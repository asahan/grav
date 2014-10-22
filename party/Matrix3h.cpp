#include "Matrix3h.h"
#include "Vector3h.h"
Matrix3h::Matrix3h()
{
	for(int i=0;i<9;i++)
		this->index[i]=0;
}
Matrix3h::Matrix3h(GLfloat a[9])
{
	for(int i=0;i<9;i++)
		this->index[i]=a[i];
}
Matrix3h::Matrix3h(GLfloat a[3][3])
{
	for(int j=0;j<3;j++)
		for(int i=0;i<3;i++)
			this->index[j*3+i]=a[i][j];
}

Matrix3h::~Matrix3h()
{
}

Vector3h Matrix3h::operator*(const Vector3h& a)
{
	Vector3h result(index[0]*a.x+index[3]*a.y+index[6]*a.z,
					index[1]*a.x+index[4]*a.y+index[7]*a.z,
					index[2]*a.x+index[5]*a.y+index[8]*a.z);
	return result;
}
Matrix3h Matrix3h::operator*(const Matrix3h& a)
{
	GLfloat temp[9]={0,};
	temp[0]=index[0]*a.index[0]+index[3]*a.index[1]+index[6]*a.index[2];
	temp[3]=index[0]*a.index[3]+index[3]*a.index[4]+index[6]*a.index[5];
	temp[6]=index[0]*a.index[6]+index[3]*a.index[7]+index[6]*a.index[8];
	temp[1]=index[1]*a.index[0]+index[4]*a.index[1]+index[7]*a.index[2];
	temp[4]=index[1]*a.index[3]+index[4]*a.index[4]+index[7]*a.index[5];
	temp[7]=index[1]*a.index[6]+index[4]*a.index[7]+index[7]*a.index[8];
	temp[2]=index[2]*a.index[0]+index[5]*a.index[1]+index[8]*a.index[2];
	temp[5]=index[2]*a.index[3]+index[5]*a.index[4]+index[8]*a.index[5];
	temp[8]=index[2]*a.index[6]+index[5]*a.index[7]+index[8]*a.index[8];
	Matrix3h result(temp);
	return result;
}
Matrix3h Matrix3h::operator+(const Matrix3h& a)
{
	GLfloat temp[9];
	for(int i=0;i<9;i++)
		temp[i]=index[i]+a.index[i];
	Matrix3h result(temp);
	return result;
}
void Matrix3h::operator+=(const Matrix3h& a)
{
	for(int i=0;i<9;i++)
		index[i]+=a.index[i];
}
Matrix3h Matrix3h::operator-(const Matrix3h& a)
{
	GLfloat temp[9];
	for(int i=0;i<9;i++)
		temp[i]=index[i]-a.index[i];
	Matrix3h result(temp);
	return result;
}
void Matrix3h::operator-=(const Matrix3h& a)
{
	for(int i=0;i<9;i++)
		index[i]-=a.index[i];
}