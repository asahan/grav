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
	CollisionCube(Vector3h min, Vector3h max);
	
	void SetColorFace(int i,float r,float g,float b);
	void operator=(const CollisionCube& temp );
	void operator=(const CollisionCube* temp);
	bool HandleCollision(CollisionCube* other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint);
	void Applyimpulse();
	virtual void Update(float dt);
	virtual void Render();

};

#endif // COLLISIONCUBE_H
