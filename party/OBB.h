#ifndef OBB_H
#define OBB_H
#include "Vector3h.h"
#include "Vector4h.h"
#include "Matrix3h.h"
#include "Matrix4h.h"
#include "BoundingSphere.h"
#include "AABB.h"
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
	
	void SetCenter(const Vector3h& pos);
	void SetAxis(const Vector3h& Axisx,const Vector3h& Axisy,const Vector3h& Axisz);
	void SetExtent(const Vector3h& Extent);
	inline Vector3h GetCenter()const {  return Center; }
	inline Vector3h GetAxis(int i)const { return Axis[i]; }
	inline float GetExtent(int i)const { return Extent[i]; } 
	bool SpanIntersect(OBB& a,Vector3h axis,float& penentration,Vector3h& minaxis);
	bool Intersect(OBB& other,float& minpen,Vector3h& axis);
	bool Intersect(BoundingSphere& other);
	Vector3h GetVertex(int i);
	int GetNumHitPoints(const Vector3h& normal,const float& penetration,Vector3h* vertex,int* vertindex);
	void ClipLinePlane(const Vector3h& point, Vector3h& collisionpoint);
	bool ComputeCollision( OBB& other, Vector3h& CollisionNormal, float& penetration, Vector3h* CollisionPoint,int& numhitpoint) ;
	bool ComputeCollision( BoundingSphere& other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint);
};

#endif // OBB_H
