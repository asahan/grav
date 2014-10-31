#include "CollisionSphere.h"

CollisionSphere::CollisionSphere()
{
	Bounding.Set(Vector3h(3,3,3),1);
	this->SetPosition(Vector3h(3,3,3));
	this->SetMass(4.);
	sphere.Set(this->matWorld);
	sphere.mRedius = 1;
	baseShape = Shape_Sphere;
	float moment = (2/5)*mMass*1;
	float inertia[9]={moment,0,0,0,moment,0,0,0,moment};
	Matrix3h inertiatensor(inertia);
	this->SetLocalinertia(inertiatensor);
	UpdateMatrix();
}

CollisionSphere::~CollisionSphere()
{
}
CollisionSphere::CollisionSphere(Vector3h mCenter, float mRedius,float mass)
{
	Bounding.Set(mCenter,mRedius);
	this->SetPosition(mCenter);
	this->SetMass(mass);
	sphere.Set(this->matWorld);
	sphere.mRedius = mRedius;
	baseShape = Shape_Sphere;
	
	float moment = (2/5)*mass*mRedius*mRedius;
	float inertia[9]={moment,0,0,0,moment,0,0,0,moment};
	Matrix3h inertiatensor(inertia);
	this->SetLocalinertia(inertiatensor);
	UpdateMatrix();
}
void CollisionSphere::operator=(const CollisionSphere& temp )
{
	Bounding.Set(temp.Bounding);
	this->SetPosition(Bounding.mCenter);
}
void CollisionSphere::operator=(const CollisionSphere* temp)
{
	Bounding.Set(temp->Bounding);
	this->SetPosition(Bounding.mCenter);
}


void CollisionSphere::Applyimpulse()
{
	
}
void CollisionSphere::Update(float dt)
{
	Rigidbody::Update(dt);
	Bounding.SetCenter(this->pos);
	sphere.Set(this->matWorld);
}
void CollisionSphere::Render()
{
	sphere.Render();
}