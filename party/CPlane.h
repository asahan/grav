#ifndef CPLANE_H
#define CPLANE_H
#include "CShape.h"
#include "Vector3h.h"
#include "Matrix4h.h"
#include "AABB.h"

class CPlane : public CShape
{


public:
	CPlane();
	~CPlane();
	virtual void Render(Vector3h vertex[4]);

};

#endif // CPLANE_H
