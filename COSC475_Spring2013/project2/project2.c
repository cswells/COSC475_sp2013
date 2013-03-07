#include <GL/glut.h>

void DrawMyPyramid(float x, float y, float z, float s);
void DrawMyCube(float x, float y, float z, float s);
void myCube();

static float angle = 0.00;

//MyColors
static GLfloat cyan[]=	{	0.0,	0.8,	0.8	};
static GLfloat aqua[]=	{	0.0,	1.0,	1.0	};
static GLfloat black[]=	{	0.0,	0.0,	0.0	};
static GLfloat blue[]=	{	0.0,	0.0,	1.0	};
static GLfloat fuchsia[]={	1.0,	0.0,	1.0	};
static GLfloat gray[]=	{	0.5,	0.5,	0.5	};
static GLfloat green[]=	{	0.0,	0.5,	0.0	};
static GLfloat lime[]=	{	0.0,	1.0,	0.0	};
static GLfloat maroon[]={	0.5,	0.0,	0.0	};
static GLfloat navyBlue[]={	0.0,	0.0,	0.5	};
static GLfloat olive[]=	{	0.5,	0.5,	0.0	};
static GLfloat purple[]={	0.5,	0.0,	0.5	};
static GLfloat red[]=	{	1.0,	0.0,	0.0	};
static GLfloat silver[]={	0.75,	0.75,	0.75};
static GLfloat teal[]=	{	0.0,	0.5,	0.5	};
static GLfloat white[]=	{	1.0,	1.0,	1.0	};
static GLfloat yellow[]={	1.0,	1.0,	0.0	};

//end MyColors
void myinit()
{
	glClearColor(black[0],black[1],black[2],1.0); //Black background


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300.0,300.0,-300.0,300.0,-300.0,300.0);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	float silverLight[] = {silver[0],silver[1],silver[2],1};

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_SPECULAR, silverLight);
	glLightfv(GL_LIGHT2, GL_AMBIENT, silverLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, silverLight);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);




}


void display()
{
	glTranslatef(0.0f,0.0f,-5.0f);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

	float x = 100.0;
	float y = 100.0;
	float z = 100.0;
	float s = 100.0;
	angle += 0.01;
	glRotatef(angle, 1, 0, 0 );
	glRotatef(angle, 0, 1, 0);
	DrawMyPyramid(x,y,z,s);

	glRotatef(angle*2, 1, 0, 0 );
	glRotatef(angle*1.5, 0, 0, 1);
	myCube();



	glutPostRedisplay();
	glFlush();

}
void DrawMyPyramid(float x, float y, float z, float s)
{
	glBegin(GL_TRIANGLE_STRIP);
		//FRONT
		glColor3fv(blue);
		glVertex3f(x+(s/2),	y+s,z-(s/2)); 	//peak
		glVertex3f(x, y, z);				//front-lower-left
		glVertex3f(x+s,	y,	z);				//front-lower-right
		//RIGHT
		glColor3fv(green);
		glVertex3f(x+s,	y,	z);				//front-lower-right
		glVertex3f(x+s,	y,	z-s);			//back-lower-right
		glVertex3f(x+(s/2),	y+s,z-(s/2)); 	//peak
		//BACK
		glColor3fv(silver);
		glVertex3f(x+(s/2),	y+s,z-(s/2)); 	//peak
		glVertex3f(x+s,	y,	z-s);			//back-lower-right
		glVertex3f(x,	y,	z-s);			//back-lower-left
		//LEFT
		glColor3fv(red);
		glVertex3f(x,	y,	z-s);			//back-lower-left
		glVertex3f(x+(s/2),	y+s,z-(s/2)); 	//peak
		glVertex3f(x, y, z);				//front-lower-left
		//BOTTOM
		glColor3fv(yellow);
		glVertex3f(x, y, z);				//front-lower-left
		glVertex3f(x+s,	y,	z);				//front-lower-right
		glVertex3f(x+s,	y,	z-s);			//back-lower-right
		glVertex3f(x+s,	y,	z-s);			//back-lower-right
		glVertex3f(x,	y,	z-s);			//back-lower-left
		glVertex3f(x, y, z);				//front-lower-left

	glEnd();
}

