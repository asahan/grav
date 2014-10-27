#include "Line3h.h"

Line3h::Line3h()
{
	Origin =Vector3h(0,0,0);
	Direct = Vector3h(0,0,0);
}
Line3h::Line3h(Vector3h origin,Vector3h direct)
{
	Origin = origin;
	Direct = direct;
}
Line3h::~Line3h()
{
}

void Line3h::Set(Vector3h origin,Vector3h direct)
{
	Origin = origin;
	Direct = direct;
}
void Line3h::SetOrigin(Vector3h origin)
{
	Origin = origin;
}
void Line3h::SetDirect(Vector3h direct)
{
	Direct = direct;
}
void Line3h::Get(Vector3h& origin,Vector3h& direct)
{
	origin = Origin;
	direct = Direct;
}
Vector3h Line3h::GetOrigin()
{
	return Origin;
}
Vector3h Line3h::GetDirect()
{
	return Direct;
}