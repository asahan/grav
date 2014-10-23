#ifndef CRECT_H
#define CRECT_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/gl.h"
class CCube : public CShape
{
	float Color[3];
public:
	CCube();
	~CCube();
	virtual void Render(Vector3h min,Vector3h max);

};

#endif // CRECT_H
