#ifndef CSPHERE_H
#define CSPHERE_H
#include "CShape.h"
#include "Vector3h.h"
#include "Matrix4h.h"
#include "gl/glut.h"
#include "gl/gl.h"
class CSphere : public CShape
{
public:
	float Color[3];
	Matrix4h mat;
	float mRedius;
public:
	CSphere();
	~CSphere();
	
	void SetColor(float r,float g,float b);
	inline void Set(const Matrix4h& pos){this->mat = pos; }
	inline void Set(float mRedius){ this->mRedius = mRedius; }
	void Render();
	
	

};

#endif // CSPHERE_H
