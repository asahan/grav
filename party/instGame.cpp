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
	delete [] list;
}

 void instGame::UpdateObjects( float dt )
 {
	 
	 
 }
 void instGame::Render()
 {
	 plain.Render();
 }