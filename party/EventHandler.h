#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

class EventHandler
{
	bool mKeys[256];          
    bool mMouseDown;
    unsigned int mMouseX;
    unsigned int mMouseY;
public:
	EventHandler();
	~EventHandler();
	void KeyDown( unsigned char key ); 
    void KeyUp( unsigned char key );    
    void MouseDown( unsigned int h, unsigned int v );   
    void MouseUp(); 
	bool IsKeyDown( unsigned char key );
};

#endif // EVENTHANDLER_H
