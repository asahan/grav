#include "instGame.h"

using namespace std;
bool Game::Create()
{
	Game::mGame=new instGame();
	if(Game::mGame!=0)
		return true;
	else
		return false;
}


instGame::instGame()
{
	list=new std::vector<CollisionSphere*>();
	list1=new std::vector<CollisionCube*>();
	list->push_back(new CollisionSphere(Vector3h(2,2,2),1));
	list->push_back(new CollisionSphere(Vector3h(4,4,4),1));
	list->push_back(new CollisionSphere(Vector3h(3,6,6),1));
	list->push_back(new CollisionSphere(Vector3h(1,3,10),1));
	list1->push_back(new CollisionCube(Vector3h(1,1,10),Vector3h(0,0,30),Vector3h(1,1,1),6));
	float Color[12]={0.5,0.3,0,0.5,0.5,0.3,0.7,0.2,0.5,0.6,0.1,0.9};
	vector<CollisionSphere*>::iterator it;
	vector<CollisionCube*>::iterator it1;
	int index=0;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->SetAccelation(Vector3h(0,0,-9.8));
		(*it)->SetElasticity(0.5);
		(*it)->SetMass(5.);
		(*it)->SetColor(Color[index],Color[index+1],Color[index+2]);
		index+=3;
	}
	for(it1=list1->begin();it1!=list1->end();it1++)
	{
		(*it1)->SetAccelation(Vector3h(0,0,-9.8));
		(*it1)->SetElasticity(0.5);
		
		
	}
	
}

instGame::~instGame()
{
	vector<CollisionSphere*>::iterator it;
	for(it=list->begin();it!=list->end();it++)
	{
		CollisionSphere * temp=*it;
		delete(temp);
	}
	delete [] list;
}

void instGame::UpdateObjects( float dt )
{
	collisionhandle.Clear();
	CollisionDetection();
	CollisionResponse();
	vector<CollisionSphere*>::iterator it;
	vector<CollisionCube*>::iterator it1;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->Update(dt);
	}
	for(it1=list1->begin();it1!=list1->end();it1++)
	{
		(*it1)->Update(dt);
	}
	 
}
void instGame::Render()
{
	plain.Render();
	vector<CollisionSphere*>::iterator it;
	vector<CollisionCube*>::iterator it1;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->Render();
	}
	for(it1=list1->begin();it1!=list1->end();it1++)
	{
		(*it1)->Render();
	}
}
void instGame::CollisionDetection()
{
	vector<CollisionSphere*>::iterator first;
	for(first=list->begin();first!=list->end();first++)
	{
		Vector3h collnormal,collpoint;
		float pen;
		if(plain.HandleCollision((*first),collnormal,pen,collpoint) == true)
		{
			collisionhandle.AddCollision((*first),collpoint,pen,collnormal);
		}
	}
	vector<CollisionSphere*>::iterator second;
	for(first=list->begin();first!=list->end();first++)
	{
		for(second=first;second!=list->end();second++)
			if(second != first)
			{
				Vector3h collnormal,collpoint;
				float pen;
				if(((*first)->HandleCollision((*second),collnormal,pen,collpoint)) == true)
				{
					collisionhandle.AddCollision((*first),(*second),collpoint,pen,collnormal);
					
				}
			}
			
					
	}
	 
}
void instGame::CollisionResponse()
{
	collisionhandle.Response();
}