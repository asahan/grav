#ifndef QUAT_H
#define QUAT_H
#include "Vector3h.h"
#include "Matrix3h.h"
class Quath
{
	float w,x,y,z;
public:
	Quath();
	Quath(float w,float x,float y,float z);
	~Quath();
	void Set(float w,float x,float y,float z);
	void Set(const Vector3h axis,float angle);
	float Magnitude();
	float Size();
	void Normalize();
	float Dot(const Quath& quat);
	Quath Conjugate();
	
	void ToRatationMatrix(Matrix3h& rot);
	
	Quath operator+(const Quath& quat);
	void operator+=(const Quath& quat);

};

#endif // QUAT_H
