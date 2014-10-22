#include "CPlane.h"
#include "gl/gl.h"
CPlane::CPlane()
{
	normal=Vector3h(0,0,1);
	vertex[0]=Vector3h(-10,-10,-10);
	vertex[1]=Vector3h(-10,10,-10);
	vertex[2]=Vector3h(10,-10,0);
	vertex[3]=Vector3h(10,10,0);
	Center=Vector3h(0,0,0);
	box.Set(vertex,4);
}

CPlane::~CPlane()
{
}

void CPlane::Render()
{	
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(4,4,4,0,0,0,0,0,1);
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<4;i++){
		glVertex3f(vertex[i].x,vertex[i].y,vertex[i].z);
	}
	
   glEnd();
   glPopMatrix();
   glFlush();
	
}