#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H
#include "Vector3h.h"
#include "CSphere.h"
class BoundingSphere
{
public:
	Vector3h mCenter;
	float mRedius;
	
public:
	BoundingSphere();
	BoundingSphere(const Vector3h& mCenter,float mRedius);
	BoundingSphere(const BoundingSphere& sphere);
	~BoundingSphere();
	void Set(const Vector3h& mCenter,const float& mReidus);
	void Set(const BoundingSphere& sphere);
	inline void SetRedius(float redius) { mRedius = redius; }; 
	inline void SetCenter(Vector3h center){mCenter = center;};
	bool Intersect( const BoundingSphere& other );
	bool ComputeCollision( const BoundingSphere& other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollistionPoint) const;
	

};

#endif // BOUNDINGSPHERE_H
