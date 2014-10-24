#include "CPlane.h"
#include "gl/gl.h"
CPlane::CPlane()
{
	
}

CPlane::~CPlane()
{
}

void CPlane::Render(Vector3h vertex[4])
{	
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(20,10,10,0,0,0,0,0,1);
	glColor3f(0.5,1,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<4;i++){
		glVertex3f(vertex[i].x,vertex[i].y,vertex[i].z);
	}
	
   glEnd();
   glPopMatrix();
   glFlush();
	
}