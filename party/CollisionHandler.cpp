#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
	this->Collisions = new std::vector<CollisionPoint*>;
}

CollisionHandler::~CollisionHandler()
{
}

void CollisionHandler::Clear()
{
	std::vector<CollisionPoint*>::iterator it=Collisions->begin();
	for(;it!=Collisions->end();it++)
	{
		CollisionPoint* remove=*it;
		remove->Sphere0 = NULL;
		remove->Sphere1 = NULL;
		delete (remove);
	}
	Collisions->clear();
	
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
		Contact intemp={sp0->Translate,sp1->Translate,point,normal,penetration};
		nCollision->contact=intemp;
		Collisions->push_back(nCollision);
	//}
}