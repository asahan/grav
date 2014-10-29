#include "Clock.h"
#include "gl/glut.h"
Clock::Clock()
{
	 mCurrentTime=0.0f,
     mElapsedTime=0.0f;
}

Clock::~Clock()
{
}

unsigned int Clock::GetTicks()
{
	return glutGet(GLUT_ELAPSED_TIME);
}
    
    
void Clock::Update()
{
	float newTime = ((float)GetTicks())*0.0001f;
    mElapsedTime = newTime - mCurrentTime;
    mCurrentTime = newTime;
}