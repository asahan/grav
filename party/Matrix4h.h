#ifndef MATRIX4H_H
#define MATRIX4H_H
#include <gl/glut.h>
#include "Vector4h.h"
#include "Matrix3h.h"
class Matrix4h
{
public:
	GLfloat index[16];
public:
	Matrix4h(GLfloat a[16]);
	Matrix4h(GLfloat a[4][4]);
	Matrix4h();
	~Matrix4h();
	friend Matrix4h Transpose(const Matrix4h& a);
	void Set(const Matrix3h a);
	void SetRow(unsigned int i,const Vector4h& a);
	void SetCuloumn(unsigned int i,const Vector4h& a);
	
	void Identity();
	
	void operator=(const Matrix4h& a);
	Vector4h operator*(const Vector4h& a);
	Matrix4h operator*(const Matrix4h& a);
	Matrix4h operator+(const Matrix4h& a);
	void operator+=(const Matrix4h& a);
	Matrix4h operator-(const Matrix4h& a);
	void operator-=(const Matrix4h& a);
	
	

};


#endif // MATRIX4H_H
