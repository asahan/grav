#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
	float   mCurrentTime;
    float   mElapsedTime;
public:
	Clock();
	~Clock();
	unsigned int GetTicks();
    
    
    void Update();
    
    
    inline float    GetCurrentTime()    { return mCurrentTime; }
    inline float    GetElapsedTime()    { return mElapsedTime; }

};

#endif // CLOCK_H
