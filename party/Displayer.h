#ifndef DISPLAY_H
#define DISPLAY_H

class Displayer
{
	unsigned int mWidth;        
    unsigned int mHeight;
    bool         mFullscreen; 
    float        mFOV;
    float        mNear;
    float        mFar;
	bool         mIsActive;
public:
	Displayer();
	~Displayer();
	bool Initialize( unsigned int  width, unsigned int  height, bool fullscreen = false );
	void Resize( unsigned int width, unsigned int height );
    void SwapBuffers();
	int InitGL();    
	inline bool IsActive()   { return mIsActive; }
};

#endif // DISPLAY_H
