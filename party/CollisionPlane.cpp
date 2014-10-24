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
bool CollisionPlane::HandleCollision(CollisionSphere* other, Vector3h& CollisionNormal, float& penetration, Vector3h& CollisionPoint)
{
	if(box.ComputeCollision(other->Bounding, CollisionNormal,penetration,CollisionPoint) == true)
	{
		Vector3h pos = other->GetPosition();
		pos+=CollisionNormal*penetration;
		other->SetPosition(pos);
		return true;
	}
	return false;
}
void CollisionPlane::Render()
{
	Vector3h ver[4];
	for(int i=0;i<4;i++)
		ver[i]=vertex[i];
	plain.Render(ver);
}
