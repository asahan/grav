#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H

#include "CSphere.h"
#include "BoundingSphere.h"
#include "CollisionCube.h"
#include "CollisionObject.h"
#include "Rigidbody.h"
#include "Vector3h.h"


class CollisionSphere : public CollisionObject
{
public:
	CSphere sphere;
	BoundingSphere Bounding;
public:
	CollisionSphere();
	~CollisionSphere();
	CollisionSphere(Vector3h mCenter, float mRedius,float mass);
	inline void SetColor(float r,float g,float b) { sphere.SetColor(r,g,b); };
	void operator=(const CollisionSphere& temp );
	void operator=(const CollisionSphere* temp);
	virtual bool ProcessColliding(CollisionObject* b,Vector3h& CollisionNormal, float& penetration,Vector3h* CollisionPoint,int& numHit);
	void Applyimpulse();
	virtual void Update(float dt);
	virtual void Render();
};

#endif // COLLISIONSPHERE_H
