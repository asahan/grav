#ifndef CSPHERE_H
#define CSPHERE_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/glut.h"
class CSphere : public CShape
{
public:
	float Color[3];

public:
	CSphere();
	~CSphere();
	
	void SetColor(float r,float g,float b);
	void Render(Vector3h pos,float mReidus);
	
	

};

#endif // CSPHERE_H
