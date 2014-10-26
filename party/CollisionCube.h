#ifndef COLLISIONCUBE_H
#define COLLISIONCUBE_H
#include "OBB.h"
#include "Rigidbody.h"
#include "CCube.h"

class CollisionCube : public Rigidbody
{
	CCube cube;
	OBB obb;
public:
	CollisionCube();
	~CollisionCube();

};

#endif // COLLISIONCUBE_H
