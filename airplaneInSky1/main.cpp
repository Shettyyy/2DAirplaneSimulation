#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
GLfloat k=0,l=0;
void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
	glutPostRedisplay();
}
void update(int value)
{
	k+=2;
	l-=50;
    if(l<=-200)
		l=300;
    if(k>=500)
        k=0;
	glutPostRedisplay();
	glutTimerFunc(100,update,0);
}
void cloudBehindAirplane(){

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(l,0,0);
glBegin(GL_POLYGON);
glVertex2f(209,400);
glVertex2f(228,375);
glVertex2f(285,350);
glVertex2f(304,375);
glVertex2f(342,350);
glVertex2f(399,387.5);
glVertex2f(361,450);
glVertex2f(323,425);
glVertex2f(266,450);
glVertex2f(228,425);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.929,0.965,0.976);
glTranslatef(l,0,0);
glBegin(GL_POLYGON);
glVertex2f(9,300);
glVertex2f(28,275);
glVertex2f(85,250);
glVertex2f(104,275);
glVertex2f(142,250);
glVertex2f(199,287.5);
glVertex2f(161,350);
glVertex2f(123,325);
glVertex2f(66,350);
glVertex2f(28,325);
glEnd();
//glFlush();
glPopMatrix();

}
void cloudFrontAirplane(){

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(l,0,0);
glBegin(GL_POLYGON);
glVertex2f(-19,0);
glVertex2f(0,25);
glVertex2f(19,50);
glVertex2f(76,25);
glVertex2f(95,100);
glVertex2f(152,75);
glVertex2f(190,25);
glVertex2f(209,25);
glVertex2f(228,0);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.929,0.965,0.976);
glTranslatef(l,0,0);
glBegin(GL_POLYGON);
glVertex2f(266,100);
glVertex2f(266,75);
glVertex2f(285,50);
glVertex2f(323,75);
glVertex2f(399,25);
glVertex2f(437,50);
glVertex2f(500,50);
glVertex2f(535,75);
glVertex2f(500,190);
glVertex2f(475,210);
glVertex2f(456,200);
glVertex2f(418,175);
glVertex2f(409,200);
glVertex2f(382,220);
glVertex2f(365,210);
glVertex2f(350,200);
glVertex2f(342,210);
glVertex2f(323,175);
glVertex2f(304,150);
glVertex2f(304,125);
glEnd();
//glFlush();
glPopMatrix();

}
void display(void)
{

glClear(GL_COLOR_BUFFER_BIT);

//sky
glColor3f(0.565,0.878,0.937);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(500,0);
glVertex2f(500,500);
glVertex2f(0,500);
glEnd();
//glFlush();

cloudBehindAirplane();

//airplane
glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(k,0,0);
glBegin(GL_POLYGON);
glVertex2f(76,300);
glVertex2f(95,250);
glVertex2f(133,250);
glVertex2f(95,300);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(k,0,0);
glBegin(GL_POLYGON);
glVertex2f(19,275);
glVertex2f(19,225);
glVertex2f(171,225);
glVertex2f(190,237.5);
glVertex2f(181,250);
glVertex2f(152,275);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(k,0,0);
glBegin(GL_POLYGON);
glVertex2f(152,237.5);
glVertex2f(152,225);
glVertex2f(171,225);
glVertex2f(190,237.5);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(k,0,0);
glBegin(GL_POLYGON);
glVertex2f(95,250);
glVertex2f(76,200);
glVertex2f(95,200);
glVertex2f(133,250);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(k,0,0);
glBegin(GL_POLYGON);
glVertex2f(19,325);
glVertex2f(19,275);
glVertex2f(76,275);
glVertex2f(38,325);
glEnd();
//glFlush();
glPopMatrix();

cloudFrontAirplane();

glFlush();

}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Airplane in sky");
	glutDisplayFunc(display);
	init();
	glutTimerFunc(100,update,0);
	glutMainLoop();
}
