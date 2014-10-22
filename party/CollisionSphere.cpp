#include "CollisionSphere.h"

CollisionSphere::CollisionSphere()
{
}

CollisionSphere::~CollisionSphere()
{
}
CollisionSphere::CollisionSphere(const CSphere& sphere)
{
	Sphere.Set(sphere);
	Bounding.Set(sphere);
}
CollisionSphere::CollisionSphere(Vector3h mCenter, float mRedius)
{
	Sphere.Set(mCenter,mRedius);
	Bounding.Set(Sphere);
}
void CollisionSphere::operator=(const CollisionSphere& temp )
{
	Sphere.Set(temp.Sphere);
}

void CollisionSphere::Render()
{
	
}