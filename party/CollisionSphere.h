#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H
#include "CSphere.h"
#include "BoundingSphere.h"
#include "Rigidbody.h"
#include "Vector3h.h"


class CollisionSphere : public Rigidbody
{
public:
	CSphere sphere;
	BoundingSphere Bounding;
public:
	CollisionSphere();
	~CollisionSphere();
	CollisionSphere(Vector3h mCenter, float mRedius);
	inline void SetColor(float r,float g,float b) { sphere.SetColor(r,g,b); };
	void operator=(const CollisionSphere& temp );
	void operator=(const CollisionSphere* temp);
	bool HandleCollision(CollisionSphere* other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint);
	void Applyimpulse();
	
	virtual void Render();
};

#endif // COLLISIONSPHERE_H
