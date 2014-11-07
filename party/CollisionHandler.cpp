#include "CollisionHandler.h"

#define max(a,b)	a>b?a:b
CollisionHandler::CollisionHandler()
{

	this->Collisions = new std::vector<CollisionPoint*>;
}

CollisionHandler::~CollisionHandler()
{
}

void CollisionHandler::Clear()
{
	std::vector<CollisionPoint*>::iterator it0=Collisions->begin();
	for(;it0!=Collisions->end();it0++)
	{
		CollisionPoint* remove=*it0;
		remove->Sphere0 = NULL;
		remove->Sphere1 = NULL;
		remove->contact.clear();
		delete (remove);
	}
	
	
	Collisions->clear();
	
}
void CollisionHandler::AddCollision(Rigidbody *sp0 , Rigidbody *sp1, Vector3h point,float penetration,Vector3h normal)
{
	bool sameCollision=false;
	std::vector<CollisionPoint*>::iterator it=Collisions->begin();
	for(;it!=Collisions->end();it++)
	{
		if((*it)->Sphere0 == sp0 && (*it)->Sphere1 == sp0)
		{
			sameCollision=true;
			Contact temp={point,normal,penetration};
			(*it)->contact.push_back(temp);
			break;
		}
	}
	if(!sameCollision)
	{
		CollisionPoint* nCollision = new CollisionPoint();
		nCollision->Sphere0 = sp0;
		nCollision->Sphere1 = sp1;
		Contact intemp={point,normal,penetration};
		nCollision->contact.push_back(intemp);
		Collisions->push_back(nCollision);
	}
}
void CollisionHandler::Response(float dt)
{
	std::vector<CollisionPoint*>::iterator it0=Collisions->begin();
	for(;it0!=Collisions->end();it0++)
	{
		Rigidbody* temp0=(*it0)->Sphere0;
		Rigidbody* temp1=(*it0)->Sphere1;
		
		std::vector<Contact>::iterator it = (*it0)->contact.begin();
		for(;it!=(*it0)->contact.end();it++)
		{
			
				Vector3h Normal = it->Normal;
				Vector3h vel0=temp0->GetVelocity();
				Vector3h vel1;
				if(temp1 != NULL)
					vel1=temp1->GetVelocity();
			
				Vector3h r0 = it->Contactpoint - temp0->GetPosition();
				Vector3h r1;
				if(temp1 != NULL)
					r1 = it->Contactpoint - temp1->GetPosition();
			
				Vector3h w0 = temp0->GetAngVelocity();
				Vector3h w1;
				if(temp1 != NULL)
					w1 = temp1->GetAngVelocity();
				
				Vector3h v0 = temp0->GetVelocity() + (w0.Cross(r0));
				Vector3h v1;
				if(temp1 != NULL)
					v1 = temp1->GetVelocity() + (w1.Cross(r1));
				else
					v1 = Vector3h(0,0,0);
				
				Vector3h dv=v0 - v1;
				float vn = dv.Dot(Normal);
				const float allowedPenetration = 0.1f;
				const float biasFactor = 0.1f; 
				float biasFactorValue = biasFactor;
				float inv_dt = dt > 0.0f ? 1.0f / dt : 0.0f;
				
				float penetration = it->penetration;
				float bias = biasFactorValue * inv_dt * max(0.0f, penetration - allowedPenetration);
				
				
				float numerator = -(1.0f+(temp0->GetElastictity()))*vn;
				float invmass0;
				float invmass1=0;
				invmass0 = temp0->GetInvMass();
				if(temp1 != NULL)
					invmass1= temp1->GetInvMass();
				
				if(invmass0 + invmass1 == 0)
					break;
	
				float knormal = invmass0 + invmass1; 
				Vector3h cross0 = r0.Cross(Normal);
				cross0 = temp0->GetinverseWorldInertia()*cross0;
				
				Vector3h cross1=Vector3h(0,0,0);
				
				if(temp1 != NULL){
					cross1 = r1.Cross(Normal);
					cross1 = temp1->GetinverseWorldInertia()*cross1;
				}
				
				
				
				Vector3h sum = cross0.Cross(r0) + cross1.Cross(r1);
				knormal += sum.Dot(Normal);
				float j = numerator/knormal;
				
				 Vector3h jn = Normal * j;

				// update velocities
				vel0 += jn*invmass0;
				temp0->SetVelocity(vel0);
			
				if(temp1!= NULL){
					vel1 -= jn*invmass1;
					temp1->SetVelocity(vel1);
				}
				
				Vector3h angvel0 = temp0->GetAngVelocity();
				angvel0 += temp0->GetinverseWorldInertia()*(r0.Cross(jn));
				
				temp0->SetAngVelocity(angvel0);
				Vector3h angvel1 =Vector3h(0,0,0);
				if(temp1 != NULL){
					angvel1 = temp1->GetAngVelocity();
					angvel1-= temp1->GetinverseWorldInertia()*(r1.Cross(jn));
					temp1->SetAngVelocity(angvel1);
				
				}
				
				
				///////////////tangent
				Vector3h tangent = Vector3h(0,0,0);
				tangent = dv - ( Normal* dv.Dot(Normal));
				tangent.normalize();

				float kTangent = invmass0 + invmass1; 
				
				Vector3h Cross0 = temp0->GetinverseWorldInertia()*(r0.Cross(tangent));
				Cross0 = Cross0.Cross(r0);
				Vector3h Cross1 = Vector3h (0,0,0);
				if(temp1 != NULL){
					Cross1 = temp1->GetinverseWorldInertia()*(r1.Cross(tangent));
					Cross1 = Cross1.Cross(r1);
				}
				Vector3h SumTangent = Cross0 + Cross1;
				kTangent += SumTangent.Dot(tangent);
					

			float massTangent = 1.0f / kTangent;
			

			float vt =dv.Dot(tangent);
			float dPt = massTangent * (-vt);


			float maxPt = 0.65 * j;
			//dPt = Clamp(dPt, -maxPt, maxPt);

			float res = dPt;
			res = dPt > maxPt ? maxPt : dPt;
			res = dPt < -maxPt ? -maxPt : dPt;
			// Apply contact impulse
			Vector3h P = tangent * res ;
			
			vel0 += P*invmass0;
			temp0->SetVelocity(vel0);
			angvel0 += temp0->GetinverseWorldInertia()*(r0.Cross(P));
			temp0->SetAngVelocity(angvel0);
			
			if(temp1 != NULL){
			vel1 -= P * invmass1;
			temp1->SetVelocity(vel1);
			angvel1 -= temp1->GetinverseWorldInertia()*(r1.Cross(P)); 
			
			
			
			}
			
			
			
			
		
		}
	}
	
}

bool CollisionHandler::HandleCollision(CollisionObject* object0,CollisionObject* object1, Vector3h& CollisionNormal, float& penetration, Vector3h* CollisionPoint,int& numHit)
{
	
	if(object0->ProcessColliding(object1,CollisionNormal,penetration,CollisionPoint,numHit) )
		return true;
	else
		return false;
}