void DrawMyCube(float x, float y, float z, float s)
{

		//FRONT
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glColor3fv(red);
		glVertex3f(x, y, z);
		glVertex3f(x+s, y, z);
		glVertex3f(x+s,	y+s, z);
		glVertex3f(x, y+s, z);
	glEnd();
		//BOTTOM
	glBegin(GL_QUADS);
		glNormal3d(0,-1,0);
		glColor3fv(blue);
		glVertex3f(x, y, z);
		glVertex3f(x+s, y, z);
		glVertex3f(x+s, y, z-s);
		glVertex3f(x, y, z-s);
	glEnd();
		//BACK
	glBegin(GL_QUADS);
		glNormal3d(0,0,-1);
		glColor3fv(navyBlue);
		glVertex3f(x, y, z-s);
		glVertex3f(x+s, y, z-s);
		glVertex3f(x+s,	y+s, z-s);
		glVertex3f(x, y+s, z-s);
	glEnd();
		//LEFT
	glBegin(GL_QUADS);
		glNormal3d(-1,0,0);
		glColor3fv(green);
		glVertex3f(x, y, z);
		glVertex3f(x, y+s, z);
		glVertex3f(x, y+s, z-s);
		glVertex3f(x, y, z-s);
	glEnd();
		//TOP
	glBegin(GL_QUADS);
		glNormal3d(0,1,0);
		glColor3fv(fuchsia);
		glVertex3f(x, y+s, z);
		glVertex3f(x+s, y+s, z);
		glVertex3f(x+s, y+s, z-s);
		glVertex3f(x, y+s, z-s);
	glEnd();
		//RIGHT
	glBegin(GL_QUADS);
		glNormal3d(1,0,0);
		glColor3fv(lime);
		glVertex3f(x+s, y, z);
		glVertex3f(x+s, y+s, z);
		glVertex3f(x+s, y+s, z-s);
		glVertex3f(x+s, y, z-s);
	glEnd();
}

void myCube()
{
glBegin(GL_QUADS);
	//FRONT
	glColor3fv(blue);
	glNormal3d(0,0,1);
	glVertex3f(-50.0f, -50.0f, 0.0f); //front-bottom-left
	glVertex3f(-50.0f, 50.0f, 0.0f); //front-top-left
	glVertex3f(50.0f, 50.0f, 0.0f); //front-top-right
	glVertex3f(50.0f, -50.0f, 0.0f); //front-bottom-right
	//BACK
	glColor3fv(red);
	glNormal3d(0,0,-1);
	glVertex3f(-50.0f, -50.0f, 100.0f);//back-bottom-left
	glVertex3f(-50.0f, 50.0f, 100.0f);//back-top-left
	glVertex3f(50.0f, 50.0f, 100.0f); //back-top-right
	glVertex3f(50.0f, -50.0f, 100.0f);//back-bottom-right
	//LEFT
	glColor3fv(green);
	glNormal3d(-1,0,0);
	glVertex3f(-50.0f, -50.0f, 0.0f); //front-bottom-left
	glVertex3f(-50.0f, -50.0f, 100.0f);//back-bottom-left
	glVertex3f(-50.0f, 50.0f, 100.0f);//back-top-left
	glVertex3f(-50.0f, 50.0f, 0.0f); //front-top-left
	//RIGHT
	glColor3fv(purple);
	glNormal3d(1,0,0);
	glVertex3f(50.0f, 50.0f, 0.0f); //front-top-right
	glVertex3f(50.0f, 50.0f, 100.0f); //back-top-right
	glVertex3f(50.0f, -50.0f, 100.0f);//back-bottom-right
	glVertex3f(50.0f, -50.0f, 0.0f); //front-bottom-right
	//BOTTOM
	glColor3fv(silver);
	glNormal3d(0,-1,0);
	glVertex3f(-50.0f, -50.0f, 0.0f); //front-bottom-left
	glVertex3f(-50.0f, -50.0f, 100.0f);//back-bottom-left
	glVertex3f(50.0f, -50.0f, 100.0f);//back-bottom-right
	glVertex3f(50.0f, -50.0f, 0.0f); //front-bottom-right
	//TOP
	glColor3fv(cyan);
	glNormal3d(0,1,0);
	glVertex3f(-50.0f, 50.0f, 0.0f); //front-top-left
	glVertex3f(-50.0f, 50.0f, 100.0f);//back-top-left
	glVertex3f(50.0f, 50.0f, 100.0f); //back-top-right
	glVertex3f(50.0f, 50.0f, 0.0f); //front-top-right
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
