#include "OBB.h"
#include "math.h"
#include "Line3h.h"
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
void OBB::SetCenter(const Vector3h& pos)
{
	Center = pos;
}
void OBB::SetExtent(const Vector3h& Extent)
{
	this->Extent[0]=Extent.x;
	this->Extent[1]=Extent.y;
	this->Extent[2]=Extent.z;
}
void OBB::SetAxis(const Vector3h& Axisx,const Vector3h& Axisy,const Vector3h& Axisz)
{
	this->Axis[0] = Axisx;
	this->Axis[1] = Axisy;
	this->Axis[2] = Axisz;
}
bool OBB::SpanIntersect(OBB& other,Vector3h axis,float& penetration,Vector3h& minaxis)
{
	
	float min=99999,max=-99999;;
	float othermin=99999,othermax=-99999;

	for(int i=0;i<8;i++)
	{
		Vector3h ver=GetVertex(i);
		float temp = ver.Dot(axis);
		
		if(temp < min)
			min = temp;
		else if(temp > max)
			max = temp;
			
		Vector3h otherver=other.GetVertex(i);
		float othertemp = otherver.Dot(axis);
		if(othertemp < othermin)
			othermin = othertemp;
		else if(othertemp > othermax)
			othermax = othertemp;
	}
	
	float length = max - min;
	float otherlength = othermax - othermin;
	float sum = length + otherlength;
	
	float minimum = (min>othermin) ? othermin : min ;
	float maximum = (max>othermax) ? max : othermax ;
	float len = maximum - minimum;
	
	if(len > sum)
		return false;
	
	
	float pene = sum - len;
	if(pene < penetration)
	{
			
			if(othermin < min)
				minaxis = axis*-1;
			else
				minaxis = axis;
			penetration = pene;
	}
	return true;
	
}
bool OBB::Intersect(OBB& other,float& minpen,Vector3h& axis)
{
	
	float minpenentration=10000.f;
	Vector3h minAxis;
	Vector3h seperatingAxis[15];
	Vector3h otherAxis[3];
	for(int i=0; i<3 ; i++)
		otherAxis[i]=other.GetAxis(i);
		
	seperatingAxis[0]=Axis[0];
	seperatingAxis[1]=Axis[1];
	seperatingAxis[2]=Axis[2];
	seperatingAxis[3]=otherAxis[0];
	seperatingAxis[4]=otherAxis[1];
	seperatingAxis[5]=otherAxis[2];
	seperatingAxis[6]=Axis[0].Cross(otherAxis[0]);
	seperatingAxis[7]=Axis[0].Cross(otherAxis[1]);
	seperatingAxis[8]=Axis[0].Cross(otherAxis[2]);
	seperatingAxis[9]=Axis[1].Cross(otherAxis[0]);
	seperatingAxis[10]=Axis[1].Cross(otherAxis[1]);
	seperatingAxis[11]=Axis[1].Cross(otherAxis[2]);
	seperatingAxis[12]=Axis[2].Cross(otherAxis[0]);
	seperatingAxis[13]=Axis[2].Cross(otherAxis[1]);
	seperatingAxis[14]=Axis[2].Cross(otherAxis[2]);
	
	for(int i=0;i<15;i++)
	{
		if(!SpanIntersect(other,seperatingAxis[i],minpenentration,minAxis))
			return false;
	}
	
	minpen = minpenentration;
	axis = minAxis;
	return true;
}
bool OBB::Intersect(BoundingSphere& other)
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
			ret=Center-Axis[0]*Extent[0]+Axis[1]*Extent[1]+Axis[2]*Extent[2];
		break;
		case 2:
			ret=Center-Axis[0]*Extent[0]-Axis[1]*Extent[1]+Axis[2]*Extent[2];
		break;
		case 3:
			ret=Center+Axis[0]*Extent[0]-Axis[1]*Extent[1]+Axis[2]*Extent[2];
		break;
		
		case 4:
			ret=Center+Axis[0]*Extent[0]+Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		case 5:
			ret=Center-Axis[0]*Extent[0]+Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		case 6:
			ret=Center-Axis[0]*Extent[0]-Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		case 7:
			ret=Center+Axis[0]*Extent[0]-Axis[1]*Extent[1]-Axis[2]*Extent[2];
		break;
		default:
		;
	}
	return ret;
}
int OBB::GetNumHitPoints(const Vector3h& normal,const float& penetration,Vector3h* vertex,int* vertindex)
{
	float max = GetVertex(0)*normal;
	Vector3h maxvec = GetVertex(0);
	for(int i=0;i<8;i++)
	{
		float temp = GetVertex(i)*normal;
		if(temp > max)
		{
			max = temp;
		}
	}
	
	float d = max - penetration ;
	int numHits=0;
	for(int i=0;i<8;i++)
	{
		Vector3h ver = GetVertex(i);
		float temp = ver*normal;
		if(temp > d)
		{
			vertex[numHits]=ver;
			max = temp;
			vertindex[numHits]=i;
			numHits++;
		}
	}
	
	return numHits;
}
void OBB::ClipLinePlane(const Vector3h& point, Vector3h& collisionpoint) 
{
	Vector3h center = this->Center;
	Vector3h ret = center;
	Vector3h distance = point - center;
	
	
	for (int i=0; i<3; i++)
	{
		float dist = distance.Dot(this->Axis[i]);
		
		if (dist >  this->Extent[i]) 
			dist =  this->Extent[i];
		if (dist < -(this->Extent[i])) 
			dist = -(this->Extent[i]);
			
		Vector3h axis = this->Axis[i];
		ret += axis * dist;
	}

	collisionpoint = ret;
}
void OBB::ClipPlanePlane(Vector3h* vert0, Vector3h* vert1, Vector3h normal0,Vector3h* points, int& numCount)
{
	
	return;
}
bool OBB::ComputeCollision(OBB& other, Vector3h& CollisionNormal, float& penetration, Vector3h* CollisionPoint,int& numhitpoint) 
{
	
	bool ret=false;
	Vector3h normal;
	float minpenetration;
	ret=Intersect(other,minpenetration,normal);
	if(!ret)
		return false;
	Vector3h vertex0[8];
	int vert0=0;
	int vert0index[8]={-1,};
	vert0 = GetNumHitPoints(normal,minpenetration,vertex0,vert0index);
	Vector3h vertex1[8];
	int vert1=0;
	int vert1index[8]={-1,};
	Vector3h norm= normal * -1;
	vert1 = other.GetNumHitPoints(norm,minpenetration,vertex1,vert1index);
	if(vert0 == 0 || vert1==0)
		return false;
	
	penetration = minpenetration;
	CollisionNormal = normal;
	/*
	if(vert0 >= 4 && vert1 >= 4)
	{
		Vector3h face0normal = normal;
		Vector3h face1normal = norm;
		Vector3h face0vertex[4];
		Vector3h face1vertex[4];
		Vector3h facevertex[8];
		for(int i=0;i<4;i++)
		{
			face0vertex[i]=GetVertex(vert0index[i]);
			face1vertex[i]=other.GetVertex(vert1index[i]);
			face1vertex[i]= face1vertex[i] + face0normal*(face0normal.Dot(face0vertex[0]-face1vertex[i]));
			facevertex[i] = face0vertex[i];
			facevertex[i+4] = face1vertex[i];
		}
		 
		
		
	}*/
	if((vert0 == 4 && vert1==2 ) || (vert0 == 2 && vert1==4 ))
	{
		numhitpoint=2;
		Vector3h point0;
		Vector3h point1;
		if(vert0 == 4)
		{
			this->ClipLinePlane(vertex1[0], point0);
			this->ClipLinePlane(vertex1[1], point1);
		}
		else
		{
			other.ClipLinePlane(vertex0[0], point0);
			other.ClipLinePlane(vertex0[0], point1);
		}

		CollisionPoint[0]=point0;
		CollisionPoint[1]=point1;
		return true;
		
	}
	else if((vert0 == 4 && vert1==1 ) || (vert0 == 1 && vert1==4 ))
	{
		numhitpoint=1;
		Vector3h point;
		if(vert0 == 4)
			point=other.GetVertex(vert1index[0]);
		else
			point=GetVertex(vert0index[0]);
		
		CollisionPoint[0]=point;
		return true;
	}
	else if(vert0 == 2 && vert1==2)
	{
		numhitpoint=1;
		Vector3h line0origin = vertex0[0];
		Vector3h line0direct = vertex0[1] - line0origin;
		Vector3h line1origin = vertex1[0];
		Vector3h line1direct = vertex1[1] - line1origin;
		Line3h line0; line0.Set(line0origin,line0direct);
		Line3h line1; line1.Set(line1origin,line1direct);
		Vector3h point0,point1;
		ClosestPoint(point0,point1,line0,line1);
		CollisionPoint[0]=point0*0.5+point1*0.5;
		return true;
	}
	
	return true;
	
}
bool OBB::ComputeCollision( BoundingSphere& other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint)
{
	Vector3h distance = other.GetCenter() - Center;
	
	Vector3h max = Axis[0]*Extent[0]+Axis[1]*Extent[1]+Axis[2]*Extent[2];
	Vector3h min = max*-1;
	
	if(distance*min > 0){
		Vector3h temp = min;
		min = max;
		max = min;
	}
	BoundingSphere relative(distance , other.GetRedius());
	AABB origin(min,max);
	Vector3h normal,point;
	float pene;
	if(!origin.ComputeCollision(relative,normal,pene,point))
		return false;
	Matrix3h inverse;
	inverse.SetCol(0,Axis[0]); inverse.SetCol(1,Axis[1]); inverse.SetCol(2,Axis[2]);
	inverse.Inverse();
	CollisionNormal = inverse*normal;
	point = inverse*point;
	point += Center;
	CollisionPoint = point;
	penetration = pene;
	return true;
}