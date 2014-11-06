#include "CollisionCube.h"

CollisionCube::CollisionCube()
{
	this->SetShape(Cube);
	SetMass(5.);
	SetPosition(Vector3h(5,5,5));
	SetElasticity(0.5);
	Bounding.SetCenter(GetPosition());
	Bounding.SetExtent(Vector3h(1,1,1));
	cube.Set(Vector3h(1,1,1));
	baseShape = Shape_Cube;
	
	Vector3h iner= Vector3h(1,1,1)*2;
	float xx = iner.x * iner.x;
	float yy = iner.y * iner.y;
	float zz = iner.z * iner.z;
	float inerm = (mMass/12);
	float ix = inerm*(yy+zz);
	float iy = inerm*(xx+zz);
	float iz = inerm*(xx+yy);
	float inertia[9] = { ix,0,0,0,iy,0,0,0,iz};
	Matrix3h inertiatensor(inertia);
	this->SetLocalinertia(inertiatensor);
	UpdateMatrix();
}

CollisionCube::~CollisionCube()
{
}
CollisionCube::CollisionCube(Vector3h pos, Vector3h rotation,Vector3h Extent,float mass)
{
	this->SetShape(Cube);
	SetMass(mass);
	SetPosition(pos);
	SetElasticity(0.5);
	Bounding.SetCenter(pos);
	Bounding.SetExtent(Extent);
	cube.Set(Extent);
	baseShape = Shape_Cube;
	Quath rZ; rZ.Set(Vector3h(0,0,1),rotation.z);
	Quath rY; rY.Set(Vector3h(0,1,0),rotation.y);
	Quath rX; rX.Set(Vector3h(1,0,0),rotation.x);
	this->rotation = rZ;
	this->rotation *= rY;
	this->rotation *= rX;
	this->rotation.Normalize();
	
	Vector3h iner= Extent*2;
	float xx = iner.x * iner.x;
	float yy = iner.y * iner.y;
	float zz = iner.z * iner.z;
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
bool CollisionCube::ProcessColliding(CollisionObject* b,Vector3h& CollisionNormal, float& penetration,Vector3h* CollisionPoint,int& numHit)
{
	Vector3h point;
	bool result=false;
	if(b->GetShape() == Cube)
	{
		CollisionCube* temp = (CollisionCube*)b;
		result=temp->Bounding.ComputeCollision(this->Bounding,CollisionNormal,penetration,CollisionPoint,numHit) ;
	
		temp->SetColorFace(0,1,0,0);
		this->SetColorFace(0,1,0,0);
		
		
	}
	else if(b->GetShape() == Sphere)
	{
		Vector3h point;
		CollisionSphere* temp = (CollisionSphere*)b;
		result = this->Bounding.ComputeCollision(temp->Bounding,CollisionNormal,penetration,point);
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
void CollisionCube::Update(float dt)
{
	Rigidbody::Update(dt);
	Bounding.SetAxis(this->rot.GetCol(0),this->rot.GetCol(1),this->rot.GetCol(2));
	Bounding.SetCenter(this->GetPosition());
	cube.Set(this->matWorld);
	
}

void CollisionCube::Render()
{
	cube.Set(this->matWorld);
	cube.Render();
}