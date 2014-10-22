#include "Matrix4h.h"

Matrix4h::Matrix4h(GLfloat a[16])
{
	for(int i=0;i<16;i++)
		this->index[i]=a[i];
}
Matrix4h::Matrix4h(GLfloat a[4][4])
{
	for(int j=0;j<4;j++)
		for(int i=0;i<4;i++)
			this->index[j*4+i]=a[i][j];
}
Matrix4h::Matrix4h()
{
	for(int i=0;i<16;i++)
		this->index[i]=0;
	
	index[0]=index[5]=index[10]=index[15]=1;
}
Matrix4h::~Matrix4h()
{
}

Vector4h Matrix4h::operator*(const Vector4h& a)
{
	GLfloat temp[4]={0,};
	temp[0]=index[0]*a.x+index[4]*a.y+index[8]*a.z+index[12]*a.w;
	temp[1]=index[1]*a.x+index[5]*a.y+index[9]*a.z+index[13]*a.w;
	temp[2]=index[2]*a.x+index[6]*a.y+index[10]*a.z+index[14]*a.w;
	temp[3]=index[3]*a.x+index[7]*a.y+index[11]*a.z+index[15]*a.w;
	Vector4h result(temp[0],temp[1],temp[2],temp[3]);
	return result;
	
}
 
 
Matrix4h Matrix4h::operator*(const Matrix4h& a)
{
	GLfloat temp[16]={0,};
	temp[0]=index[0]*a.index[0]+index[4]*a.index[1]+index[8]*a.index[2]+index[12]*a.index[3];
	temp[4]=index[0]*a.index[4]+index[4]*a.index[5]+index[8]*a.index[6]+index[12]*a.index[7];
	temp[8]=index[0]*a.index[8]+index[4]*a.index[9]+index[8]*a.index[10]+index[12]*a.index[11];
	temp[12]=index[0]*a.index[12]+index[4]*a.index[13]+index[8]*a.index[14]+index[12]*a.index[15];
	temp[1]=index[1]*a.index[0]+index[5]*a.index[1]+index[9]*a.index[2]+index[13]*a.index[3];
	temp[5]=index[1]*a.index[4]+index[5]*a.index[5]+index[9]*a.index[6]+index[13]*a.index[7];
	temp[9]=index[1]*a.index[8]+index[5]*a.index[9]+index[9]*a.index[10]+index[13]*a.index[11];
	temp[13]=index[1]*a.index[12]+index[5]*a.index[13]+index[9]*a.index[14]+index[13]*a.index[15];
	temp[2]=index[2]*a.index[0]+index[6]*a.index[1]+index[10]*a.index[2]+index[14]*a.index[3];
	temp[6]=index[2]*a.index[4]+index[6]*a.index[5]+index[10]*a.index[6]+index[14]*a.index[7];
	temp[10]=index[2]*a.index[8]+index[6]*a.index[9]+index[10]*a.index[10]+index[14]*a.index[11];
	temp[14]=index[2]*a.index[12]+index[6]*a.index[13]+index[10]*a.index[14]+index[14]*a.index[15];
	temp[3]=index[3]*a.index[0]+index[7]*a.index[1]+index[11]*a.index[2]+index[15]*a.index[3];
	temp[7]=index[3]*a.index[4]+index[7]*a.index[5]+index[11]*a.index[6]+index[15]*a.index[7];
	temp[11]=index[3]*a.index[8]+index[7]*a.index[9]+index[11]*a.index[10]+index[15]*a.index[11];
	temp[15]=index[3]*a.index[12]+index[7]*a.index[13]+index[11]*a.index[14]+index[15]*a.index[15];
	Matrix4h result(temp);
	return result;
}
Matrix4h Matrix4h::operator+(const Matrix4h& a)
{
	GLfloat temp[16]={0,};
		for(int i=0;i<16;i++)
			temp[i]=index[i]+a.index[i];
	Matrix4h result(temp);
	return result;
}
void Matrix4h::operator+=(const Matrix4h& a)
{
	for(int i=0;i<16;i++)
		index[i]+=a.index[i];
}
Matrix4h Matrix4h::operator-(const Matrix4h& a)
{
	GLfloat temp[16];
	for(int i=0;i<16;i++)
		temp[i]=index[i]-a.index[i];
	Matrix4h result(temp);
	return result;
}
void Matrix4h::operator-=(const Matrix4h& a)
{
	for(int i=0;i<16;i++)
		index[i]-=a.index[i];
}
