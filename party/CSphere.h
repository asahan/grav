#ifndef CSPHERE_H
#define CSPHERE_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/glut.h"
class CSphere : public CShape
{


public:
	CSphere();
	~CSphere();
	
	void Render(Vector3h pos,float mReidus);
	
	

};

#endif // CSPHERE_H
