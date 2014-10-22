#ifndef INSTGAME_H
#define INSTGAME_H

#include "Game.h"
#include "CPlane.h"
#include <vector>
#include "CollisionSphere.h"
#include "Vector3h.h"
#include "CollisionHandler.h"
#include "Rigidbody.h"
using namespace std;

class instGame : public Game
{
public:
	vector<CollisionSphere*> *list;
	CollisionHandler collisionhandle;
	CPlane plain;
	
public:
	instGame();
	~instGame();
	void initialize();
	void CollisionDetection();
	virtual void UpdateObjects( float dt );
    virtual void Render();
	
};

#endif // INSTGAME_H
