#ifndef CRECT_H
#define CRECT_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/gl.h"
class CRect : public CShape
{
public:
	Vector3h min;
	Vector3h max;


public:
	CRect();
	CRect(Vector3h min,Vector3h max);
	~CRect();
	virtual void Render();

};

#endif // CRECT_H
