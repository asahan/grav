#include "CollisionPlane.h"

CollisionPlane::CollisionPlane()
{
	normal=Vector3h(0,0,1);
	vertex[0]=Vector3h(-10,-10,0);
	vertex[1]=Vector3h(10,-10,0);
	vertex[2]=Vector3h(10,10,0);
	vertex[3]=Vector3h(-10,10,0);
	vertex[4]=Vector3h(-10,10,-10);
	vertex[5]=Vector3h(-10,10,-10);
	vertex[6]=Vector3h(-10,10,-10);
	vertex[7]=Vector3h(-10,10,-10);
	Center=Vector3h(0,0,0);
	box.Set(vertex,8);
	
}

CollisionPlane::~CollisionPlane()
{
}
bool CollisionPlane::HandleCollision(CollisionSphere* other, Vector3h& CollisionNormal, Vector3h& CollisionPoint)
{
	Vector3h otherpos = other->GetPosition();
	otherpos -= normal*(other->Bounding.GetRedius());
	float penetration = otherpos*(this->normal);

	if(penetration <= 0)
	{
		CollisionPoint = Vector3h(otherpos.x,otherpos.y,0);
		CollisionNormal = this->normal;
		penetration*=-1;
		otherpos = other->GetPosition() + this->normal*penetration;
		other->SetPosition(otherpos);
		return true;
	}
	
	return false;
}
bool CollisionPlane::HandleCollision(CollisionCube* other, Vector3h& CollisionNormal, Vector3h& CollisionPoint)
{
	Vector3h Collisionpoint=Vector3h(0,0,0);
	Vector3h otherpos;
	float num=0;
	for(int i=0; i<8; i++)
	{
		Vector3h position = other->Bounding.GetVertex(i);
		if(position*normal <= 0)
		{
			num++;
			Collisionpoint += position;
		}
	}
	if(num == 0)
		return false;
	else {
	Collisionpoint = Collisionpoint * (1/num);
	CollisionPoint = Vector3h(Collisionpoint.x,Collisionpoint.y,0);
	CollisionNormal = normal;
	float penetration = Collisionpoint*normal*-1;
	otherpos = other->GetPosition() + normal*penetration;
	
	other->SetPosition(otherpos);
	
	}
	
	
}
void CollisionPlane::Render()
{
	Vector3h ver[4];
	for(int i=0;i<4;i++)
		ver[i]=vertex[i];
	plain.Render(ver);
}
