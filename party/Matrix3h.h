#ifndef MATRIX3H_H
#define MATRIX3H_H
#include <gl/glut.h>
#include "Vector3h.h"
class Matrix3h
{
public:
	GLfloat index[9];
public:
	Matrix3h();
	Matrix3h(GLfloat a[9]);
	Matrix3h(GLfloat a[3][3]);
	~Matrix3h();
	
	void Identity();
	Matrix3h Inverse();
	friend Matrix3h Transpose(const Matrix3h& a);
	void operator=(const Matrix3h& a);
	Vector3h operator*(const Vector3h& a);
	Matrix3h operator*(const Matrix3h& a);
	Matrix3h operator+(const Matrix3h& a);
	void operator+=(const Matrix3h& a);
	Matrix3h operator-(const Matrix3h& a);
	void operator-=(const Matrix3h& a);
	
	

};

#endif // MATRIX3H_H
