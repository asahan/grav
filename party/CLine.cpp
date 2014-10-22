#include "CLine.h"
#include "Vector3h.h"
CLine::CLine(Vector3h Origin,Vector3h endpoint)
{
	this->mOrigin=Origin;
	this->mDirection=endpoint-Origin;
	
}
CLine::CLine()
{
	Vector3h temp;
	mOrigin=temp;
	mDirection=temp;
}
CLine::~CLine()
{
}

void CLine:: Render()
{
	
}
void CLine::Set(Vector3h a[2])
{
	this->mOrigin=a[0];
	this->mDirection=a[1]-a[0];
}

