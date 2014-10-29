#include "Displayer.h"
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "stdlib.h"
Displayer::Displayer()
{
	mWidth = 0;
    mHeight = 0;
    mFullscreen = false;

    mFOV = 45.0f;
    mNear = 0.1f;
    mFar = 35.0f;
	mIsActive=true;
	
}

Displayer::~Displayer()
{
}
bool Displayer::Initialize( unsigned int  width, unsigned int  height, bool fullscreen )
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	if (fullscreen)
    {
        glutGameModeString("640x480:16@60");
        glutEnterGameMode();
    }
    else
    {
        glutInitWindowSize(width, height);
        glutCreateWindow("Cube Collision Example");
    }
    mFullscreen = fullscreen;

    //if (!InitGL())
       // return false;

   
    Resize( width, height );

    return true;
}
void Displayer::Resize( unsigned int width, unsigned int height )
{
	if (height == 0)                                    
    {
        height = 1;                                 
    }

   
    glViewport(0,0,width,height);                       
    mWidth = width;
    mHeight = height;

    
    glMatrixMode(GL_PROJECTION);                        
    glLoadIdentity();             
             
    gluPerspective(mFOV, (GLfloat)width/(GLfloat)height, mNear, mFar);
	gluLookAt(20,10,10,0,0,0,0,0,1);     
    glMatrixMode(GL_MODELVIEW);        
	                 
    glLoadIdentity(); 
	
   
}
void Displayer::SwapBuffers()
{
	glutSwapBuffers();
}
int Displayer::InitGL()    
{
	 glShadeModel(GL_SMOOTH);    
    
 
    glClearColor(0.0f, 0.0f, 0.35f, 0.5f);          
    glClearDepth(1.0f); 
    
    
    glEnable(GL_DEPTH_TEST);                            
    glDepthFunc(GL_LEQUAL); 
    

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  

  
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);

    return true;                
}
