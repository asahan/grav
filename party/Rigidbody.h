#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector3h.h"
#include "Matrix3h.h"
#include "Quath.h"
class Rigidbody
{
public:
	float       mMass;
	Vector3h pos;
	Vector3h Velocity;
	Vector3h Gravity;
	Vector3h Force;
	
	Quath rotation;
	Matrix3h rot;
	Matrix3h inertia;
	Matrix3h invinertia;
	
	
	
	Vector3h AngVelocity;
	Vector3h Angmoment;
	Vector3h Torque;
	
	float Elasticity;
public:
	Rigidbody();
	~Rigidbody();
	inline void SetPosition( const Vector3h pos) { this->pos = pos; }
	inline Vector3h GetPosition() { return pos; }
	inline void SetMass(float mass) { mMass = mass; }
	inline float GetMass() { return mMass; }
	inline float GetInvMass() { if(mMass != 0 )return 1/mMass; else return 0; }
	virtual void Update(float dt);
	inline void SetVelocity(Vector3h vec) { Velocity = vec; }
	inline Vector3h GetVelocity() { return Velocity; }
	inline void SetGravity(Vector3h grav) { Gravity =  grav; }
	inline void SetElasticity(float e) { Elasticity =e; }
	inline float GetElastictity() { return Elasticity;}
	inline void SetAngVelocity(Vector3h ang) { AngVelocity = ang; }
	inline Vector3h GetAngVelocity() { return AngVelocity; }
	inline void SetLocalinertia(const Matrix3h& inertia ){ this->inertia = inertia; invinertia = this->inertia.Inverse();}
	inline Matrix3h GetLocalInertia() { return inertia; }
	inline Matrix3h GetWorldInertia() { return (rot*inertia*Transpose(rot)); }
	inline Matrix3h GetinverseInertia() { return invinertia; }
	inline Matrix3h GetinverseWorldInertia(){ return (rot*invinertia*Transpose(rot));}
	

};

#endif // RIGIDBODY_H
