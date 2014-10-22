#include "CSphere.h"

CSphere::CSphere()
{
	mCenter=Vector3h(0.f,0.f,0.f);
	mRedius=0;
}
CSphere::CSphere(Vector3h mCenter,float mRedius):mCenter(mCenter),mRedius(mRedius){};
CSphere::~CSphere()
{
}
void CSphere::Set(const CSphere& sphere)
{
	mCenter=sphere.mCenter;
	mRedius=sphere.mRedius;
	
}
void CSphere::Set(Vector3h mCenter,float mRedius)
{
	this->mCenter = mCenter;
	this->mRedius = mRedius;
}
void CSphere::Render()
{
	 glutSolidSphere( mRedius, 24, 12 );
}


