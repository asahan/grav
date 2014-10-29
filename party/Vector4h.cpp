#include "Vector4h.h"

Vector4h::Vector4h(GLfloat w,GLfloat x,GLfloat y,GLfloat z):x(x),y(y),z(z),w(w){};

Vector4h::Vector4h()
{
	x=y=z=w=0;
}

Vector4h::~Vector4h()
{
}
Vector4h::Vector4h(Vector4h& cre)
{
	x=cre.x,y=cre.y,z=cre.z,w=cre.w;
}
Vector4h::Vector4h(Vector3h& cre)
{
	w=cre.x,x=cre.y,y=cre.z,z=0;
}

void Vector4h::setVector4h(GLfloat w,GLfloat x,GLfloat y,GLfloat z)
{
	this->x=x,this->y=y,this->z=z,this->w=w;
}
void Vector4h::setVector4h(Vector4h& temp)
{
	x=temp.x,y=temp.y,z=temp.z,w=temp.w;
}
void Vector4h::setVector4h(Vector3h& temp)
{
	w=temp.x,x=temp.y,y=temp.z,z=0;
}