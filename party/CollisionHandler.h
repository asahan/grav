#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include "CollisionSphere.h"
#include "Vector3h.h"
#include <vector>
using namespace std;

struct Contact
{
	Vector3h Objectpos0;
	Vector3h Objectpos1;
	Vector3h Contactpoint;
	Vector3h Normal;
	float penetration;
};
struct CollisionPoints
{
	CollisionSphere *Sphere0;
	CollisionSphere *Sphere1;
	vector<Contact> contacts;
};
class CollisionHandler
{
	
	vector<CollisionPoints*> *Collisions;
public:
	
	CollisionHandler();
	~CollisionHandler();
	void Clear();
	void AddCollision(CollisionSphere *sp0,CollisionSphere *sp1,Vector3h point, float penetration,Vector3h normal);

};

#endif // COLLISIONHANDLER_H
