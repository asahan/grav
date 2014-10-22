#ifndef VECTOR3H_H
#define VECTOR3H_H

#include <gl/glut.h>
class Vector3h
{
public:
	GLfloat x,y,z;
public:
	Vector3h(float x,float y,float z);
	Vector3h(const Vector3h& cre);
	Vector3h();
	~Vector3h();
	void setVector3h(float x,float y,float z);
	void setVector3h(Vector3h& temp);
	void Clean();
	
	
	Vector3h getVector3h();
	float magnitude();
	float Size();
	void normalize();
	Vector3h Cross(const Vector3h& a);
	
	void operator+=(const Vector3h& a);
	Vector3h operator+(const Vector3h& a) const;
	void operator-=(const Vector3h& a);
	Vector3h operator-(const Vector3h& a) const;
	void operator*=(const GLfloat a);
	Vector3h operator*(const GLfloat a);
	float operator*(const Vector3h& a);
	Vector3h operator%(const Vector3h& a);
	void operator=(const Vector3h& a);
	
	

};

#endif // VECTOR3H_H
