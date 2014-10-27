#ifndef OBB_H
#define OBB_H
#include "Vector3h.h"
#include "Matrix3h.h"
#include "BoundingSphere.h"
class OBB
{
	Vector3h Center;
	Vector3h Axis[3];
	float Extent[3];
	
public:
	OBB();
	OBB(const Vector3h Center,const Vector3h Axis[3],const float Extent[3]);
	OBB(const Vector3h Center,const Vector3h axis[3]);
	OBB(const OBB& other);
	~OBB();
	
	bool SpanIntersect(OBB& a,Vector3h axis,float& penentration,Vector3h& minaxis);
	bool Intersect(OBB& other,float& minpen,Vector3h& axis);
	bool Intersect(BoundingSphere& other);
	Vector3h GetVertex(int i);
	int GetNumHitPoints(const Vector3h& normal,const float& penetration,Vector3h* vertex,int* vertindex);
	bool ComputeCollision( OBB& other, Vector3h& CollisionNormal, float& penetration, Vector3h* CollisionPoint,int& numhitpoint) ;
};

#endif // OBB_H
