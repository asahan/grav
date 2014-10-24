#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector3h.h"
#include "Matrix3h.h"
class Rigidbody
{
public:
	float       mMass;
	Vector3h Translate;
	Vector3h Velocity;
	Vector3h Gravity;
	Vector3h Force;
	
	Matrix3h MomentInverse;
	Matrix3h WorldMomentInverse;
	
	Vector3h AngVelocity;
	Vector3h Angmoment;
	Vector3h Torque;
	
	float Elasticity;
public:
	Rigidbody();
	~Rigidbody();
	inline void SetPosition( const Vector3h pos) { Translate = pos; }
	inline Vector3h GetPosition() { return Translate; }
	inline void SetMass(float mass) { mMass = mass; }
	inline float GetMass() { return mMass; }
	inline float GetInvMass() { return 1/mMass; }
	void Update(float dt);
	inline void SetVelocity(Vector3h vec) { Velocity = vec; }
	inline Vector3h GetVelocity() { return Velocity; }
	inline void SetGravity(Vector3h grav) { Gravity =  grav; }
	inline void SetElasticity(float e) { Elasticity =e; }
	inline float GetElastictity() { return Elasticity;}
	inline void SetAngVelocity(Vector3h ang) { AngVelocity = ang; }
	inline Vector3h GetAngVelocity() { return AngVelocity; }
	
	
	
		

};

#endif // RIGIDBODY_H
