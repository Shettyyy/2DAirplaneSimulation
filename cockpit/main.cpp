#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
GLfloat m=0,n=0;
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
void update5(int value)
{
	m-=30;
	n+=30;
    if(m<-250){
        m=0;
        n=0;
    }
	glutPostRedisplay();
	glutTimerFunc(100,update,0);
}
void plotpixels(GLfloat h,GLfloat k, GLfloat x,GLfloat y)
{
    glBegin(GL_POINTS);
    glVertex2f(x+h,y+k);
    glVertex2f(-x+h,y+k);
    glVertex2f(x+h,-y+k);
    glVertex2f(-x+h,-y+k);
    glVertex2f(y+h,x+k);
    glVertex2f(-y+h,x+k);
    glVertex2f(y+h,-x+k);
    glVertex2f(-y+h,-x+k);
    glEnd();
    //glFlush();
}
void draw_circle(GLfloat h, GLfloat k, GLfloat r)
{
    GLfloat d=1-r, x=0, y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);
        if(d<0) d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}
void cloud_cockpit(){
//cloud 1
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(m,0,0);
glBegin(GL_POLYGON);
glVertex2f(0,325);
glVertex2f(19,350);
glVertex2f(57,325);
glVertex2f(76,350);
glVertex2f(95,325);
glVertex2f(95,300);
glVertex2f(76,275);
glVertex2f(133,300);
glVertex2f(152,275);
glVertex2f(133,250);
glVertex2f(152,250);
glVertex2f(171,225);
glVertex2f(190,250);
glVertex2f(209,225);
glVertex2f(209,200);
glVertex2f(228,225);
glVertex2f(247,225);
glVertex2f(266,200);
glVertex2f(266,0);
glVertex2f(0,0);
glEnd();
glPopMatrix();

//cloud2
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(n,0,0);
glBegin(GL_POLYGON);
glVertex2f(304,193);
glVertex2f(315,225);
glVertex2f(361,268);
glVertex2f(380,250);
glVertex2f(399,300);
glVertex2f(437,325);
glVertex2f(456,350);
glVertex2f(475,350);
glVertex2f(500,325);
glVertex2f(500,0);
glVertex2f(380,0);
glEnd();
glPopMatrix();
}
void human_cockpit(){
glColor3f(1,0.804,0.698);
for(int i=0;i<=22;i++){
draw_circle(105,175,i);
}

glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(82,150);
glVertex2f(80,205);
glVertex2f(125,210);
glVertex2f(128,200);
glVertex2f(90,190);
glVertex2f(105,150);
glEnd();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(95,150);
glVertex2f(76,125);
glVertex2f(133,125);
glVertex2f(114,150);
glEnd();

glColor3f(0.929,0.965,0.976);
glBegin(GL_POLYGON);
glVertex2f(66,137.5);
glVertex2f(57,125);
glVertex2f(57,25);
glVertex2f(133,25);
glVertex2f(152,100);
glVertex2f(152,137.5);
glEnd();

glColor3f(0.929,0.965,0.976);
glBegin(GL_POLYGON);
glVertex2f(152,137.5);
glVertex2f(133,100);
glVertex2f(171,50);
glVertex2f(190,75);
glEnd();

glColor3f(0.929,0.965,0.976);
glBegin(GL_POLYGON);
glVertex2f(177,75);
glVertex2f(177,50);
glVertex2f(209,75);
glVertex2f(209,100);
glEnd();

glColor3f(1,0.804,0.698);
glBegin(GL_POLYGON);
glVertex2f(220,110);
glVertex2f(209,100);
glVertex2f(209,75);
glVertex2f(228,85);
glEnd();

//human2
glColor3f(1,0.804,0.698);
for(int i=0;i<=22;i++){
draw_circle(385,175,i);
}

glColor3f(0.914,0.769,0.416);
glBegin(GL_POLYGON);
glVertex2f(407,150);
glVertex2f(395,150);
glVertex2f(390,190);
glVertex2f(361,200);
glVertex2f(368,210);
glVertex2f(415,205);
glEnd();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(380,150);
glVertex2f(361,125);
glVertex2f(418,125);
glVertex2f(399,150);
glEnd();

glColor3f(0.929,0.965,0.976);
glBegin(GL_POLYGON);
glVertex2f(418,137.5);
glVertex2f(437,125);
glVertex2f(437,0);
glVertex2f(361,0);
glVertex2f(342,100);
glVertex2f(342,137.5);
glEnd();

glColor3f(0.929,0.965,0.976);
glBegin(GL_POLYGON);
glVertex2f(342,137.5);
glVertex2f(342,100);
glVertex2f(323,50);
glVertex2f(304,75);
glEnd();


}
void cockpit(void)
{
glClear(GL_COLOR_BUFFER_BIT);

// ceiling part

glColor3f(0.114,0.208,0.341);
glBegin(GL_POLYGON);
glVertex2f(0,400);
glVertex2f(228,350);
glVertex2f(266,350);
glVertex2f(500,400);
glVertex2f(500,500);
glVertex2f(0,500);
glEnd();
//glFlush();

glColor3f(0.271,0.482,0.616);
glBegin(GL_POLYGON);
glVertex2f(0,407);
glVertex2f(247,357);
glVertex2f(500,407);
glVertex2f(500,500);
glVertex2f(0,500);
glEnd();

//here

//glFlush();

glColor3f(0,0.588,0.78);
glBegin(GL_POLYGON);
glVertex2f(158,493);
glVertex2f(171,382);
glVertex2f(243.5,368);
glVertex2f(243.5,493);
glEnd();
//glFlush();

glColor3f(0,0.588,0.78);
glBegin(GL_POLYGON);
glVertex2f(250.5,493);
glVertex2f(250.5,368);
glVertex2f(323,382);
glVertex2f(335,493);
glEnd();
//glFlush();

glColor3f(0,0.588,0.78);
glBegin(GL_POLYGON);
glVertex2f(76,493);
glVertex2f(95,400);
glVertex2f(164,383);
glVertex2f(152,493);
glEnd();
//glFlush();

glColor3f(0,0.588,0.78);
glBegin(GL_POLYGON);
glVertex2f(342,493);
glVertex2f(330,383);
glVertex2f(399,400);
glVertex2f(418,493);
glEnd();
//glFlush();

//window

glColor3f(0.565,0.878,0.937);
glBegin(GL_POLYGON);
glVertex2f(266,350);
glVertex2f(0,400);
glVertex2f(0,125);
glVertex2f(114,175);
glVertex2f(228,200);
glVertex2f(266,200);
glVertex2f(380,175);
glVertex2f(500,125);
glVertex2f(500,400);
glVertex2f(228,350);
glEnd();
//glFlush();

cloud_cockpit();

//system

glColor3f(0.114,0.208,0.341);
glBegin(GL_POLYGON);
glVertex2f(0,125);
glVertex2f(114,175);
glVertex2f(228,200);
glVertex2f(266,200);
glVertex2f(380,175);
glVertex2f(500,125);
glVertex2f(500,0);
glVertex2f(0,0);
glEnd();
//glFlush();

//window parts
glColor3f(0.114,0.208,0.341);
glLineWidth(20);
glBegin(GL_LINES);
glVertex2f(190,365);
glVertex2f(152,177);
glVertex2f(304,365);
glVertex2f(342,177);
glEnd();
//glFlush();

// system parts

glColor3f(0.007,0.243,0.541);
glBegin(GL_POLYGON);
glVertex2f(38,132);
glVertex2f(57,75);
glVertex2f(437,75);
glVertex2f(456,132);
glVertex2f(380,160);
glVertex2f(247,193);
glVertex2f(114,168);
glEnd();
//glFlush();

//here
glColor3f(0.271,0.482,0.616);
glBegin(GL_POLYGON);
glVertex2f(143,150);
glVertex2f(133,100);
glVertex2f(181,100);
glVertex2f(190,150);
glEnd();

glColor3f(0.271,0.482,0.616);
glBegin(GL_POLYGON);
glVertex2f(304,150);
glVertex2f(314,100);
glVertex2f(361,100);
glVertex2f(351,150);
glEnd();

glLineWidth(5);
glColor3f(0.114,0.208,0.341);
glBegin(GL_LINES);
glVertex2f(143,150);
glVertex2f(133,100);
glVertex2f(190,150);
glVertex2f(181,100);
glVertex2f(143,150);
glVertex2f(190,150);
glVertex2f(181,100);
glVertex2f(133,100);

glEnd();

glColor3f(0.114,0.208,0.341);
glBegin(GL_LINES);
glVertex2f(304,150);
glVertex2f(314,100);
glVertex2f(361,100);
glVertex2f(351,150);
glVertex2f(314,100);
glVertex2f(361,100);
glVertex2f(304,150);
glVertex2f(351,150);
glEnd();

glColor3f(0.271,0.482,0.616);
glBegin(GL_POLYGON);
glVertex2f(247,193);
glVertex2f(209,182);
glVertex2f(190,75);
glVertex2f(304,75);
glVertex2f(285,182);
glEnd();
//glFlush();

glColor3f(0.114,0.208,0.341);
glBegin(GL_LINES);
glVertex2f(143,150);
glVertex2f(133,100);
glVertex2f(181,100);
glVertex2f(190,150);
glEnd();

glColor3f(0.114,0.208,0.341);
glBegin(GL_LINES);
glVertex2f(304,150);
glVertex2f(314,100);
glVertex2f(361,100);
glVertex2f(351,150);
glEnd();

glColor3f(0.914,0.769,0.416);
glPointSize(15);
glBegin(GL_POINTS);
glVertex2f(219,175);
glVertex2f(219,125);
glVertex2f(275,175);
glVertex2f(275,125);
glEnd();

glColor3f(0.933,0.424,0.302);
glPointSize(15);
glBegin(GL_POINTS);
glVertex2f(219,150);
glVertex2f(219,100);
glVertex2f(275,150);
glVertex2f(275,100);
glEnd();

glColor3f(0.933,0.424,0.302);
for(int i=0;i<=5;i++){
draw_circle(237,175,i);
draw_circle(237,125,i);
draw_circle(256,175,i);
draw_circle(256,125,i);
}

glColor3f(0.502,1,0.859);
for(int i=0;i<=5;i++){
draw_circle(237,150,i);
draw_circle(237,100,i);
draw_circle(256,150,i);
draw_circle(256,100,i);
}

human_cockpit();

//chair1

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(67,125);
glVertex2f(38,100);
glVertex2f(57,0);
glVertex2f(133,0);
glVertex2f(114,125);
glEnd();
//glFlush();

glColor3f(0.933,0.424,0.302);
glBegin(GL_POLYGON);
glVertex2f(38,100);
glVertex2f(57,0);
glVertex2f(120,0);
glVertex2f(114,100);
glEnd();
//glFlush();

//chair 2

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(380,125);
glVertex2f(361,0);
glVertex2f(437,0);
glVertex2f(456,100);
glVertex2f(437,125);
glEnd();
//glFlush();

glColor3f(0.933,0.424,0.302);
glBegin(GL_POLYGON);
glVertex2f(380,100);
glVertex2f(372,0);
glVertex2f(437,0);
glVertex2f(456,100);
glEnd();
//glFlush();

//system parts

glColor3f(0,0.467,0.714);
glBegin(GL_POLYGON);
glVertex2f(171,75);
glVertex2f(171,0);
glVertex2f(323,0);
glVertex2f(323,75);
glEnd();
//glFlush();

glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(124,75);
glVertex2f(133,0);
glVertex2f(171,0);
glVertex2f(171,75);
glEnd();
//glFlush();

glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(323,75);
glVertex2f(323,0);
glVertex2f(361,0);
glVertex2f(370,75);
glEnd();

glFlush();

}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cockpit of Airplane");
	glutDisplayFunc(display);
	init();
    glutTimerFunc(100,update,0);
	glutMainLoop();
}
