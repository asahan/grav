#include "EventHandler.h"
#include "string.h"
#include "ctype.h"
EventHandler::EventHandler()
{
	memset(mKeys, 0, sizeof(bool)*256);
	mMouseX = 0;  mMouseY = 0;
    mMouseDown = false;
}

EventHandler::~EventHandler()
{
}

void EventHandler::KeyDown( unsigned char key )
{
	if(isupper(key))
		tolower(key);
	mKeys[key] = true; 
	
}
void EventHandler::KeyUp( unsigned char key )
{
	mKeys[key] = false; 
}
void EventHandler::MouseDown( unsigned int h, unsigned int v )
{
	mMouseDown =true;
	mMouseX=h; mMouseY=v;
}   
void EventHandler::MouseUp()
{
	mMouseDown = false;
}
bool EventHandler::IsKeyDown( unsigned char key )
{
	return mKeys[key];
}