#include "CSphere.h"

CSphere::CSphere()
{
	
}
CSphere::~CSphere()
{
}
void CSphere::Render(Vector3h pos,float mRedius)
{
	glPushMatrix();
		glLoadIdentity();
		gluLookAt(20,10,10,0,0,0,0,0,1);
		glColor3f(0.5,0.1,0);
		glTranslatef(pos.x,pos.y,pos.z);
		glutSolidSphere( mRedius, 24, 12 );
	glPopMatrix();
	glFlush();
	
	 
}


