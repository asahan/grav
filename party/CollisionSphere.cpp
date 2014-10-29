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
	sphere.Set(this->matWorld);
	sphere.mRedius = mRedius;
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
bool CollisionSphere::HandleCollision(CollisionSphere* other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint) 
{
	if(Bounding.ComputeCollision(other->Bounding,CollisionNormal,penetration,CollisionPoint) == true){
		Vector3h firstpos=this->GetPosition();
		firstpos-=CollisionNormal*0.5*penetration;
		this->SetPosition(firstpos);
		Vector3h secondpos=other->GetPosition();
		secondpos+=CollisionNormal*0.5*penetration;
		other->SetPosition(secondpos);
		return true;
	}
	return false;
	
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