#include <GL/glut.h>

void DrawMyPyramid(float x, float y, float z, float s);
void DrawMyCube(float x, float y, float z, float s);
static float angle = 0.00;
void myinit()
{
	glClearColor(0, 0, 0, 1.0); //Black background
	glColor3f(1.0, 0.0, 0.0); //Draw in Red

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300.0,300.0,-300.0,300.0,300.0,-300.0);
	glMatrixMode(GL_MODELVIEW);

}


void display()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	float x = 100.0;
	float y = 100.0;
	float z = 100.0;
	float s = 100.0;
	angle += 0.01;
	glRotatef(angle, 0.5, 0, 0 );
	glRotatef(angle, 0, 0.5, 0 );
	DrawMyPyramid(x,y,z,s);

	float x2 = -100.0;
	float y2 = -100.0;
	float z2 = -100.0;
	float s2 = 100.0;
	glRotatef(angle, 0, 0.5, 0 );
	glRotatef(angle, 0.5, 0, 0 );
	DrawMyCube(x2,y2,z2,s2);



	glutPostRedisplay();
	glFlush();

}
void DrawMyPyramid(float x, float y, float z, float s)
{
	glBegin(GL_TRIANGLE_FAN);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(x+(s/2),	y+s,	z-(s/2));
			glVertex3f(x, y, z);
			glVertex3f(x+s,	y,	z);
			glVertex3f(x+s,	y,	z-s);
			glVertex3f(x,	y,	z-s);
			glVertex3f(x, y, z);
	glEnd();
}

void DrawMyCube(float x, float y, float z, float s)
{
	glBegin(GL_QUADS);
		//FRONT
		glColor3f(0.0, 0.5, 0.5);
		glVertex3f(x, y, z);
		glVertex3f(x, y+s, z);
		glVertex3f(x+s,	y+s, z);
		glVertex3f(x, y+s, z);
		//BOTTOM
		glColor3f(0.5, 0.0, 0.0);
		glVertex3f(x, y, z);
		glVertex3f(x+s, y, z);
		glVertex3f(x+s, y, z-s);
		glVertex3f(x, y, z-s);
		//BACK
		glColor3f(5.0, 0.0, 0.5);
		glVertex3f(x, y, z-s);
		glVertex3f(x, y+s, z-s);
		glVertex3f(x+s,	y+s, z-s);
		glVertex3f(x, y+s, z-s);
		//TOP
		glColor3f(0.0, 0.0, 0.5);
		glVertex3f(x, y+s, z);
		glVertex3f(x+s, y+s, z);
		glVertex3f(x+s, y+s, z-s);
		glVertex3f(x, y+s, z-s);
		//LEFT
		glColor3f(0.5, 0.5, 0.0);
		glVertex3f(x, y, z);
		glVertex3f(x, y+s, z);
		glVertex3f(x, y+s, z-s);
		glVertex3f(x, y, z-s);
		//RIGHT
		glColor3f(0.5, 1.0, 0.0);
		glVertex3f(x+s, y, z);
		glVertex3f(x+s, y+s, z);
		glVertex3f(x+s, y+s, z-s);
		glVertex3f(x+s, y, z-s);

	glEnd();
}

void main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Diamond");
	glutDisplayFunc(display);


	myinit();

	glutMainLoop();
}
