#ifndef CSPHERE_H
#define CSPHERE_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/glut.h"
class CSphere : public CShape
{
public:
	float Color[3];
	Vector3h pos;
	float mRedius;
public:
	CSphere();
	~CSphere();
	
	void SetColor(float r,float g,float b);
	inline void Set(Vector3h pos){this->pos = pos; }
	inline void Set(float mRedius){ this->mRedius = mRedius; }
	void Render();
	
	

};

#endif // CSPHERE_H
