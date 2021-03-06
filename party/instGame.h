#ifndef INSTGAME_H
#define INSTGAME_H

#include "Game.h"
#include "CPlane.h"
#include <vector>
#include "CollisionSphere.h"
#include "Vector3h.h"
#include "CollisionHandler.h"
#include "CollisionObject.h"
#include "CollisionPlane.h"
#include "Rigidbody.h"
using namespace std;

class instGame : public Game
{
public:
	vector<CollisionObject*> *list;
	
	CollisionHandler collisionhandle;
	CollisionPlane plain;
	
public:
	instGame();
	~instGame();
	void init();
	void CollisionDetection();
	void CollisionResponse(float dt);
	virtual void UpdateObjects( float dt );
    virtual void Render();
	
};

#endif // INSTGAME_H
