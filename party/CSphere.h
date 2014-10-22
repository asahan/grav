#ifndef CSPHERE_H
#define CSPHERE_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/glut.h"
class CSphere : public CShape
{
public :
	Vector3h mCenter;
	float mRedius;

public:
	CSphere();
	CSphere(Vector3h mCenter,float mRedius);
	~CSphere();
	void Set(const CSphere& sphere);
	void Set(Vector3h mCenter,float mRedius);
	virtual void Render();
	
	

};

#endif // CSPHERE_H
