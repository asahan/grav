#ifndef CRECT_H
#define CRECT_H
#include "CShape.h"
#include "Vector3h.h"
#include "gl/gl.h"
class CCube : public CShape
{
	Vector3h min;
	Vector3h max;
	float top[3];
	float bottom[3];
	float left[3];
	float right[3];
	float front[3];
	float back[3];
public:
	CCube();
	~CCube();
	inline void SetFaceTopColor(float r,float g,float b) {top[0]=r,top[1]=g,top[2]=b;}
	inline void SetFaceBottomColor(float r,float g,float b) {bottom[0]=r,bottom[1]=g,bottom[2]=b;}
	inline void SetFaceLeftColor(float r,float g,float b) {left[0]=r,left[1]=g,left[2]=b;}
	inline void SetFaceRightColor(float r,float g,float b) {right[0]=r,right[1]=g,right[2]=b;}
	inline void SetFaceFrontColor(float r,float g,float b) {front[0]=r,front[1]=g,front[2]=b;}
	inline void SetFaceBackColor(float r,float g,float b) {back[0]=r,back[1]=g,back[2]=b;}
	virtual void Render();

};

#endif // CRECT_H
