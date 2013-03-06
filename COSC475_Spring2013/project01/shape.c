//#include <GL/glut.h>

//void myinit()
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0); //white background
//	glColor3f(1.0, 0.0, 0.0); //Draw in Red
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
//	glMatrixMode(GL_MODELVIEW);
//
//}

//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	glBegin(GL_TRIANGLE_FAN);
//		glVertex2f(150.0,150.0); //center
//		glVertex2f(200.0,150.0);
//		glVertex2f(150.0,200.0);
//		glVertex2f(100.0,150.0);
//		glVertex2f(150.0,100.0);
//		glVertex2f(200.0,150.0);
//	glEnd();
//
//	glFlush();
//
//}

//void main(int argc, char** argv)
//{
//	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500,500);
//	glutInitWindowPosition(0,0);
//	glutCreateWindow("Diamond");
//	glutDisplayFunc(display);
//
//
//	myinit();
//
//	glutMainLoop();
//}
