#ifndef VECTOR4H_H
#define VECTOR4H_H
#include "gl/gl.h"
#include "Vector3h.h"
class Vector4h
{
public:
	GLfloat x,y,z,w;
public:
	Vector4h(GLfloat x,GLfloat y,GLfloat z,GLfloat w);
	Vector4h(Vector4h& cre);
	Vector4h(Vector3h& cre);
	Vector4h();
	~Vector4h();
	void setVector4h(GLfloat x,GLfloat y,GLfloat z,GLfloat w=0);
	void setVector4h(Vector4h& temp);
	void setVector4h(Vector3h& temp);
};

#endif // VECTOR4H_H
