#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include "CollisionSphere.h"
#include "CPlane.h"
#include "Vector3h.h"
#include <vector>
using namespace std;

struct Contact
{
	Vector3h Contactpoint;
	Vector3h Normal;
	float penetration;
};
struct CollisionPoint
{
	Rigidbody *Sphere0;
	Rigidbody *Sphere1;
	std::vector<Contact> contact;
};

class CollisionHandler
{
	vector<CollisionPoint*> *Collisions;
public:
	
	CollisionHandler();
	~CollisionHandler();
	void Clear();
	void AddCollision(Rigidbody *sp0,Rigidbody *sp1,Vector3h point, float penetration,Vector3h normal);
	void Response(float dt);
	bool HandleCollision(CollisionSphere* sphere0,CollisionSphere* sphere1, Vector3h& CollisionNormal, float& penetration,Vector3h* CollisionPoint,int& numHit);
	bool HandleCollision(CollisionCube* cube,CollisionSphere* sphere, Vector3h& CollisionNormal, float& penetration,Vector3h* CollisionPoint,int& numHit);
	bool HandleCollision(CollisionCube* cube0,CollisionCube* cube1, Vector3h& CollisionNormal, float& penetration, Vector3h* CollisionPoint,int& numHit);

};

#endif // COLLISIONHANDLER_H
