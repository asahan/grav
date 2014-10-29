#include "CCube.h"

CCube::CCube()
{  
	Extent = Vector3h(1,1,1);
	top[0]=top[1]=top[2]=0.96;
	bottom[0]=bottom[1]=bottom[2]=0.16;
	left[0]=left[1]=left[2]=0.32;
	right[0]=right[1]=right[2]=0.48;
	front[0]=front[1]=front[2]=0.64;
	back[0]=back[1]=back[2]=0.80;
}
CCube::~CCube()
{
}
void CCube::Render()
{
	glPushMatrix();
		glLoadIdentity();
		glMultMatrixf(mat.index);
		glBegin(GL_QUADS);
    
		glColor3f(top[0],top[1],top[2]);
		glVertex3f(Extent.x, Extent.y, Extent.z);
		glVertex3f(-Extent.x, Extent.y, Extent.z);
		glVertex3f(-Extent.x, -Extent.y, Extent.z);
		glVertex3f(Extent.x, -Extent.y, Extent.z);

   
		glColor3f(bottom[0],bottom[1],bottom[2]);
		glVertex3f(Extent.x, Extent.y, -Extent.z);
		glVertex3f(Extent.x, -Extent.y, -Extent.z);
		glVertex3f(-Extent.x, -Extent.y, -Extent.z);
		glVertex3f(-Extent.x, Extent.y, -Extent.z);

   
		glColor3f(left[0],left[1],left[2]);
		glVertex3f(Extent.x, Extent.y, Extent.z);
		glVertex3f(Extent.x, Extent.y, -Extent.z);
		glVertex3f(-Extent.x, Extent.y, -Extent.z);
		glVertex3f(-Extent.x, Extent.y, Extent.z);

    
		glColor3f(right[0],right[1],right[2]);
		glVertex3f(Extent.x, -Extent.y, Extent.z);
		glVertex3f(-Extent.x, -Extent.y, Extent.z);
		glVertex3f(-Extent.x, -Extent.y, -Extent.z);
		glVertex3f(Extent.x, -Extent.y, -Extent.z);

   
		glColor3f(front[0],front[1],front[2]);
		glVertex3f(Extent.x, Extent.y, Extent.z);
		glVertex3f(Extent.x, -Extent.y, Extent.z);
		glVertex3f(Extent.x, -Extent.y, -Extent.z);
		glVertex3f(Extent.x, Extent.y, -Extent.z);

    
		glColor3f(back[0],back[1],back[2]);
		glVertex3f(-Extent.x, Extent.y, Extent.z);
		glVertex3f(-Extent.x, Extent.y, -Extent.z);
		glVertex3f(-Extent.x, -Extent.y, -Extent.z);
		glVertex3f(-Extent.x, -Extent.y, Extent.z);

    
		glEnd();
		glPopMatrix();
	
	glFlush();
	
}

	
