#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#include "Rigidbody.h"

#define Cube 0x00000001
#define Sphere 0x00000002

class CollisionObject : public Rigidbody
{
private:
	unsigned int Shape;
public:
	CollisionObject();
	~CollisionObject();
	inline void SetShape(unsigned int i){Shape = i;}
	inline unsigned int GetShape(){ return Shape; }
	virtual bool ProcessColliding(CollisionObject* b,Vector3h& CollisionNormal, float& penetration,Vector3h* CollisionPoint,int& numHit) = 0;

};

#endif // COLLISIONOBJECT_H
