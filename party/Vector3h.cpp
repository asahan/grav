#include "Vector3h.h"
#include "math.h"
Vector3h::Vector3h(float x,float y,float z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}
Vector3h::Vector3h(const Vector3h& cre)
{
	this->x=cre.x;
	this->y=cre.y;
	this->z=cre.z;
	
}
Vector3h::Vector3h()
{
	x=y=z=0;
}
Vector3h::~Vector3h()
{
}

void Vector3h::setVector3h(float x,float y,float z)
{
		this->x=x;this->y=y;this->z=z;
}
void Vector3h::setVector3h(Vector3h& temp)
{
	this->x=temp.x;
	this->y=temp.y;
	this->z=temp.z;
}
float Vector3h::magnitude()
{
	return x*x+y*y+z*z;
}
float Vector3h::Size()
{
	return sqrtf(magnitude());
}
Vector3h Vector3h::getVector3h()
{
	return *this;
}
void Vector3h::normalize()
{
	float size=Size();
	if(size==0)
	{
		x=y=z=0; return;
	}
	float inverse=1/size;
	
	x=x*inverse;
	y=y*inverse;
	z=z*inverse;
}
void Vector3h::Clean()
{
	x=y=z=0;
}

Vector3h Vector3h::Cross(const Vector3h& a)
{
	Vector3h b(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
	return b;
}
float Vector3h::Dot(const Vector3h a)
{
	return x*a.x+y*a.y+z*a.z;
}
void Vector3h::operator+=(const Vector3h& a)
{
	x+=a.x,y+=a.y,z+=a.z;
}
Vector3h Vector3h::operator+(const Vector3h& a) const
{
	Vector3h result(x+a.x,y+a.y,z+a.z);
	return result;
}
void Vector3h::operator-=(const Vector3h& a)
{
	x-=a.x,y-=a.y,z-=a.z;
}
Vector3h Vector3h::operator-(const Vector3h& a) const
{
	Vector3h result(x-a.x,y-a.y,z-a.z);
	return result;
}
void Vector3h::operator*=(const GLfloat a)
{
	x*=a,y*=a,z*=a;
}

Vector3h Vector3h::operator*(const GLfloat a)
{
	Vector3h result(x*a, y*a, z*a);
	return result;
}
float Vector3h::operator*(const Vector3h& a)
{
	return x*a.x+y*a.y+z*a.z;
}
Vector3h Vector3h::operator%(const Vector3h& a)
{
	Vector3h b(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
	return b;
}
void Vector3h::operator=(const Vector3h& a)
{
	setVector3h(a.x,a.y,a.z);
}