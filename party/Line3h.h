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
	friend void ClosestPoint(Vector3h& p0, Vector3h& p1, Line3h& line0, Line3h& line1);
	
	bool IntersectionPoint(Line3h p1,Vector3h& point);
	
	
	
	

};

#endif // LINE3H_H
