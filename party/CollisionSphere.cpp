#include "CollisionSphere.h"

CollisionSphere::CollisionSphere()
{
	this->SetShape(Sphere);
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
	this->SetShape(Sphere);
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

bool CollisionSphere::ProcessColliding(CollisionObject* b,Vector3h& CollisionNormal, float& penetration,Vector3h* CollisionPoint,int& numHit)
{
	Vector3h point;
	bool result=false;
	if(b->GetShape() == Cube)
	{
		CollisionCube* temp = (CollisionCube*)b;
		result=temp->Bounding.ComputeCollision(Bounding,CollisionNormal,penetration,point);
		CollisionPoint[0]=point;
		numHit = 1;
		Vector3h firstpos=this->GetPosition();
		firstpos-=CollisionNormal*0.5*penetration;
		this->SetPosition(firstpos);
		Vector3h secondpos=temp->GetPosition();
		secondpos+=CollisionNormal*0.5*penetration;
		temp->SetPosition(secondpos);
		
	}
	else if(b->GetShape() == Sphere)
	{
		CollisionSphere* temp = (CollisionSphere*)b;
		result = temp->Bounding.ComputeCollision(this->Bounding,CollisionNormal,penetration,point);
		CollisionPoint[0]=point;
		numHit = 1; 
		Vector3h firstpos=temp->GetPosition();
		firstpos-=CollisionNormal*0.5*penetration;
		temp->SetPosition(firstpos);
		Vector3h secondpos=this->GetPosition();
		secondpos+=CollisionNormal*0.5*penetration;
		this->SetPosition(secondpos);
	}
	return result;
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