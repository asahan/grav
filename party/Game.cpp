#include "Game.h"
#include "gl/glut.h"
#include "Clock.h"
#include "Displayer.h"
#include "EventHandler.h"
Game* Game::mGame = 0;
Game::Game()
{
	mClock=0;
	mEventHandler=0;
	mDisplay=0;
	mGame=this;
	mPaused=false,
    mQuit=false;
}

Game::~Game()
{
	mGame = 0;
    
    if (mEventHandler)
    {
        delete mEventHandler;
        mEventHandler = 0;
    }

    if (mDisplay)
    {
        delete mDisplay;
        mDisplay = 0;
    }

    if (mClock)
    {
        delete mClock;
        mClock = 0;
    }
}
void Game::Destroy()
{
	delete mGame;
}

bool Game::Initialize( int argc, char* argv[] )
{
    mClock = new Clock;
    if ( !mClock )
        return false;

    mClock->Update();
        
    mDisplay = new Displayer();
    if (!mDisplay || !mDisplay->Initialize( 640, 480 ))
        return false;
    
   
    mEventHandler = new EventHandler;
    if (!mEventHandler)
        return false;
    
    
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    
    return true;
    
}
void Game::Display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    Render();
    mDisplay->SwapBuffers();
}
void Game::Update()
{
	 if ( mQuit )
    {
        Game::Destroy();
        exit(0);
    }

    
    if (mEventHandler->IsKeyDown(27))
        Quit();

    
    mClock->Update();

    
    if ( !mPaused )
        UpdateObjects( mClock->GetElapsedTime() );
    
   
    if ( mDisplay->IsActive() )
    {
        Display();
    }
	
}