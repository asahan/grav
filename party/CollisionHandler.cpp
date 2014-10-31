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
			if(temp1 != NULL){
				Vector3h Normal = it->Normal;
				Vector3h vel0=temp0->GetVelocity();
				Vector3h vel1=temp1->GetVelocity();
				
				Vector3h r0 = it->Contactpoint - temp0->GetPosition();
				Vector3h r1 = it->Contactpoint - temp1->GetPosition();
				Vector3h w0 = temp0->GetAngVelocity();
				Vector3h w1 = temp1->GetAngVelocity();
				
				Vector3h v0 = temp0->GetVelocity() + (w0.Cross(r0));
				Vector3h v1 = temp1->GetVelocity() + (w1.Cross(r1));
				Vector3h relatveVel=v0 - v1;
				float knormal = relatveVel*Normal;
				const float allowedPenetration = 0.1f;
				const float biasFactor = 0.1f; 
				float biasFactorValue = biasFactor;
				float inv_dt = dt > 0.0f ? 1.0f / dt : 0.0f;
				
				float penetration = it->penetration;
				float bias = biasFactorValue * inv_dt * max(0.0f, penetration - allowedPenetration);
				
				float numerator = -(1.0f+(temp0->GetElastictity()))*knormal;
				float invmass0,invmass1;
				invmass0 = temp0->GetInvMass();
				invmass1= temp1->GetInvMass();
				if(invmass0 + invmass1 == 0)
					break;
	
				float denomenator = (invmass0 + invmass1)*(Normal*Normal);
				Vector3h cross0 = r0.Cross(Normal);
				cross0 = temp0->GetinverseWorldInertia()*cross0;
				Vector3h cross1 = r1.Cross(Normal);
				cross1 = temp1->GetinverseWorldInertia()*cross1;
				Vector3h sum = cross0.Cross(r0) + cross1.Cross(r1);
				denomenator += sum*Normal;
				float j = numerator/denomenator;
				
				 Normal *= j;

				// update velocities
				vel0+= Normal*invmass0;
				temp0->SetVelocity(vel0);
			
				vel1-=Normal*invmass1;
				temp1->SetVelocity(vel1);
				
				Vector3h angvel0 = temp0->GetAngVelocity();
				angvel0+= temp0->GetinverseWorldInertia()*(r0.Cross(Normal));
				
				temp0->SetAngVelocity(angvel0);
		
				Vector3h angvel1 = temp1->GetAngVelocity();
				angvel1-= temp1->GetinverseWorldInertia()*(r1.Cross(Normal));
				temp1->SetAngVelocity(angvel1);
			
			}
			else
			{
				Vector3h Normal = it->Normal;
				Vector3h vel0=temp0->GetVelocity();
				Vector3h vel1=Vector3h(0,0,0);
			
				Vector3h r0 = it->Contactpoint - temp0->GetPosition();
				Vector3h v0 = temp0->GetVelocity() + (temp0->GetAngVelocity().Cross(r0));
				Vector3h relatveVel=vel0 - vel1;
				float veldot = relatveVel*Normal;
			
				float numerator = -(1.0f+(temp0->GetElastictity()))*veldot;
				float invmass0,invmass1;
				invmass0 = temp0->GetInvMass();
				invmass1= 1/50;
				if(invmass0 + invmass1 == 0)
					break;
	
				
				float denomenator = (invmass0 + invmass1)*(Normal*Normal);
		
				Vector3h cross0 = r0.Cross(Normal);
				cross0 = temp0->GetinverseWorldInertia()*cross0;
				Vector3h sum = cross0.Cross(r0);
				denomenator += sum*Normal;
				float j = numerator/denomenator;
				
				 Normal *= j;

				// update velocities
				vel0+= Normal*invmass0;
				temp0->SetVelocity(vel0);
				
				Vector3h angvel0 = temp0->GetAngVelocity();
				angvel0+= temp0->GetinverseWorldInertia()*(r0.Cross(Normal));
				temp0->SetAngVelocity(angvel0);
			
			}
			
			
		
		}
	}
	
}
bool CollisionHandler::HandleCollision(CollisionSphere* sphere0,CollisionSphere* sphere1, Vector3h& CollisionNormal, float& penetration, Vector3h* CollisionPoint,int& numHit)
{
	numHit =0;
	Vector3h Collpoint;
	if(sphere0->Bounding.ComputeCollision(sphere1->Bounding,CollisionNormal,penetration,Collpoint) == true){
		numHit =1; CollisionPoint[0]=Collpoint;
		Vector3h firstpos=sphere0->GetPosition();
		firstpos-=CollisionNormal*0.5*penetration;
		sphere0->SetPosition(firstpos);
		Vector3h secondpos=sphere1->GetPosition();
		secondpos+=CollisionNormal*0.5*penetration;
		sphere1->SetPosition(secondpos);
		return true;
	}
	return false;
	
}
bool CollisionHandler::HandleCollision(CollisionCube* cube,CollisionSphere* sphere, Vector3h& CollisionNormal, float& penetration,Vector3h* CollisionPoint,int& numHit)
{
	numHit =0;
	Vector3h Collpoint;
	if(cube->Bounding.ComputeCollision(sphere->Bounding,CollisionNormal,penetration,Collpoint) == true)
	{
		numHit =1; CollisionPoint[0]=Collpoint;
		Vector3h firstpos=cube->GetPosition();
		firstpos-=CollisionNormal*0.5*penetration;
		cube->SetPosition(firstpos);
		Vector3h secondpos=sphere->GetPosition();
		secondpos+=CollisionNormal*0.5*penetration;
		sphere->SetPosition(secondpos);
		return true;
	}
	return false;
}
bool CollisionHandler::HandleCollision(CollisionCube* cube0,CollisionCube* cube1, Vector3h& CollisionNormal, float& penetration, Vector3h* CollisionPoint,int& numHit)
{
	if(cube0->Bounding.ComputeCollision(cube1->Bounding,CollisionNormal,penetration,CollisionPoint,numHit) == true)
		return true;
		
	else
		return false;
	
}