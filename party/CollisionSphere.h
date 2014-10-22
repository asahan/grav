#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H
#include "CSphere.h"
#include "BoundingSphere.h"
#include "Rigidbody.h"
#include "Vector3h.h"


class CollisionSphere : public Rigidbody
{
public:
	CSphere Sphere;
	BoundingSphere Bounding;
public:
	CollisionSphere();
	~CollisionSphere();
	CollisionSphere(const CSphere& sphere);
	CollisionSphere(Vector3h mCenter, float mRedius);
	void operator=(const CollisionSphere& temp );
	
	virtual void Render();
};

#endif // COLLISIONSPHERE_H
