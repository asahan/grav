#ifndef CLINE_H
#define CLINE_H
#include "CShape.h"
#include "Vector3h.h"

class CLine : public CShape
{
public:
	Vector3h mOrigin;
	Vector3h mDirection;
	
	
public:
	CLine(Vector3h Origin,Vector3h endpoint);
	CLine();
	~CLine();
	virtual void Render();
	void Set(Vector3h a[2]);
	

};

#endif // CLINE_H
