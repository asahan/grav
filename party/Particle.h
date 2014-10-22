#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3h.h"
class Particle
{
public:
	Vector3h pos,linvel,acc;
	
public:
	Particle(Vector3h pos,Vector3h linvel,Vector3h acc);
	~Particle();

};

#endif // PARTICLE_H
