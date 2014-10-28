#include "CollisionCube.h"

CollisionCube::CollisionCube()
{
}

CollisionCube::~CollisionCube()
{
}
CollisionCube::CollisionCube(Vector3h min, Vector3h max)
{
	Vector3h temp = max - min;
	temp = temp * 0.5; 
	temp = min + temp;
	this->SetPosition(temp);
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
}
void CollisionCube::Render()
{
	cube.Render();
}