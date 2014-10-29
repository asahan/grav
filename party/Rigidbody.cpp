#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	
}

Rigidbody::~Rigidbody()
{
}



void Rigidbody::Update(float dt)
{
	
	
	//////////linearvelocity update
	
	Vector3h vec = Velocity + acc*dt;
	SetVelocity(vec);
	pos =pos + Velocity*dt;
	
	///////rotation update
	Quath vel(0,AngVelocity.x,AngVelocity.y,AngVelocity.z);
	vel = vel*rotation;
	vel*=0.5*dt;
	rotation += vel;
	rotation.Normalize();
	
	////////////////////
	
	float damping=0.85;
	damping = powf(damping,dt);
	Velocity *= damping;
	AngVelocity*= damping;

	UpdateMatrix();

}
void Rigidbody::UpdateMatrix()
{
	this->rotation.ToRatationMatrix(this->rot);
	
	Matrix4h matR;
	matR.Set(this->rot);
	
	Matrix4h matT; matT.Identity();
	Vector4h trans(pos.x,pos.y,pos.z,1.);
	matT.SetCuloumn(3,trans);
	
	matWorld =matT*matR;
	
}