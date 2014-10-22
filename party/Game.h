#ifndef GAME_H
#define GAME_H
#include "Clock.h"
#include "Displayer.h"
#include "EventHandler.h"
class Create;
class Clock;
class Render;
class EventHandler;
class Game
{
public:
	static Game*  mGame;         
    
    Clock*        mClock;         
    Displayer*      mDisplay;      
    EventHandler* mEventHandler;
    
    bool mQuit;
    bool mPaused;
public:
	Game();
	virtual ~Game();
	static bool Create();
	static void Destroy();
	
	void Update();
	void Display();
	virtual void UpdateObjects( float dt ) = 0;
    virtual void Render() = 0;
	bool Initialize( int argc, char* argv[] );
	inline void Quit()          { mQuit = true; }
    inline bool IsRunning()     { return !mQuit; }
};

#endif // GAME_H
