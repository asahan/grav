#include <stdio.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include "Game.h"
#include "Vector3h.h"


void KeyboardDown(unsigned char key, int,int)
{
	Game::mGame->mEventHandler->KeyDown(key);
}
void KeyboardUp(unsigned char key, int,int)
{
	Game::mGame->mEventHandler->KeyUp(key);
}
void Mouse(int Button,int state,int x,int y)
{
	
}
void Display()
{
	Game::mGame->Display();
}
void idle()
{
	Game::mGame->Update();
	glutPostRedisplay();
	
}
int main(int argc, char* argv[])
{
	glutInit(&argc,argv);

	glutInitWindowPosition (70, 70);

	if(!Game::Create() || !Game::mGame->Initialize(argc,argv))
		return 0;
	
	
	glutDisplayFunc(Display);
	glutKeyboardFunc(KeyboardDown);
	glutKeyboardUpFunc(KeyboardUp);
	glutMouseFunc(Mouse);
	glutIdleFunc(idle);
	
	glutMainLoop();
	
	//printf("hello world\n");
	return 0;
}
