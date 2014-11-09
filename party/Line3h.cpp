#include "Line3h.h"
#include "math.h"
#define  epsilon    1.0e-6f

bool isZero(float a){
	return fabsf(a) < epsilon;
	
}
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

void ClosestPoint(Vector3h& p0, Vector3h& p1, Line3h& line0, Line3h& line1)
{
	Vector3h w0 = line0.Origin - line1.Origin;
    float a = line0.Direct.Dot( line0.Direct);
    float b = line0.Direct.Dot( line1.Direct);
    float c = line1.Direct.Dot( line1.Direct);
    float d = line0.Direct.Dot( w0 );
    float e = line1.Direct.Dot( w0 );

    float denom = a*c - b*b;

    if ( isZero(denom) )
    {
        p0 = line0.Origin;
        p1 = line1.Origin + line1.Direct*(e/c);
    }
    else
    {
        p0 = line0.Origin + line0.Direct*((b*e - c*d)/denom);
        p1 = line1.Origin + line1.Direct*((a*e - b*d)/denom);
    }
	return ;
}
bool Line3h::IntersectionPoint(Line3h p1 , Vector3h& point)
{
	Vector3h Line0Point[2];
	Vector3h Line1Point[2];
	Line0Point[0] = this->Origin;
	Line0Point[1] = this->Origin + this->Direct;
	p1.Get(Line1Point[0],Line1Point[1]);
	Line1Point[1] = Line1Point[0] + Line1Point[1];
	float t0,t1;
	t0 = (Line0Point[1].x - Line0Point[0].x)*(Line1Point[1].y - Line1Point[0].y) - (Line0Point[1].y - Line0Point[0].y)*(Line1Point[1].x - Line1Point[0].x);
	if(t0 == 0)
	{
		Vector3h diff = this->Origin - Line1Point[0];
		Vector3h direct = diff.Cross(this->Direct);
		if(direct == Vector3h(0,0,0)){
			point = Vector3h(0,0,0);
		}
			return false;
	}
	t1 = (Line0Point[1].y - Line1Point[1].y)*(Line1Point[1].x - Line1Point[0].x) - (Line0Point[1].x - Line1Point[1].x)*(Line1Point[1].y - Line1Point[0].y);
	
	float t = t1 / t0;
	if(t<0 || t>1)
		return false;
	point = this->Origin + this->Direct*t;
	return true;
}