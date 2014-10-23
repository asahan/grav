#include "CRect.h"

CRect::CRect()
{
}
CRect::~CRect()
{
}
void CRect::Render(Vector3h min,Vector3h max)
{
	glBegin(GL_QUADS);

    
    glNormal3f(0.0f, 0.0f, 1.0f);
 
    glVertex3f(max.x, max.y, max.z);
    glVertex3f(min.x, max.y, max.z);
    glVertex3f(min.x, min.y, max.z);
    glVertex3f(max.x, min.y, max.z);

   
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(max.x, max.y, min.z);
    glVertex3f(max.x, min.y, min.z);
    glVertex3f(min.x, min.y, min.z);
    glVertex3f(min.x, max.y, min.z);

   
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(max.x, max.y, max.z);
    glVertex3f(max.x, max.y, min.z);
    glVertex3f(min.x, max.y, min.z);
    glVertex3f(min.x, max.y, max.z);

    
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(max.x, min.y, max.z);
    glVertex3f(min.x, min.y, max.z);
    glVertex3f(min.x, min.y, min.z);
    glVertex3f(max.x, min.y, min.z);

   
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(max.x, max.y, max.z);
    glVertex3f(max.x, min.y, max.z);
    glVertex3f(max.x, min.y, min.z);
    glVertex3f(max.x, max.y, min.z);

    
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(min.x, max.y, max.z);
    glVertex3f(min.x, max.y, min.z);
    glVertex3f(min.x, min.y, min.z);
    glVertex3f(min.x, min.y, max.z);

    
    glEnd();
	
}

	
