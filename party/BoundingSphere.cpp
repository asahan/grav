#include "BoundingSphere.h"

BoundingSphere::BoundingSphere()
{
}
BoundingSphere::BoundingSphere(const Vector3h& mCenter,float mRedius):mCenter(mCenter),mRedius(mRedius){};
BoundingSphere::BoundingSphere(const BoundingSphere& sphere)
{
	Set(sphere);
}
BoundingSphere::~BoundingSphere()
{
}
void BoundingSphere::Set(const BoundingSphere& sphere)
{
	mCenter=sphere.mCenter;
	mRedius=sphere.mRedius;
}
void BoundingSphere::Set(const Vector3h& mCenter,const float& mReidus)
{
	this->mCenter = mCenter;
	mRedius = mReidus;
	
}
bool BoundingSphere::Intersect( const BoundingSphere& other ) 
{
	Vector3h CollisionNormal = other.mCenter - mCenter;
	float distance = mRedius + other.mRedius;
	distance*=distance;
	return (CollisionNormal.magnitude() <= distance) ? true : false;
}
bool BoundingSphere::ComputeCollision( const BoundingSphere& other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint) const
{
	CollisionNormal = other.mCenter - mCenter;
	float distance = mRedius + other.mRedius;
	float distancelq = CollisionNormal.Size();
	if( distancelq <= distance)
	{
		penetration = distance - distancelq;
		CollisionNormal.normalize();
		CollisionPoint= (mCenter+CollisionNormal*mRedius)*0.5 + (other.mCenter+CollisionNormal*other.mRedius)*0.5;
		return true;
	}

	return false;
}
