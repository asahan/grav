#ifndef COLLISIONPLANE_H
#define COLLISIONPLANE_H
#include "CPlane.h"
#include "Vector3h.h"
#include "AABB.h"
#include "CollisionSphere.h"
#include "CollisionCube.h"
class CollisionPlane : public Rigidbody
{
public:
	Vector3h Center;
	Vector3h normal;
	Vector3h vertex[8];
	CPlane plain;
	AABB box;
public:
	CollisionPlane();
	~CollisionPlane();
	bool HandleCollision(CollisionSphere* other, Vector3h& CollisionNormal, Vector3h& CollisionPoint);
	bool HandleCollision(CollisionCube* other, Vector3h& CollisionNormal,  Vector3h& CollisionPoint);
	virtual void Render();

};

#endif // COLLISIONPLANE_H
