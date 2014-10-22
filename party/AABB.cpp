#include "AABB.h"

AABB::AABB(){
	mMin=Vector3h(0,0,0);
	mMax=Vector3h(0,0,0);
	};
AABB::AABB(Vector3h mMin,Vector3h mMax):mMin(mMin),mMax(mMax){};
AABB::~AABB()
{
}
void AABB::Set(const Vector3h& Min,const Vector3h& Max)
{
	mMin=Min;
	mMax=Max;
}
void AABB::Set( const Vector3h* points, unsigned int numPoints )
{
	mMin=points[0];
	mMax=points[0];
	for(unsigned int i=1;i<numPoints;i++)
	{
		if(points[i].x < mMin.x)
			mMin.x=points[i].x;
		else if(points[i].x > mMax.x)
			mMax.x=points[i].x;
		if(points[i].y < mMin.y)
			mMin.y=points[i].y;
		else if(points[i].y > mMax.y)
			mMax.y=points[i].y;
		if(points[i].z < mMin.z)
			mMin.z=points[i].z;
		else if(points[i].z > mMax.z)
			mMax.z=points[i].z;
	}
	
	
}
bool AABB::Intersect( const AABB& other ) const
{
    
    if (mMin.x > other.mMax.x || other.mMin.x > mMax.x )
        return false;

  
    if (mMin.y > other.mMax.y || other.mMin.y > mMax.y )
        return false;

   
    if (mMin.z > other.mMax.z || other.mMin.z > mMax.z )
        return false;

   
    return true;
}
bool AABB::Contain( Vector3h point) const
{
	if(point.x < mMin.x || point.x > mMax.x )
		return false;
	else if(point.y < mMin.y || point.y > mMax.y)
		return false;
	else if(point.z < mMin.z || point.z > mMax.z)
		return false;
	else
		return true;
}
Vector3h AABB::ClosestPoint(const BoundingSphere& other) const
{
	Vector3h center=other.mCenter;
	Vector3h ret;
	if(mMin.x > center.x)
		ret.x = mMin.x;
	else if(mMax.x < center.x)
		ret.x = mMax.x;
	else
		ret.x = center.x;
	
	if(mMin.y > center.y)
		ret.y = mMin.y;
	else if(mMax.y < center.y)
		ret.y = mMax.y;
	else
		ret.y = center.y;
		
	if(mMin.z > center.z)
		ret.z = mMin.z;
	if(mMax.z < center.z)
		ret.z = mMax.z;
	else
		ret.z = center.z;
	
	return ret;
}
bool AABB::ComputeCollision( const BoundingSphere& other,Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint) const
{
	Vector3h circle=other.mCenter;
	if(Contain(circle))
	{
		CollisionPoint = Vector3h(0,0,0);
		penetration = 0;
		CollisionNormal = Vector3h(0,0,0);
		return true;
	}
	
	CollisionPoint=ClosestPoint(other);
	
	CollisionNormal = other.mCenter - CollisionPoint;
	float redius = other.mRedius;
	float diff = CollisionNormal.magnitude();
	
	if(diff > (redius*redius))
		return false;
	else
	{
		penetration = redius - CollisionNormal.Size();
		CollisionNormal.normalize();
	}
		return true;
}
