#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	
}

Rigidbody::~Rigidbody()
{
}



void Update(float dt)
{
	//Runge-Kutta 4 method
	//h=dt
	//k1 = f(xn,yn)
	//k2 = f(xn + h/2, yn+ h/2*k1)
	//k3 = f(xn + h/2, yn + h/2*k2)
	//k4 = f(xn + h, yn + hk3)
	//yn+1 = yn + h/6(k1 + 2*k2 + 2*k3 + k4)
	
}