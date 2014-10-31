#ifndef COLLISIONCUBE_H
#define COLLISIONCUBE_H

#include "OBB.h"
#include "Rigidbody.h"
#include "CollisionSphere.h"
#include "CCube.h"
#include "Quath.h"
#include "Matrix4h.h"
#include "Vector4h.h"


class CollisionCube : public Rigidbody
{
	public:
	CCube cube;
	OBB Bounding;

public:
	CollisionCube();
	~CollisionCube();
	CollisionCube(Vector3h pos, Vector3h rotation,Vector3h Extent,float mass);
	
	
	void SetColorFace(int i,float r,float g,float b);
	void operator=(const CollisionCube& temp );
	void operator=(const CollisionCube* temp);
	

	
	void Applyimpulse();
	virtual void Update(float dt);
	virtual void Render();

};

#endif // COLLISIONCUBE_H
