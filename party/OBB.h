#ifndef OBB_H
#define OBB_H
#include "Vector3h.h"
#include "Matrix3h.h"
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
	bool Intersect(OBB& other);
	Vector3h GetVertex(int i);

};

#endif // OBB_H
