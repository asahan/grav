#ifndef COLLISIONPLANE_H
#define COLLISIONPLANE_H
#include "CPlane.h"
#include "Vector3h.h"
#include "AABB.h"
#include "CollisionSphere.h"
class CollisionPlane : public Rigidbody
{
public:
	Vector3h Center;
	Vector3h normal;
	Vector3h vertex[8];
	AABB box;
	CPlane plain;
	
public:
	CollisionPlane();
	~CollisionPlane();
	bool HandleCollision(CollisionSphere* other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint);
	
	virtual void Render();

};

#endif // COLLISIONPLANE_H
