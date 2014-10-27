#ifndef LINE3H_H
#define LINE3H_H
#include "Vector3h.h"

class Line3h
{
public:
	Vector3h Origin;
	Vector3h Direct;
	
public:
	Line3h();
	Line3h(Vector3h origin,Vector3h direct);
	~Line3h();
	
	void Set(Vector3h origin,Vector3h direct);
	void SetOrigin(Vector3h origin);
	void SetDirect(Vector3h direct);
	void Get(Vector3h& origin,Vector3h& direct);
	Vector3h GetOrigin();
	Vector3h GetDirect();
	
	
	

};

#endif // LINE3H_H
