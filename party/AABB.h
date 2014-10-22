#ifndef AABB_H
#define AABB_H
#include "Vector3h.h"
#include "BoundingSphere.h"
class AABB
{
	Vector3h mMin;
	Vector3h mMax;
	
public:
	AABB();
	AABB(Vector3h mMin,Vector3h mMax);
	~AABB();
	
	void Set(const Vector3h& Min,const Vector3h& Max);
	void Set( const Vector3h* points, unsigned int numPoints );
	bool Contain(Vector3h point) const;
	bool Intersect( const AABB& other ) const;
	Vector3h ClosestPoint(const BoundingSphere& other) const;
	bool ComputeCollision( const BoundingSphere& other,Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint) const;
	

};

#endif // AABB_H
