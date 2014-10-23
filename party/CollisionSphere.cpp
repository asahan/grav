#include "CollisionSphere.h"

CollisionSphere::CollisionSphere()
{
}

CollisionSphere::~CollisionSphere()
{
}
CollisionSphere::CollisionSphere(Vector3h mCenter, float mRedius)
{
	Bounding.Set(mCenter,mRedius);
	this->SetPosition(mCenter);
}
void CollisionSphere::operator=(const CollisionSphere& temp )
{
	Bounding.Set(temp.Bounding);
	this->SetPosition(Bounding.mCenter);
}

void CollisionSphere::Render()
{
	Bounding.SetCenter(this->Translate);
	sphere.Render(Bounding.mCenter,Bounding.mRedius);
}