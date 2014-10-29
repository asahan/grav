#include "CollisionCube.h"

CollisionCube::CollisionCube()
{
}

CollisionCube::~CollisionCube()
{
}
CollisionCube::CollisionCube(Vector3h pos, Vector3h rotation,Vector3h Extent,float mass)
{
	SetMass(mass);
	SetPosition(pos);
	obb.SetCenter(pos);
	obb.SetExtent(Extent);
	cube.Set(Extent);
	Quath rZ; rZ.Set(Vector3h(0,0,1),rotation.z);
	Quath rY; rY.Set(Vector3h(0,1,0),rotation.y);
	Quath rX; rX.Set(Vector3h(1,0,0),rotation.x);
	this->rotation = rZ;
	this->rotation *= rY;
	this->rotation *= rX;
	this->rotation.Normalize();
	
	Vector3h iner= Extent*2;
	float xx = Extent.x * Extent.x;
	float yy = Extent.y * Extent.y;
	float zz = Extent.z * Extent.z;
	float inerm = (mass/12);
	float ix = inerm*(yy+zz);
	float iy = inerm*(xx+zz);
	float iz = inerm*(xx+yy);
	float inertia[9] = { ix,0,0,0,iy,0,0,0,iz};
	Matrix3h inertiatensor(inertia);
	this->SetLocalinertia(inertiatensor);
	UpdateMatrix();
}


void CollisionCube::SetColorFace(int i,float r,float g,float b) 
{ 
	switch(i){
		case 0:
		cube.SetFaceTopColor(r,g,b);
		break;
		case 1:
		cube.SetFaceBottomColor(r,g,b);
		break;
		case 2:
		cube.SetFaceLeftColor(r,g,b);
		break;
		case 3:
		cube.SetFaceRightColor(r,g,b);
		break;
		case 4:
		cube.SetFaceFrontColor(r,g,b);
		break;
		default:
		cube.SetFaceBackColor(r,g,b);
		
	}
}
void CollisionCube::Update(float dt)
{
	Rigidbody::Update(dt);
	obb.SetAxis(this->rot.GetCol(0),this->rot.GetCol(1),this->rot.GetCol(2));
	obb.SetCenter(this->GetPosition());
	cube.Set(this->matWorld);
	
}
void CollisionCube::Render()
{
	cube.Set(this->matWorld);
	cube.Render();
}