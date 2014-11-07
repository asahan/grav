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
bool CollisionPlane::HandleCollision(CollisionSphere* other, Vector3h& CollisionNormal, Vector3h* CollisionPoint,int& numHit)
{
	Vector3h otherpos = other->GetPosition();
	otherpos -= normal*(other->Bounding.GetRedius());
	float penetration = otherpos*(this->normal);

	if(penetration <= 0)
	{
		numHit = 1;
		CollisionPoint[0] = Vector3h(otherpos.x,otherpos.y,0);
		CollisionNormal = this->normal;
		penetration*=-1;
		otherpos = other->GetPosition() + this->normal*penetration;
		other->SetPosition(otherpos);
		return true;
	}
	
	return false;
}
bool CollisionPlane::HandleCollision(CollisionCube* other, Vector3h& CollisionNormal, Vector3h* CollisionPoint,int& numHit)
{
	Vector3h otherpos;
	int num=0;
	float penetration=0;
	float Maxdepth=0;
	for(int i=0; i<8; i++)
	{
		Vector3h position = other->Bounding.GetVertex(i);
		penetration = position*normal;
		if(penetration <= 0)
		{
			CollisionPoint[num++]= position;
			if(penetration < Maxdepth)
				Maxdepth = penetration;
		}
	}
	if(num == 0)
		return false;
	else {
	numHit = num;
	
	CollisionNormal = normal;
	penetration = Maxdepth;
	otherpos = other->GetPosition() + normal*-penetration;
	
		
	
	other->SetPosition(otherpos);
	return true;
	
	}
	
	
}
void CollisionPlane::Render()
{
	Vector3h ver[4];
	for(int i=0;i<4;i++)
		ver[i]=vertex[i];
	plain.Render(ver);
}
