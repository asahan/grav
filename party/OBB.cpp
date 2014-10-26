#include "OBB.h"
#include "math.h"
OBB::OBB()
{
	this->Center = Vector3h (0,0,0);
	this->Extent [0]=1;
	this->Extent [1] =1;
	this->Extent [2]=1;
	
	this->Axis[0]=Vector3h (1,0,0);
	this->Axis[1]=Vector3h (0,1,0);
	this->Axis[2]=Vector3h (0,0,1);
}

OBB::~OBB()
{
}

OBB::OBB(const Vector3h Center,const Vector3h Axis[3],const float Extent[3])
{
	this->Center=Center;
	for(int i=0;i<3;i++)
	{
		this->Axis[i]=Axis[i];
		this->Extent[i]=Extent[i];
	}
}
OBB::OBB(const Vector3h Center,const Vector3h axis[3])
{
	this->Center=Center;
	Vector3h temp[3];
	for(int i=0;i<3;i++)
	{
		temp[i]=axis[i];
		this->Extent[i]=temp[i].Size();
		float inverse=1/this->Extent[i];
		this->Axis[i]=temp[i]*inverse;
	}
}
OBB::OBB(const OBB& other)
{
	this->Center = other.Center;
	for(int i=0;i<3;i++)
	{
		this->Axis[i]=other.Axis[i];
		this->Extent[i]=other.Extent[i];
	}
	
}
bool OBB::SpanIntersect(OBB& other,Vector3h axis,float& penetration,Vector3h& minaxis)
{
	
	float min=99999,max=-99999;;
	float othermin=99999,othermax=-99999;

	for(int i=0;i<8;i++)
	{
		Vector3h ver=GetVertex(i);
		float temp = ver*axis;
		
		if(temp < min)
			min = temp;
		else if(temp > max)
			max = temp;
			
		Vector3h otherver=other.GetVertex(i);
		float othertemp = otherver*axis;
		if(othertemp < othermin)
			othermin = othertemp;
		else if(othertemp > othermax)
			othermax = othertemp;
	}
	
	float length = max - min;
	float otherlength = othermax - othermin;
	float sum = length + otherlength;
	
	float minimum = (min>othermin) ? othermin:min ;
	float maximum = (max>othermax) ? max:othermax ;
	float len = maximum - minimum;
	
	if(len > sum)
		return false;
	
	
	float pene = sum - len;
	if(pene < penetration)
	{
			minaxis = axis;
			penetration = pene;
	}
	return true;
	
}
bool OBB::Intersect(OBB& other)
{
	bool hit=true;
	float minpenentration=10000.f;
	Vector3h minAxis;
	hit&=SpanIntersect(other,Axis[0],minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[1],minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[2],minpenentration,minAxis);
	hit&=SpanIntersect(other,other.Axis[0],minpenentration,minAxis);
	hit&=SpanIntersect(other,other.Axis[1],minpenentration,minAxis);
	hit&=SpanIntersect(other,other.Axis[2],minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[0].Cross(other.Axis[0]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[0].Cross(other.Axis[1]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[0].Cross(other.Axis[2]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[1].Cross(other.Axis[0]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[1].Cross(other.Axis[1]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[1].Cross(other.Axis[2]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[2].Cross(other.Axis[0]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[2].Cross(other.Axis[1]),minpenentration,minAxis);
	hit&=SpanIntersect(other,Axis[2].Cross(other.Axis[2]),minpenentration,minAxis);
	
	return hit;
}
bool Intersect(BoundingSphere& other)
{
	return false;
}
Vector3h OBB::GetVertex(int i)
{
	Vector3h ret;
	switch(i){
		case 0:
			ret=Center+Axis[0]*Extent[0]+Axis[1]*Extent[1]+Axis[2]*Extent[2];
		break;
		case 1:
			ret=Center+Axis[0]*Extent[0]+Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		case 2:
			ret=Center+Axis[0]*Extent[0]-Axis[1]*Extent[1]+Axis[2]*Extent[2];
		break;
		case 3:
			ret=Center+Axis[0]*Extent[0]-Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		case 4:
			ret=Center-Axis[0]*Extent[0]+Axis[1]*Extent[1]+Axis[2]*Extent[2];
		break;
		case 5:
			ret=Center-Axis[0]*Extent[0]+Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		case 6:
			ret=Center-Axis[0]*Extent[0]-Axis[1]*Extent[1]+Axis[2]*Extent[2];
		break;
		case 7:
			ret=Center-Axis[0]*Extent[0]-Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		default:
		;
	}
	return ret;
}
