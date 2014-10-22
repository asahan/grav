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
	
	list->push_back(new CollisionSphere(Vector3h(2,2,2),1));
	
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
	vector<CollisionSphere*>::iterator it;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->Update(dt);
	}
	 
}
void instGame::Render()
{
	plain.Render();
	vector<CollisionSphere*>::iterator it;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->Render();
	}
}
void instGame::CollisionDetection()
{
	vector<CollisionSphere*>::iterator first;
	vector<CollisionSphere*>::iterator second;
	for(first=list->begin();first!=list->end();first++)
	{
		for(second=first;second!=list->end();second++)
		{
			if(second != first)
			{
				Vector3h collnormal,collpoint;
				float pen;
				if(((*first)->Bounding.ComputeCollision((*second)->Bounding,collnormal,pen,collpoint)) == true)
				{
					collisionhandle.AddCollision((*first),(*second),collpoint,pen,collnormal);
					Vector3h firstpos=(*first)->GetPosition();
					firstpos-=collnormal*0.5*pen;
					(*first)->SetPosition(firstpos);
					Vector3h secondpos=(*second)->GetPosition();
					secondpos+=collnormal*0.5*pen;
					(*second)->SetPosition(secondpos);
				}
			}
			
					
		}
	}
	 
}