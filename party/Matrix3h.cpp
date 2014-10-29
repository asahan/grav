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

Matrix3h Matrix3h::Inverse()
{
	Matrix3h ret;
	
	float cof0 = index[4]*index[8] - index[5]*index[7];
	float cof1 = index[1]*index[8] - index[2]*index[7];
	float cof2 = index[1]*index[5] - index[2]*index[4];
	float det = index[0]*cof0 - index[3]*cof1 + index[6]*cof2;
	if(det == 0)
		return ret;
	float invdet = 1/det;
	
	ret.index[0] = invdet * cof0;
	ret.index[1] = invdet * (-cof1);
	ret.index[2] = invdet * cof2;
	
	ret.index[3] = invdet*-(index[3]*index[8] - index[5]*index[6]);
	ret.index[4] = invdet*(index[0]*index[8] - index[2]*index[6]);
	ret.index[5] = invdet*-(index[0]*index[5] - index[2]*index[3]);
	
	ret.index[6] = invdet*(index[3]*index[7] - index[4]*index[6]);
	ret.index[7] = invdet*-(index[0]*index[7] - index[1]*index[6]);
	ret.index[8] = invdet*(index[0]*index[4] - index[1]*index[3]);
	
	
	return ret;
}
Matrix3h Transpose(const Matrix3h& a)
{
	Matrix3h ret;
	ret.index[0] = a.index[0];
	ret.index[1] = a.index[3];
	ret.index[2] = a.index[6];
	ret.index[3] = a.index[1];
	ret.index[4] = a.index[4];
	ret.index[5] = a.index[7];
	ret.index[6] = a.index[2];
	ret.index[7] = a.index[5];
	ret.index[8] = a.index[8];
	return ret;
}
void Matrix3h::Identity()
{
	for(int i=0;i<9;i++)
		this->index[i]=0;
	index[0]=index[4]=index[8]=1;
}
Vector3h Matrix3h::GetRow(unsigned int i)
{
	Vector3h ret;
	switch(i){
		case 0:
		ret.x = index[0]; ret.y = index[3]; ret.z = index[6];
		break;
		case 1:
		ret.x = index[1]; ret.y = index[4]; ret.z = index[7];
		break;
		case 2:
		ret.x = index[2]; ret.y = index[5]; ret.z = index[8];
		break;
		default:
		ret.x =0; ret.y = 0; ret.z = 0;
		break;
	}
	return ret;
}
Vector3h Matrix3h::GetCol(unsigned int i)
{
	Vector3h ret;
	switch(i){
		case 0:
		ret.x = index[0]; ret.y = index[1]; ret.z = index[2];
		break;
		case 1:
		ret.x = index[3]; ret.y = index[4]; ret.z = index[5];
		break;
		case 2:
		ret.x = index[6]; ret.y = index[7]; ret.z = index[8];
		break;
		default:
		ret.x =0; ret.y = 0; ret.z = 0;
		break;
	}
	return ret;
}
void Matrix3h::SetRow(unsigned int i,const Vector3h& a)
{
	switch(i){
		case 0:
		index[0] = a.x, index[3] = a.y, index[6] = a.z;
		break;
		case 1:
		index[1] = a.x, index[4] = a.y, index[7] = a.z;
		break;
		case 2:
		index[2] = a.x, index[5] = a.y, index[8] = a.z;
		break;
		default:
		break;
	}
}
void Matrix3h::SetCol(unsigned int i,const Vector3h& a)
{
	switch(i){
		case 0:
		index[0] = a.x, index[1] = a.y, index[2] = a.z;
		break;
		case 1:
		index[3] = a.x, index[4] = a.y, index[5] = a.z;
		break;
		case 2:
		index[6] = a.x, index[7] = a.y, index[8] = a.z;
		break;
		default:
		break;
	}
}
void Matrix3h::operator=(const Matrix3h& a)
{
	for(int i=0;i<9;i++)
		index[i]=a.index[i];
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