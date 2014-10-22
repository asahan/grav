#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
	this->Collisions = new std::vector<CollisionPoints*>;
}

CollisionHandler::~CollisionHandler()
{
}

void CollisionHandler::Clear()
{
	std::vector<CollisionPoints*>::iterator it=Collisions->begin();
	for(;it!=Collisions->end();it++)
	{
		CollisionPoints* remove=*it;
		remove->Sphere0 = NULL;
		remove->Sphere1 = NULL;
		remove->contacts.clear();
		delete (remove);
	}
	Collisions->clear();
	
}
void CollisionHandler::AddCollision(CollisionSphere *sp0,CollisionSphere *sp1, Vector3h point,float penetration,Vector3h normal)
{
	bool sameCollision=false;
	std::vector<CollisionPoints*>::iterator it=Collisions->begin();
	for(;it!=Collisions->end();it++)
	{
		if((*it)->Sphere0 == sp0 && (*it)->Sphere1 == sp0)
		{
			sameCollision=true;
			Contact temp={sp0->Translate,sp1->Translate,point,normal,penetration};
			(*it)->contacts.push_back(temp);
			break;
		}
	}
	if(!sameCollision)
	{
		CollisionPoints* nCollision = new CollisionPoints();
		nCollision->Sphere0 = sp0;
		nCollision->Sphere1 = sp1;
		Contact intemp={sp0->Translate,sp1->Translate,point,normal,penetration};
		nCollision->contacts.push_back(intemp);
		Collisions->push_back(nCollision);
		
	}
	
	
}