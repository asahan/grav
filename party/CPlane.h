#ifndef CPLANE_H
#define CPLANE_H
#include "CShape.h"
#include "Vector3h.h"
#include "Matrix4h.h"
#include "AABB.h"

class CPlane : public CShape
{
public:
	Vector3h Center;
	Vector3h normal;
	Vector3h vertex[8];
	AABB box;
public:
	CPlane();
	~CPlane();
	virtual void Render();

};

#endif // CPLANE_H
