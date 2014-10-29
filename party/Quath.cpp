#include "Quath.h"
#include "math.h"

Quath::Quath()
{
	w=1.0;
	x=y=z=0;
}

Quath::~Quath()
{
}

Quath::Quath(float w,float x,float y,float z):w(w),x(x),y(y),z(z)
{
};
Quath::Quath(const Vector3h& vec)
{
	Set(0,vec.x,vec.y,vec.z);
}
void Quath::Set(float w,float x,float y,float z)
{
	this->w=w,this->x=x,this->y=y,this->z=z;
}
void Quath::Set(const Vector3h axis,float angle)
{
	Vector3h t_axis=axis;
	float t_angle=0.5*angle;
	w=cosf(t_angle);
	if(t_axis.magnitude()==0)
	{
		w=1,x=y=z=0;
		return;
	}
	t_axis.normalize();
	float v_sin=sinf(t_angle);
	t_axis*=v_sin;
	
	x=t_axis.x;
	y=t_axis.y;
	z=t_axis.z;
	
}
float Quath::Magnitude()
{
	return (w*w+x*x+y*y+z*z);
}

float Quath::Size()
{
	return sqrtf(Magnitude());
}
void Quath::Normalize()
{
	float size=Size();
	if(size == 0)
	{
		w=x=y=z=0; return;
	}
	float inverse=1/size;
	w*=inverse;
	x*=inverse;
	y*=inverse;
	z*=inverse;
}
float Quath::Dot(const Quath& quat)
{
	return (w*quat.w+x*quat.x+y*quat.y+z*quat.z);
}

Quath Quath::Conjugate()
{
	return Quath(w,-x,-y,-z);
}

void Quath::ToRatationMatrix(Matrix3h& rot)
{
	float xx=2*x*x;
	float xy=2*x*y;
	float xz=2*x*z;
	float yy=2*y*y;
	float yz=2*y*z;
	float zz=2*z*z;
	float wx=2*w*x;
	float wy=2*w*y;
	float wz=2*w*z;
	rot.index[0]=1-yy-zz;
	rot.index[1]=xy+wz;
	rot.index[2]=xz-wy;
	rot.index[3]=xy-wz;
	rot.index[4]=1-xx-zz;
	rot.index[5]=yz+wx;
	rot.index[6]=xz+wy;
	rot.index[7]=yz-wx;
	rot.index[8]=1-xx-yy;
	
}
Quath Quath::operator+(const Quath& quat)
{
	float t_w=w+quat.w;
	float t_x=x+quat.x;
	float t_y=y+quat.y;
	float t_z=z+quat.z;
	return Quath(t_w, t_x, t_y, t_z);
}
void Quath::operator+=(const Quath& quat)
{
	w=w+quat.w;
	x=x+quat.x;
	y=y+quat.y;
	z=z+quat.z;
}
Quath Quath::operator*(const Quath& quat)
{
	Quath ret;
	ret.w = w*quat.w - x*quat.x - y*quat.y - z*quat.z;
	ret.x = w*quat.x + x*quat.w + y*quat.z - z*quat.y;
	ret.y = w*quat.y - x*quat.z + y*quat.w + z*quat.x;
	ret.z = w*quat.z + x*quat.y - y*quat.x + z*quat.w;
	return ret;
}
void Quath::operator*=(const Quath& quat)
{
	w = w*quat.w - x*quat.x - y*quat.y - z*quat.z;
	x = w*quat.x + x*quat.w + y*quat.z - z*quat.y;
	y = w*quat.y - x*quat.z + y*quat.w + z*quat.x;
	z = w*quat.z + x*quat.y - y*quat.x + z*quat.w;
}
Quath Quath::operator*(float quat)
{
	Quath ret;
	ret.w = w*quat, ret.x = x*quat, ret.y = y*quat , ret.z = z*quat;
	return ret;
}
void Quath::operator*=(float quat)
{
	w = w*quat, x = x*quat, y = y*quat , z = z*quat;
}