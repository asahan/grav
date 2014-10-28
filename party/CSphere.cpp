#include "CSphere.h"

CSphere::CSphere()
{
	Color[0]=0.5;
	Color[1]=0.1;
	Color[2]=0;
}
CSphere::~CSphere()
{
}
void CSphere::SetColor(float r,float g,float b)
{
	Color[0]=r;
	Color[1]=g;
	Color[2]=b;
}
void CSphere::Render()
{
	glPushMatrix();
		glLoadIdentity();
		gluLookAt(20,10,10,0,0,0,0,0,1);
		glColor3f(Color[0],Color[1],Color[2]);
		glTranslatef(pos.x,pos.y,pos.z);
		glutSolidSphere( mRedius, 24, 12 );
	glPopMatrix();
	glFlush();
	
	 
}


