#ifndef CRECT_H
#define CRECT_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/gl.h"
class CRect : public CShape
{

public:
	CRect();
	~CRect();
	virtual void Render(Vector3h min,Vector3h max);

};

#endif // CRECT_H
