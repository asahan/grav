#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
	this->Coll=new std::vector<CollisionSpherePlane*>;
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
		delete (remove);
	}
	std::vector<CollisionSpherePlane*>::iterator it1=Coll->begin();
	for(;it1!=Coll->end();it1++)
	{
		CollisionSpherePlane* remove=*it1;
		remove->Sphere0 = NULL;
		delete (remove);
	}
	Collisions->clear();
	Coll->clear();
}
void CollisionHandler::AddCollision(CollisionSphere *sp0,CollisionSphere *sp1, Vector3h point,float penetration,Vector3h normal)
{
	//bool sameCollision=false;
	//std::vector<CollisionPoints*>::iterator it=Collisions->begin();
	//for(;it!=Collisions->end();it++)
	//{
		//if((*it)->Sphere0 == sp0 && (*it)->Sphere1 == sp0)
		//{
			//sameCollision=true;
			//Contact temp={sp0->Translate,sp1->Translate,point,normal,penetration};
			//(*it)->contacts.push_back(temp);
			//break;
		//}
	//}
	//if(!sameCollision)
	//{
		CollisionPoint* nCollision = new CollisionPoint();
		nCollision->Sphere0 = sp0;
		nCollision->Sphere1 = sp1;
		Contact intemp={sp0->pos,sp1->pos,point,normal,penetration};
		nCollision->contact=intemp;
		Collisions->push_back(nCollision);
	//}
}
void CollisionHandler::AddCollision(CollisionSphere *sp1,Vector3h point, float penetration,Vector3h normal)
{
	CollisionSpherePlane* nCollision = new CollisionSpherePlane();
	nCollision->Sphere0 = sp1;
	Contact intemp = {Vector3h(0,0,0),sp1->pos,point,normal,penetration};
	nCollision->contact = intemp;
	this->Coll->push_back(nCollision);
}
void CollisionHandler::Response()
{
	std::vector<CollisionPoint*>::iterator it0=Collisions->begin();
	for(;it0!=Collisions->end();it0++)
	{
	
		CollisionSphere* temp0;
		CollisionSphere* temp1;
		Vector3h Normal = (*it0)->contact.Normal;
		temp0=(*it0)->Sphere0;
		temp1=(*it0)->Sphere1;
		Vector3h vel0=temp0->GetVelocity();
		Vector3h vel1=temp1->GetVelocity();
		Vector3h relatveVel=vel0 - vel1;
		float veldot = relatveVel*Normal;
		if (veldot < 0)
            return;
		float numerator = -(1.0f+(temp0->GetElastictity()))*veldot;
        float denomenator = (1)*(1.0f/temp0->GetMass() + 1.0f/temp1->GetMass());
        float j = numerator/denomenator;

        // update velocities
		vel0+= Normal*(j/temp0->GetMass());
		temp0->SetVelocity(vel0);
        vel1-=Normal*(j/temp1->GetMass());
		temp1->SetVelocity(vel1);
	}
	
	std::vector<CollisionSpherePlane*>::iterator it1=Coll->begin();
	for(;it1!=Coll->end();it1++)
	{
		CollisionSphere* temp0;
		temp0 = (*it1)->Sphere0;
		Vector3h Normal = (*it1)->contact.Normal;
		Vector3h vel0=temp0->GetVelocity();
		float veldot = vel0*Normal;
		float numerator = -(1.0f+(temp0->GetElastictity()))*veldot;
		float denomenator = (1)*(1.0f/temp0->GetMass());
		 float j = numerator/denomenator;
		 vel0+= Normal*(j/temp0->GetMass());
		 temp0->SetVelocity(vel0);

		
	}
	
}