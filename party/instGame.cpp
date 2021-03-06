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
	list=new std::vector<CollisionObject*>();


	list->push_back(new CollisionSphere(Vector3h(2,2,2),1,5));
	list->push_back(new CollisionSphere(Vector3h(4,4,4),1,8));
	list->push_back(new CollisionSphere(Vector3h(3,6,6),1,4));
	list->push_back(new CollisionSphere(Vector3h(1,3,10),1,3));
	list->push_back(new CollisionSphere(Vector3h(5,4,9),1,3));
	//list->push_back(new CollisionCube(Vector3h(9,8,10),Vector3h(0,80,0),Vector3h(1,1,1),6));
	list->push_back(new CollisionCube(Vector3h(9,8,5),Vector3h(0,0,0),Vector3h(1,1,1),6));
	list->push_back(new CollisionCube(Vector3h(5,4,10),Vector3h(0,50,50),Vector3h(1,1,1),5));
	//list->push_back(new CollisionCube(Vector3h(8,6,10),Vector3h(0,50,0),Vector3h(1,1,1),5));
	
	float Color[12]={0.5,0.3,0,0.5,0.5,0.3,0.7,0.2,0.5,0.6,0.1,0.9};
	vector<CollisionObject*>::iterator it;
	int index=0;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->SetAccelation(Vector3h(0,0,-9.8));
		(*it)->SetElasticity(0.8);
		
		if((*it)->baseShape == Shape_Sphere){
			((CollisionSphere*)(*it))->SetColor(Color[index],Color[index+1],Color[index+2]);
			index+=3;

		}
	}
	
}

instGame::~instGame()
{
	vector<CollisionObject*>::iterator it;
	for(it=list->begin();it!=list->end();it++)
	{
		Rigidbody * temp=*it;
		delete(temp);
	}
	delete [] list;
}

void instGame::UpdateObjects( float dt )
{
	collisionhandle.Clear();
	CollisionDetection();
	CollisionResponse(dt);
	vector<CollisionObject*>::iterator it;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->Update(dt);
	}
	 
}
void instGame::Render()
{
	plain.Render();
	vector<CollisionObject*>::iterator it;
	for(it=list->begin();it!=list->end();it++)
	{
		(*it)->Render();
	}
}
void instGame::CollisionDetection()
{
	vector<CollisionObject*>::iterator first;
	for(first=list->begin();first!=list->end();first++)
	{
		Vector3h collnormal;
		Vector3h collpoint[8];
		float pen; bool intersect;
		int count;
		if((*first)->baseShape == Shape_Cube)
			intersect=plain.HandleCollision((CollisionCube *)(*first),collnormal,collpoint,count);
		else
			intersect=plain.HandleCollision((CollisionSphere *)(*first),collnormal,collpoint,count);
	
		if(intersect)
		{
			for(int i=0;i<count;i++)
				collisionhandle.AddCollision((*first),NULL,collpoint[i],pen,collnormal);
		}
	}
	vector<CollisionObject*>::iterator second;
	for(first=list->begin();first!=list->end();first++)
	{
		for(second=first;second!=list->end();second++)
			if(second != first)
			{
				Vector3h collnormal;Vector3h collpoint[50]; 
				int numhit;
				float pen;
				bool intersect;
				intersect = collisionhandle.HandleCollision(*first, *second ,collnormal,pen,collpoint,numhit);
			
				if(intersect)
				{
					for(int i = 0; i < numhit; i++ )
					collisionhandle.AddCollision((*first),(*second),collpoint[i],pen,collnormal);
					
				}
			}
			
					
	}
	 
}
void instGame::CollisionResponse(float dt)
{
	collisionhandle.Response(dt);
}