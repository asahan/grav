#include "CPlane.h"
#include "gl/gl.h"
CPlane::CPlane()
{
	normal=Vector3h(0,0,1);
	vertex[0]=Vector3h(-10,-10,0);
	vertex[1]=Vector3h(10,-10,0);
	vertex[2]=Vector3h(10,10,0);
	vertex[3]=Vector3h(-10,10,0);
	vertex[4]=Vector3h(-10,10,-10);
	vertex[5]=Vector3h(-10,10,-10);
	vertex[6]=Vector3h(-10,10,-10);
	vertex[7]=Vector3h(-10,10,-10);
	Center=Vector3h(0,0,0);
	box.Set(vertex,8);
}

CPlane::~CPlane()
{
}

void CPlane::Render()
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