#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include <string.h>
#include <stdio.h>
GLfloat a=0,b=0,c=0,d=0,e=0;
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
void *currentfont;
void setFont(void *font)
{
    currentfont=font;
}
void drawstring(float x,float y,float z,char *string)
{
    char *c;
    int len = (int) strlen(string);
    int i;
    glRasterPos3f(x,y,z);
    for(i = 0;i<len;i++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,string[i]);
    }
}
void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, h, 0);
  glMatrixMode(GL_MODELVIEW);
}
void update1(int value)
{
    a+=0;
	b+=0;
	c+=0;
	d+=0;
	e-=10;
	if(e<=-175)
        e=0;
	if(a<=90)
        a+=2;
    else
        b+=2;
    if(c<=140)
        c+=2;
    else
        d+=2;
	if(b>=87){
        a=0;
        b=0;
	}
	if(d>=87){
        c=0;
        d=0;
	}
	glutPostRedisplay();
	glutTimerFunc(100,update1,0);
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
void human(){

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(c,d,0);
for(int i=1;i<=5;i++){
draw_circle(209,50,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,0.804,0.698);
glLineWidth(10);
glTranslatef(c,d,0);
glBegin(GL_LINES);
glVertex2f(203,45);
glVertex2f(197,20);
glVertex2f(215,45);
glVertex2f(221,20);
glVertex2f(205,25);
glVertex2f(205,5);
glVertex2f(213,25);
glVertex2f(213,5);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.741,0.698,1);
glLineWidth(35);
glTranslatef(c,d,0);
glBegin(GL_LINES);
glVertex2f(209,45);
glVertex2f(209,25);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.51,0.70,0.60);
glLineWidth(10);
glTranslatef(c,d,0);
glBegin(GL_POLYGON);
glVertex2f(218,37.5);
glVertex2f(218,0);
glVertex2f(228,0);
glVertex2f(228,37.5);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(a,b,0);
for(int i=1;i<=5;i++){
draw_circle(266,50,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,0.686,0.80);
glLineWidth(35);
glTranslatef(a,b,0);
glBegin(GL_LINES);
glVertex2f(266,45);
glVertex2f(266,25);
glEnd();
glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(1,0.804,0.698);
glLineWidth(10);
glTranslatef(a,b,0);
glBegin(GL_LINES);
glVertex2f(260,45);
glVertex2f(254,20);
glVertex2f(272,45);
glVertex2f(278,20);
glVertex2f(262,25);
glVertex2f(262,5);
glVertex2f(270,25);
glVertex2f(270,5);
glEnd();
glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.988,0.639,0.067);
glLineWidth(10);
glTranslatef(a,b,0);
glBegin(GL_POLYGON);
glVertex2f(275,37.5);
glVertex2f(275,0);
glVertex2f(285,0);
glVertex2f(285,37.5);
glEnd();
glPopMatrix();

}
void cloud(){
glPushMatrix();
glColor3f(0.929,0.965,0.976);
glTranslatef(e,0,0);
for(int i=1;i<=27;i++){
draw_circle(276,425,i);
}
for(int i=1;i<=19;i++){
draw_circle(257,425,i);
}
for(int i=1;i<=19;i++){
draw_circle(295,425,i);
}
for(int i=1;i<=20;i++){
draw_circle(361,450,i);
}
for(int i=1;i<=15;i++){
draw_circle(350,450,i);
}
for(int i=1;i<=15;i++){
draw_circle(374,450,i);
}
glPopMatrix();


}
void boarding(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

//sky

glBegin(GL_POLYGON);
glColor3f(0.659,0.855,0.863);
glVertex2f(0,500);
glColor3f(0.914,0.769,0.416);
glVertex2f(0,200);
glColor3f(0.914,0.769,0.416);
glVertex2f(500,200);
glColor3f(0.659,0.855,0.863);
glVertex2f(500,500);
glEnd();
//glFlush();

cloud();
//grass
glColor3f(0.22,0.69,0);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(0,175);
glVertex2f(500,175);
glVertex2f(500,200);
glEnd();
//glFlush();

//plants
glColor3f(0,0.502,0);
glBegin(GL_POLYGON);
glVertex2f(0,212.5);
glVertex2f(0,200);
glVertex2f(38,200);
glEnd();
//glFlush();

glColor3f(0,0.502,0);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(38,225);
glVertex2f(57,225);
glVertex2f(95,200);
glEnd();
//glFlush();

glColor3f(0,0.502,0);
glBegin(GL_POLYGON);
glVertex2f(76,200);
glVertex2f(133,225);
glVertex2f(304,225);
glVertex2f(380,200);
glEnd();
//glFlush();

//road
glColor3f(0.125,0.15,0.225);
glBegin(GL_POLYGON);
glVertex2f(0,175);
glVertex2f(0,150);
glVertex2f(500,150);
glVertex2f(500,175);
glEnd();
//glFlush();

glColor3f(0.133,0.20,0.231);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,0);
glVertex2f(500,0);
glVertex2f(500,150);
glEnd();
//glFlush();

//buildings
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(418,350);
glVertex2f(408,325);
glVertex2f(408,200);
glVertex2f(418,200);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(351,425);
glVertex2f(351,400);
glVertex2f(390,400);
glVertex2f(390,425);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(342,400);
glVertex2f(342,200);
glVertex2f(399,200);
glVertex2f(399,400);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(342,400);
glVertex2f(342,200);
glVertex2f(380,200);
glVertex2f(361,400);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(399,300);
glVertex2f(399,200);
glVertex2f(418,200);
glVertex2f(405,300);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(418,400);
glVertex2f(418,200);
glVertex2f(475,200);
glVertex2f(475,375);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(418,400);
glVertex2f(418,200);
glVertex2f(475,200);
glVertex2f(475,300);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(456,300);
glVertex2f(456,200);
glVertex2f(494,200);
glVertex2f(494,350);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(494,350);
glVertex2f(475,275);
glVertex2f(475,200);
glVertex2f(494,200);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(475,275);
glVertex2f(475,200);
glVertex2f(500,200);
glVertex2f(500,250);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(475,275);
glVertex2f(475,200);
glVertex2f(500,200);
glVertex2f(500,225);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2f(342,400);
glVertex2f(399,400);
glVertex2f(418,400);
glVertex2f(475,375);
glVertex2f(456,300);
glVertex2f(494,350);
glVertex2f(475,275);
glVertex2f(500,250);
glEnd();
//glFlush();

//main building
glColor3f(0.031,0.60,0.729);
glBegin(GL_POLYGON);
glVertex2f(95,325);
glVertex2f(114,200);
glVertex2f(323,200);
glVertex2f(342,325);
glEnd();
//glFlush();

glColor3f(0.125,0.729,0.772);
glBegin(GL_POLYGON);
glVertex2f(98,300);
glVertex2f(114,200);
glVertex2f(323,200);
glVertex2f(339,300);
glEnd();
//glFlush();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(76,350);
glVertex2f(76,325);
glVertex2f(361,325);
glVertex2f(361,350);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(95,325);
glVertex2f(171,200);
glVertex2f(209,200);
glVertex2f(133,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(171,325);
glVertex2f(238,200);
glVertex2f(247,200);
glVertex2f(181,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(209,325);
glVertex2f(266,200);
glVertex2f(285,200);
glVertex2f(228,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(238,325);
glVertex2f(295,200);
glVertex2f(323,200);
glVertex2f(266,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(295,325);
glVertex2f(331,250);
glVertex2f(333,275);
glVertex2f(304,325);
glEnd();
//glFlush();

glColor3f(0.369,0.392,0.447);
glBegin(GL_POLYGON);
glVertex2f(133,400);
glVertex2f(133,350);
glVertex2f(152,350);
glVertex2f(152,400);
glEnd();
//glFlush();

glColor3f(0.49,0.522,0.592);
glBegin(GL_POLYGON);
glVertex2f(133,475);
glVertex2f(133,400);
glVertex2f(152,400);
glVertex2f(152,475);
glEnd();
//glFlush();

glColor3f(0.125,0.729,0.772);
glBegin(GL_POLYGON);
glVertex2f(133,462.5);
glVertex2f(114,450);
glVertex2f(119,400);
glVertex2f(164,400);
glVertex2f(171,450);
glVertex2f(152,462.5);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(114,450);
glVertex2f(133,400);
glVertex2f(135,400);
glVertex2f(124,450);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(133,450);
glVertex2f(152,400);
glVertex2f(163,425);
glVertex2f(152,450);
glEnd();
//glFlush();

glColor3f(0.49,0.522,0.592);
glBegin(GL_POLYGON);
glVertex2f(109,455);
glVertex2f(109,450);
glVertex2f(176,450);
glVertex2f(176,455);
glEnd();
//glFlush();

glColor3f(0.49,0.522,0.592);
glBegin(GL_POLYGON);
glVertex2f(119,400);
glVertex2f(114,387.5);
glVertex2f(171,387.5);
glVertex2f(164,400);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(1);
glBegin(GL_LINES);
glVertex2f(114,325);
glVertex2f(114,200);
glVertex2f(133,325);
glVertex2f(133,200);
glVertex2f(152,325);
glVertex2f(152,200);
glVertex2f(171,325);
glVertex2f(171,200);
glVertex2f(190,325);
glVertex2f(190,200);
glVertex2f(209,325);
glVertex2f(209,200);
glVertex2f(228,325);
glVertex2f(228,200);
glVertex2f(247,325);
glVertex2f(247,200);
glVertex2f(266,325);
glVertex2f(266,200);
glVertex2f(285,325);
glVertex2f(285,200);
glVertex2f(304,325);
glVertex2f(304,200);
glVertex2f(323,325);
glVertex2f(323,200);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2f(133,250);
glVertex2f(133,200);
glVertex2f(171,250);
glVertex2f(171,200);
glVertex2f(200,250);
glVertex2f(200,200);
glVertex2f(238,250);
glVertex2f(238,200);
glVertex2f(266,250);
glVertex2f(266,200);
glVertex2f(304,250);
glVertex2f(304,200);
glVertex2f(133,250);
glVertex2f(171,250);
glVertex2f(200,250);
glVertex2f(238,250);
glVertex2f(266,250);
glVertex2f(304,250);
glEnd();
//glFlush();

//lights
glColor3f(0.424,0.459,0.49);
glLineWidth(3);
glBegin(GL_LINES);
glVertex2f(76,275);
glVertex2f(76,200);
glVertex2f(133,275);
glVertex2f(133,200);
glVertex2f(323,275);
glVertex2f(323,200);
glVertex2f(380,275);
glVertex2f(380,200);
glEnd();
//glFlush();

glColor3f(0.424,0.459,0.49);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2f(76,250);
glVertex2f(76,200);
glVertex2f(133,250);
glVertex2f(133,200);
glVertex2f(323,250);
glVertex2f(323,200);
glVertex2f(380,250);
glVertex2f(380,200);
glEnd();
//glFlush();

glColor3f(1,0.835,0);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2f(95,287.5);
glVertex2f(76,275);
glVertex2f(152,287.5);
glVertex2f(133,275);
glVertex2f(304,287.5);
glVertex2f(323,275);
glVertex2f(361,285.5);
glVertex2f(380,275);
glEnd();
//glFlush();

glColor3f(0.424,0.459,0.49);
glLineWidth(3);
glBegin(GL_LINES);
glVertex2f(95,287.5);
glVertex2f(76,275);
glVertex2f(152,287.5);
glVertex2f(133,275);
glVertex2f(304,287.5);
glVertex2f(323,275);
glVertex2f(361,285.5);
glVertex2f(380,275);
glEnd();
//glFlush();

//airplane
glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(76,300);
glVertex2f(95,175);
glVertex2f(152,175);
glVertex2f(95,290);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(133,200);
glVertex2f(133,175);
glVertex2f(171,175);
glEnd();
//glFlush();

glColor3f(0,0,0);
glLineWidth(25);
glBegin(GL_LINES);
glVertex2f(209,100);
glVertex2f(209,73);
glVertex2f(399,100);
glVertex2f(399,73);
glEnd();
//glFlush();

glColor3f(0,0,0);
draw_circle(209,62.5,10);
draw_circle(399,62.5,10);

glColor3f(1,1,1);
draw_circle(209,62.5,5);
draw_circle(399,62.5,5);

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(76,175);
glVertex2f(67,162.5);
glVertex2f(171,100);
glVertex2f(380,85);
glVertex2f(437,100);
glVertex2f(447,112.5);
glVertex2f(447,137.5);
glVertex2f(380,187.5);
glEnd();
//glFlush();

glColor3f(0,0.706,0.847);
glBegin(GL_POLYGON);
glVertex2f(399,175);
glVertex2f(380,175);
glVertex2f(410,150);
glVertex2f(429,150);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(67,187.5);
glVertex2f(76,162.5);
glVertex2f(114,150);
glVertex2f(124,160);
glEnd();
//glFlush();

glColor3f(0,0.706,0.847);
glLineWidth(25);
glBegin(GL_LINES);
glVertex2f(171,150);
glVertex2f(171,137.5);
glVertex2f(190,150);
glVertex2f(190,137.5);
glVertex2f(209,150);
glVertex2f(209,137.5);
glVertex2f(228,150);
glVertex2f(228,137.5);
glVertex2f(247,150);
glVertex2f(247,137.5);
glVertex2f(266,150);
glVertex2f(266,137.5);
glVertex2f(285,150);
glVertex2f(285,137.5);
glVertex2f(304,150);
glVertex2f(304,137.5);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(190,175);
glVertex2f(190,137.5);
glVertex2f(209,98);
glVertex2f(209,125);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(209,97);
glVertex2f(380,85);
glVertex2f(190,137.5);
glEnd();
//glFlush();

glColor3f(0.424,0.459,0.49);
glBegin(GL_POLYGON);
glVertex2f(342,150);
glVertex2f(342,87.5);
glVertex2f(380,87.5);
glVertex2f(380,150);
glEnd();
//glFlush();

glColor3f(0.678,0.71,0.741);
glBegin(GL_POLYGON);
glVertex2f(380,87.5);
glVertex2f(342,85.5);
glVertex2f(342,25);
glVertex2f(380,25);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(342,25);
glVertex2f(380,25);
glVertex2f(342,37.5);
glVertex2f(380,37.5);
glVertex2f(342,50);
glVertex2f(380,50);
glVertex2f(342,62.5);
glVertex2f(380,62.5);
glVertex2f(342,75);
glVertex2f(380,75);
glVertex2f(342,87.5);
glVertex2f(380,87.5);
glEnd();
//glFlush();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(342,100);
glVertex2f(342,25);
glVertex2f(380,100);
glVertex2f(380,25);
glEnd();
//glFlush();

glColor3f(0.960,0.952,0.956);
glBegin(GL_POLYGON);
glVertex2f(285,100);
glVertex2f(255,100);
glVertex2f(228,87.5);
glVertex2f(255,75);
glVertex2f(285,75);
glEnd();
//glFlush();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(285,100);
glVertex2f(255,100);
glVertex2f(255,75);
glVertex2f(285,75);
glEnd();
//glFlush();

glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(285,100);
glVertex2f(285,75);
glVertex2f(290,80);
glVertex2f(290,95);
glEnd();
//glFlush();

//human
human();

glFlush();

}
void frontscreen(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0,0,1);
    drawstring(20.0-50,90.0,0.0,"NMAMIT");
    glColor3f(0.7,0,1);
    drawstring(21-50,82,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1,0.5,0);
    drawstring(38-50,70,0.0,"A MINI PROJECT ON");
    glColor3f(1,0,0);
    drawstring(40-50,60,0.0,"3-D Plane Simulation");
    glColor3f(1,0.5,0);
    drawstring(20-50,50,0.0,"BY:");
    glColor3f(0.5,0,0.5);
    drawstring(10-50,40,0.0,"Sonali Suresh Shetty      (4NM18CS185)");
    drawstring(10-50,34,0.0,"Shreema S Suvarna         (4NM18CS176)");
    glColor3f(1,0,0);
    glColor3f(1,0.1,1);
    glutSwapBuffers();
    glFlush();
}
void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-100.0,100.0,-100.0,100.0,-50.0,50.0);
}
GLfloat f=0,g=0;
void update2(int value)
{
    f-=20;
    g+=2;
    if(f<=-500)
        f=0;
	glutPostRedisplay();
	glutTimerFunc(100,update2,0);
}
void runway1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

//sky
glBegin(GL_POLYGON);
glColor3f(0.659,0.855,0.863);
glVertex2f(0,500);
glColor3f(1,1,1);
glVertex2f(0,20);
glColor3f(1,1,1);
glVertex2f(1000,0);
glColor3f(0.659,0.855,0.863);
glVertex2f(1000,500);
glEnd();

//building
glPushMatrix();
//glColor3f(0.518,0.824,0.965);
glColor3f(0.60,0.757,0.871);
glLineWidth(50);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(0,375);
glVertex2f(0,0);
glVertex2f(19,300);
glVertex2f(19,0);
glVertex2f(38,275);
glVertex2f(38,0);
glVertex2f(57,350);
glVertex2f(57,0);
glVertex2f(76,250);
glVertex2f(76,0);
glVertex2f(95,250);
glVertex2f(95,0);
glVertex2f(114,300);
glVertex2f(114,0);
glVertex2f(133,350);
glVertex2f(133,0);
glVertex2f(152,275);
glVertex2f(152,0);
glVertex2f(171,325);
glVertex2f(171,0);
glVertex2f(190,375);
glVertex2f(190,0);
glVertex2f(209,325);
glVertex2f(209,0);
glVertex2f(228,275);
glVertex2f(228,0);
glVertex2f(247,350);
glVertex2f(247,0);
glVertex2f(266,375);
glVertex2f(266,0);
glVertex2f(285,325);
glVertex2f(285,0);
glVertex2f(304,275);
glVertex2f(304,0);
glVertex2f(323,300);
glVertex2f(323,0);
glVertex2f(342,350);
glVertex2f(342,0);
glVertex2f(361,300);
glVertex2f(361,0);
glVertex2f(380,350);
glVertex2f(380,0);
glVertex2f(399,275);
glVertex2f(399,0);
glVertex2f(418,325);
glVertex2f(418,0);
glVertex2f(437,375);
glVertex2f(437,0);
glVertex2f(456,325);
glVertex2f(456,0);
glVertex2f(475,275);
glVertex2f(475,0);
glVertex2f(494,350);
glVertex2f(494,0);
glVertex2f(500,375);
glVertex2f(500,0);
glVertex2f(519,300);
glVertex2f(519,0);
glVertex2f(538,275);
glVertex2f(538,0);
glVertex2f(557,350);
glVertex2f(557,0);
glVertex2f(576,250);
glVertex2f(576,0);
glVertex2f(595,250);
glVertex2f(595,0);
glVertex2f(614,300);
glVertex2f(614,0);
glVertex2f(633,350);
glVertex2f(633,0);
glVertex2f(652,275);
glVertex2f(652,0);
glVertex2f(671,325);
glVertex2f(671,0);
glVertex2f(690,375);
glVertex2f(690,0);
glVertex2f(709,325);
glVertex2f(709,0);
glVertex2f(728,275);
glVertex2f(728,0);
glVertex2f(747,350);
glVertex2f(747,0);
glVertex2f(766,375);
glVertex2f(766,0);
glVertex2f(785,325);
glVertex2f(785,0);
glVertex2f(804,275);
glVertex2f(804,0);
glVertex2f(823,300);
glVertex2f(823,0);
glVertex2f(842,350);
glVertex2f(842,0);
glVertex2f(861,300);
glVertex2f(861,0);
glVertex2f(880,350);
glVertex2f(880,0);
glVertex2f(899,275);
glVertex2f(899,0);
glVertex2f(918,325);
glVertex2f(918,0);
glVertex2f(937,375);
glVertex2f(937,0);
glVertex2f(956,325);
glVertex2f(956,0);
glVertex2f(975,275);
glVertex2f(975,0);
glVertex2f(1000,350);
glVertex2f(1000,0);
glEnd();
glPopMatrix();

//building
glPushMatrix();
glColor3f(0.008,0.502,0.565);
glTranslatef(f,0,0);
for(int i=25;i>=10;i--){
draw_circle(256.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0,0.659,0.588);
glTranslatef(f,0,0);
for(int i=0;i<=10;i++){
draw_circle(237.5,250,i);
draw_circle(256.5,250,i);
draw_circle(275.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glTranslatef(f,0,0);
draw_circle(237.5,250,10);
draw_circle(256.5,250,10);
draw_circle(275.5,250,10);
glPopMatrix();

glPushMatrix();
glColor3f(0.008,0.765,0.604);
glTranslatef(f,0,0);
glBegin(GL_POLYGON);
glVertex2f(209,250);
glVertex2f(209,225);
glVertex2f(304,225);
glVertex2f(304,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glLineWidth(5);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(209,245);
glVertex2f(304,245);
glEnd();
glPopMatrix();

//grass
glColor3f(0.667,0.80,0);
glBegin(GL_POLYGON);
glVertex2f(0,225);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,225);
glEnd();

//tree
glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(10);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(76,287.5);
glVertex2f(76,200);
glVertex2f(228,287.5);
glVertex2f(228,200);
glVertex2f(304,287.5);
glVertex2f(304,200);
glVertex2f(380,287.5);
glVertex2f(380,200);
glVertex2f(456,287.5);
glVertex2f(456,200);
glVertex2f(576,287.5);
glVertex2f(576,200);
glVertex2f(652,287.5);
glVertex2f(652,200);
glVertex2f(728,287.5);
glVertex2f(728,200);
glVertex2f(804,287.5);
glVertex2f(804,200);
glVertex2f(880,287.5);
glVertex2f(880,200);
glVertex2f(956,287.5);
glVertex2f(956,200);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(5);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(57,250);
glVertex2f(76,225);
glVertex2f(76,225);
glVertex2f(95,250);
glVertex2f(209,250);
glVertex2f(228,225);
glVertex2f(228,225);
glVertex2f(247,250);
glVertex2f(285,250);
glVertex2f(304,225);
glVertex2f(304,225);
glVertex2f(323,250);
glVertex2f(361,250);
glVertex2f(380,225);
glVertex2f(380,225);
glVertex2f(399,250);
glVertex2f(437,250);
glVertex2f(456,225);
glVertex2f(456,225);
glVertex2f(475,250);
glVertex2f(557,250);
glVertex2f(576,225);
glVertex2f(576,225);
glVertex2f(595,250);
glVertex2f(633,250);
glVertex2f(652,225);
glVertex2f(652,225);
glVertex2f(671,250);
glVertex2f(709,250);
glVertex2f(728,225);
glVertex2f(728,225);
glVertex2f(747,250);
glVertex2f(785,250);
glVertex2f(804,225);
glVertex2f(804,225);
glVertex2f(823,250);
glVertex2f(861,250);
glVertex2f(880,225);
glVertex2f(880,225);
glVertex2f(899,250);
glVertex2f(937,250);
glVertex2f(956,225);
glVertex2f(956,225);
glVertex2f(975,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(3);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(57,275);
glVertex2f(76,250);
glVertex2f(76,250);
glVertex2f(95,275);
glVertex2f(209,275);
glVertex2f(228,250);
glVertex2f(228,250);
glVertex2f(247,275);
glVertex2f(285,275);
glVertex2f(304,250);
glVertex2f(304,250);
glVertex2f(323,275);
glVertex2f(361,275);
glVertex2f(380,250);
glVertex2f(380,250);
glVertex2f(399,275);
glVertex2f(437,275);
glVertex2f(456,250);
glVertex2f(456,250);
glVertex2f(475,275);
glVertex2f(557,275);
glVertex2f(576,250);
glVertex2f(576,250);
glVertex2f(595,275);
glVertex2f(633,275);
glVertex2f(652,250);
glVertex2f(652,250);
glVertex2f(671,275);
glVertex2f(709,275);
glVertex2f(728,250);
glVertex2f(728,250);
glVertex2f(747,275);
glVertex2f(785,275);
glVertex2f(804,250);
glVertex2f(804,250);
glVertex2f(823,275);
glVertex2f(861,275);
glVertex2f(880,250);
glVertex2f(880,250);
glVertex2f(899,275);
glVertex2f(937,275);
glVertex2f(956,250);
glVertex2f(956,250);
glVertex2f(975,275);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.31,0.467,0.176);
glTranslatef(f,0,0);
for(int i=0;i<=10;i++){
draw_circle(76,287.5,i);
draw_circle(228,287.5,i);
draw_circle(304,287.5,i);
draw_circle(380,287.5,i);
draw_circle(456,287.5,i);
draw_circle(576,287.5,i);
draw_circle(652,287.5,i);
draw_circle(728,287.5,i);
draw_circle(804,287.5,i);
draw_circle(880,287.5,i);
draw_circle(956,287.5,i);
draw_circle(57,250,i);
draw_circle(95,250,i);
draw_circle(209,250,i);
draw_circle(247,250,i);
draw_circle(285,250,i);
draw_circle(323,250,i);
draw_circle(361,250,i);
draw_circle(399,250,i);
draw_circle(437,250,i);
draw_circle(475,250,i);
draw_circle(557,250,i);
draw_circle(595,250,i);
draw_circle(633,250,i);
draw_circle(671,250,i);
draw_circle(709,250,i);
draw_circle(747,250,i);
draw_circle(785,250,i);
draw_circle(823,250,i);
draw_circle(861,250,i);
draw_circle(899,250,i);
draw_circle(937,250,i);
draw_circle(975,250,i);
}
for(int i=0;i<=5;i++){
draw_circle(57,275,i);
draw_circle(95,275,i);
draw_circle(209,275,i);
draw_circle(247,275,i);
draw_circle(285,275,i);
draw_circle(323,275,i);
draw_circle(361,275,i);
draw_circle(399,275,i);
draw_circle(437,275,i);
draw_circle(475,275,i);
draw_circle(557,275,i);
draw_circle(595,275,i);
draw_circle(633,275,i);
draw_circle(671,275,i);
draw_circle(709,275,i);
draw_circle(747,275,i);
draw_circle(785,275,i);
draw_circle(823,275,i);
draw_circle(861,275,i);
draw_circle(899,275,i);
draw_circle(937,275,i);
draw_circle(975,275,i);
}
glPopMatrix();

//mid road
glPushMatrix();
glColor3f(0.604,0.561,0.592);
glTranslatef(f,0,0);
glBegin(GL_POLYGON);
glVertex2f(95,225);
glVertex2f(76,200);
glVertex2f(76,0);
glVertex2f(190,0);
glVertex2f(190,200);
glVertex2f(171,225);
glEnd();
glPopMatrix();

//road
glColor3f(0.604,0.561,0.592);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,200);
glEnd();

glColor3f(0.451,0.435,0.447);
glBegin(GL_POLYGON);
glVertex2f(0,130);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,130);
glEnd();

//land
glColor3f(0.266,0.215,0.258);
glBegin(GL_POLYGON);
glVertex2f(0,75);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,75);
glEnd();

glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(5);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(0,197.5);
glVertex2f(77,197.5);
glVertex2f(190,197.5);
glVertex2f(1000,195.5);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(3);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(77,199);
glVertex2f(96,225);
glVertex2f(191,198);
glVertex2f(172,225);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glLineWidth(7);
glTranslatef(f,0,0);
glBegin(GL_LINES);
glVertex2f(38,162.5);
glVertex2f(76,162.5);
glVertex2f(209,162.5);
glVertex2f(247,162.5);
glVertex2f(266,162.5);
glVertex2f(304,162.5);
glVertex2f(323,162.5);
glVertex2f(361,162.5);
glVertex2f(380,162.5);
glVertex2f(418,162.5);
glVertex2f(437,162.5);
glVertex2f(475,162.5);
glVertex2f(538,162.5);
glVertex2f(576,162.5);
glVertex2f(595,162.5);
glVertex2f(633,162.5);
glVertex2f(652,162.5);
glVertex2f(690,162.5);
glVertex2f(709,162.5);
glVertex2f(747,162.5);
glVertex2f(766,162.5);
glVertex2f(804,162.5);
glVertex2f(823,162.5);
glVertex2f(861,162.5);
glVertex2f(880,162.5);
glVertex2f(918,162.5);
glVertex2f(937,162.5);
glVertex2f(975,162.5);
glEnd();
glPopMatrix();

//airplane
glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(g,0,0);
glBegin(GL_POLYGON);
glVertex2f(38,225);
glVertex2f(38,175);
glVertex2f(76,175);
glVertex2f(48,225);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(g,0,0);
glBegin(GL_POLYGON);
glVertex2f(76,200);
glVertex2f(95,175);
glVertex2f(114,175);
glVertex2f(86,200);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glLineWidth(2);
glTranslatef(g,0,0);
glBegin(GL_LINES);
glVertex2f(67,175);
glVertex2f(67,137);
glVertex2f(134,137);
glVertex2f(134,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(g,0,0);
for(int i=0;i<=5;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(g,0,0);
for(int i=0;i<=2;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(g,0,0);
glBegin(GL_POLYGON);
glVertex2f(38,187.5);
glVertex2f(38,150);
glVertex2f(152,150);
glVertex2f(171,162.5);
glVertex2f(167,167);
glVertex2f(152,185.5);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(g,0,0);
glBegin(GL_POLYGON);
glVertex2f(95,175);
glVertex2f(76,137.5);
glVertex2f(86,137.5);
glVertex2f(114,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(g,0,0);
glBegin(GL_POLYGON);
glVertex2f(149,162.5);
glVertex2f(149,150);
glVertex2f(152,150);
glVertex2f(171,162.5);
glEnd();
glPopMatrix();

glFlush();
}
GLfloat h=0,i=0,j=0;
void update3(int value)
{
    h-=20;
    i+=2;
    j+=2;
    if(h<=-500)
        h=0;
	glutPostRedisplay();
	glutTimerFunc(100,update3,0);
}
void takeoff(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

//sky
glBegin(GL_POLYGON);
glColor3f(0.659,0.855,0.863);
glVertex2f(0,500);
glColor3f(1,1,1);
glVertex2f(0,20);
glColor3f(1,1,1);
glVertex2f(1000,0);
glColor3f(0.659,0.855,0.863);
glVertex2f(1000,500);
glEnd();

//building
glPushMatrix();
//glColor3f(0.518,0.824,0.965);
glColor3f(0.60,0.757,0.871);
glLineWidth(50);
glTranslatef(h,0,0);
glBegin(GL_LINES);
glVertex2f(0,375);
glVertex2f(0,0);
glVertex2f(19,300);
glVertex2f(19,0);
glVertex2f(38,275);
glVertex2f(38,0);
glVertex2f(57,350);
glVertex2f(57,0);
glVertex2f(76,250);
glVertex2f(76,0);
glVertex2f(95,250);
glVertex2f(95,0);
glVertex2f(114,300);
glVertex2f(114,0);
glVertex2f(133,350);
glVertex2f(133,0);
glVertex2f(152,275);
glVertex2f(152,0);
glVertex2f(171,325);
glVertex2f(171,0);
glVertex2f(190,375);
glVertex2f(190,0);
glVertex2f(209,325);
glVertex2f(209,0);
glVertex2f(228,275);
glVertex2f(228,0);
glVertex2f(247,350);
glVertex2f(247,0);
glVertex2f(266,375);
glVertex2f(266,0);
glVertex2f(285,325);
glVertex2f(285,0);
glVertex2f(304,275);
glVertex2f(304,0);
glVertex2f(323,300);
glVertex2f(323,0);
glVertex2f(342,350);
glVertex2f(342,0);
glVertex2f(361,300);
glVertex2f(361,0);
glVertex2f(380,350);
glVertex2f(380,0);
glVertex2f(399,275);
glVertex2f(399,0);
glVertex2f(418,325);
glVertex2f(418,0);
glVertex2f(437,375);
glVertex2f(437,0);
glVertex2f(456,325);
glVertex2f(456,0);
glVertex2f(475,275);
glVertex2f(475,0);
glVertex2f(494,350);
glVertex2f(494,0);
glVertex2f(500,375);
glVertex2f(500,0);
glVertex2f(519,300);
glVertex2f(519,0);
glVertex2f(538,275);
glVertex2f(538,0);
glVertex2f(557,350);
glVertex2f(557,0);
glVertex2f(576,250);
glVertex2f(576,0);
glVertex2f(595,250);
glVertex2f(595,0);
glVertex2f(614,300);
glVertex2f(614,0);
glVertex2f(633,350);
glVertex2f(633,0);
glVertex2f(652,275);
glVertex2f(652,0);
glVertex2f(671,325);
glVertex2f(671,0);
glVertex2f(690,375);
glVertex2f(690,0);
glVertex2f(709,325);
glVertex2f(709,0);
glVertex2f(728,275);
glVertex2f(728,0);
glVertex2f(747,350);
glVertex2f(747,0);
glVertex2f(766,375);
glVertex2f(766,0);
glVertex2f(785,325);
glVertex2f(785,0);
glVertex2f(804,275);
glVertex2f(804,0);
glVertex2f(823,300);
glVertex2f(823,0);
glVertex2f(842,350);
glVertex2f(842,0);
glVertex2f(861,300);
glVertex2f(861,0);
glVertex2f(880,350);
glVertex2f(880,0);
glVertex2f(899,275);
glVertex2f(899,0);
glVertex2f(918,325);
glVertex2f(918,0);
glVertex2f(937,375);
glVertex2f(937,0);
glVertex2f(956,325);
glVertex2f(956,0);
glVertex2f(975,275);
glVertex2f(975,0);
glVertex2f(1000,350);
glVertex2f(1000,0);
glEnd();
glPopMatrix();

//building
/*
glPushMatrix();
glColor3f(0.008,0.502,0.565);
glTranslatef(a,0,0);
for(int i=25;i>=10;i--){
draw_circle(256.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0,0.659,0.588);
glTranslatef(a,0,0);
for(int i=0;i<=10;i++){
draw_circle(237.5,250,i);
draw_circle(256.5,250,i);
draw_circle(275.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glTranslatef(a,0,0);
draw_circle(237.5,250,10);
draw_circle(256.5,250,10);
draw_circle(275.5,250,10);
glPopMatrix();

glPushMatrix();
glColor3f(0.008,0.765,0.604);
glTranslatef(a,0,0);
glBegin(GL_POLYGON);
glVertex2f(209,250);
glVertex2f(209,225);
glVertex2f(304,225);
glVertex2f(304,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glLineWidth(5);
glTranslatef(a,0,0);
glBegin(GL_LINES);
glVertex2f(209,245);
glVertex2f(304,245);
glEnd();
glPopMatrix();
*/

//grass
glColor3f(0.667,0.80,0);
glBegin(GL_POLYGON);
glVertex2f(0,225);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,225);
glEnd();

//tree
glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(10);
glTranslatef(h,0,0);
glBegin(GL_LINES);
glVertex2f(76,287.5);
glVertex2f(76,200);
glVertex2f(152,287.5);
glVertex2f(152,200);
glVertex2f(228,287.5);
glVertex2f(228,200);
glVertex2f(304,287.5);
glVertex2f(304,200);
glVertex2f(380,287.5);
glVertex2f(380,200);
glVertex2f(456,287.5);
glVertex2f(456,200);
glVertex2f(576,287.5);
glVertex2f(576,200);
glVertex2f(652,287.5);
glVertex2f(652,200);
glVertex2f(728,287.5);
glVertex2f(728,200);
glVertex2f(804,287.5);
glVertex2f(804,200);
glVertex2f(880,287.5);
glVertex2f(880,200);
glVertex2f(956,287.5);
glVertex2f(956,200);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(5);
glTranslatef(h,0,0);
glBegin(GL_LINES);
glVertex2f(57,250);
glVertex2f(76,225);
glVertex2f(76,225);
glVertex2f(95,250);
glVertex2f(133,250);
glVertex2f(152,225);
glVertex2f(152,225);
glVertex2f(171,250);
glVertex2f(209,250);
glVertex2f(228,225);
glVertex2f(228,225);
glVertex2f(247,250);
glVertex2f(285,250);
glVertex2f(304,225);
glVertex2f(304,225);
glVertex2f(323,250);
glVertex2f(361,250);
glVertex2f(380,225);
glVertex2f(380,225);
glVertex2f(399,250);
glVertex2f(437,250);
glVertex2f(456,225);
glVertex2f(456,225);
glVertex2f(475,250);
glVertex2f(557,250);
glVertex2f(576,225);
glVertex2f(576,225);
glVertex2f(595,250);
glVertex2f(633,250);
glVertex2f(652,225);
glVertex2f(652,225);
glVertex2f(671,250);
glVertex2f(709,250);
glVertex2f(728,225);
glVertex2f(728,225);
glVertex2f(747,250);
glVertex2f(785,250);
glVertex2f(804,225);
glVertex2f(804,225);
glVertex2f(823,250);
glVertex2f(861,250);
glVertex2f(880,225);
glVertex2f(880,225);
glVertex2f(899,250);
glVertex2f(937,250);
glVertex2f(956,225);
glVertex2f(956,225);
glVertex2f(975,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(3);
glTranslatef(h,0,0);
glBegin(GL_LINES);
glVertex2f(57,275);
glVertex2f(76,250);
glVertex2f(76,250);
glVertex2f(95,275);
glVertex2f(133,275);
glVertex2f(152,250);
glVertex2f(152,250);
glVertex2f(171,275);
glVertex2f(209,275);
glVertex2f(228,250);
glVertex2f(228,250);
glVertex2f(247,275);
glVertex2f(285,275);
glVertex2f(304,250);
glVertex2f(304,250);
glVertex2f(323,275);
glVertex2f(361,275);
glVertex2f(380,250);
glVertex2f(380,250);
glVertex2f(399,275);
glVertex2f(437,275);
glVertex2f(456,250);
glVertex2f(456,250);
glVertex2f(475,275);
glVertex2f(557,275);
glVertex2f(576,250);
glVertex2f(576,250);
glVertex2f(595,275);
glVertex2f(633,275);
glVertex2f(652,250);
glVertex2f(652,250);
glVertex2f(671,275);
glVertex2f(709,275);
glVertex2f(728,250);
glVertex2f(728,250);
glVertex2f(747,275);
glVertex2f(785,275);
glVertex2f(804,250);
glVertex2f(804,250);
glVertex2f(823,275);
glVertex2f(861,275);
glVertex2f(880,250);
glVertex2f(880,250);
glVertex2f(899,275);
glVertex2f(937,275);
glVertex2f(956,250);
glVertex2f(956,250);
glVertex2f(975,275);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.31,0.467,0.176);
glTranslatef(h,0,0);
for(int i=0;i<=10;i++){
draw_circle(76,287.5,i);
draw_circle(152,287.5,i);
draw_circle(228,287.5,i);
draw_circle(304,287.5,i);
draw_circle(380,287.5,i);
draw_circle(456,287.5,i);
draw_circle(576,287.5,i);
draw_circle(652,287.5,i);
draw_circle(728,287.5,i);
draw_circle(804,287.5,i);
draw_circle(880,287.5,i);
draw_circle(956,287.5,i);
draw_circle(57,250,i);
draw_circle(95,250,i);
draw_circle(133,250,i);
draw_circle(171,250,i);
draw_circle(209,250,i);
draw_circle(247,250,i);
draw_circle(285,250,i);
draw_circle(323,250,i);
draw_circle(361,250,i);
draw_circle(399,250,i);
draw_circle(437,250,i);
draw_circle(475,250,i);
draw_circle(557,250,i);
draw_circle(595,250,i);
draw_circle(633,250,i);
draw_circle(671,250,i);
draw_circle(709,250,i);
draw_circle(747,250,i);
draw_circle(785,250,i);
draw_circle(823,250,i);
draw_circle(861,250,i);
draw_circle(899,250,i);
draw_circle(937,250,i);
draw_circle(975,250,i);
}
for(int i=0;i<=5;i++){
draw_circle(57,275,i);
draw_circle(95,275,i);
draw_circle(133,275,i);
draw_circle(171,275,i);
draw_circle(209,275,i);
draw_circle(247,275,i);
draw_circle(285,275,i);
draw_circle(323,275,i);
draw_circle(361,275,i);
draw_circle(399,275,i);
draw_circle(437,275,i);
draw_circle(475,275,i);
draw_circle(557,275,i);
draw_circle(595,275,i);
draw_circle(633,275,i);
draw_circle(671,275,i);
draw_circle(709,275,i);
draw_circle(747,275,i);
draw_circle(785,275,i);
draw_circle(823,275,i);
draw_circle(861,275,i);
draw_circle(899,275,i);
draw_circle(937,275,i);
draw_circle(975,275,i);
}
glPopMatrix();

//mid road
/*glPushMatrix();
glColor3f(0.604,0.561,0.592);
glTranslatef(a,0,0);
glBegin(GL_POLYGON);
glVertex2f(95,225);
glVertex2f(76,200);
glVertex2f(76,0);
glVertex2f(190,0);
glVertex2f(190,200);
glVertex2f(171,225);
glEnd();
glPopMatrix();*/

//road
glColor3f(0.604,0.561,0.592);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,200);
glEnd();

glColor3f(0.451,0.435,0.447);
glBegin(GL_POLYGON);
glVertex2f(0,130);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,130);
glEnd();

//land
glColor3f(0.266,0.215,0.258);
glBegin(GL_POLYGON);
glVertex2f(0,75);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,75);
glEnd();

glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(5);
glTranslatef(h,0,0);
glBegin(GL_LINES);
glVertex2f(0,197.5);
//glVertex2f(77,197.5);
//glVertex2f(190,197.5);
glVertex2f(1000,195.5);
glEnd();
glPopMatrix();

/*glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(3);
glTranslatef(a,0,0);
glBegin(GL_LINES);
glVertex2f(77,199);
glVertex2f(96,225);
glVertex2f(191,198);
glVertex2f(172,225);
glEnd();
glPopMatrix();*/

glPushMatrix();
glColor3f(1,1,1);
glLineWidth(7);
glTranslatef(h,0,0);
glBegin(GL_LINES);
glVertex2f(38,162.5);
glVertex2f(76,162.5);
glVertex2f(95,162.5);
glVertex2f(133,162.5);
glVertex2f(152,162.5);
glVertex2f(190,162.5);
glVertex2f(209,162.5);
glVertex2f(247,162.5);
glVertex2f(266,162.5);
glVertex2f(304,162.5);
glVertex2f(323,162.5);
glVertex2f(361,162.5);
glVertex2f(380,162.5);
glVertex2f(418,162.5);
glVertex2f(437,162.5);
glVertex2f(475,162.5);
glVertex2f(538,162.5);
glVertex2f(576,162.5);
glVertex2f(595,162.5);
glVertex2f(633,162.5);
glVertex2f(652,162.5);
glVertex2f(690,162.5);
glVertex2f(709,162.5);
glVertex2f(747,162.5);
glVertex2f(766,162.5);
glVertex2f(804,162.5);
glVertex2f(823,162.5);
glVertex2f(861,162.5);
glVertex2f(880,162.5);
glVertex2f(918,162.5);
glVertex2f(937,162.5);
glVertex2f(975,162.5);
glEnd();
glPopMatrix();

//airplane
glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(i,j,0);
glBegin(GL_POLYGON);
glVertex2f(38,225);
glVertex2f(38,175);
glVertex2f(76,175);
glVertex2f(48,225);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(i,j,0);
glBegin(GL_POLYGON);
glVertex2f(76,200);
glVertex2f(95,175);
glVertex2f(114,175);
glVertex2f(86,200);
glEnd();
glPopMatrix();

/*glPushMatrix();
glColor3f(0,0,0);
glLineWidth(2);
glTranslatef(b,c,0);
glBegin(GL_LINES);
glVertex2f(67,175);
glVertex2f(67,137);
glVertex2f(134,137);
glVertex2f(134,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(b,c,0);
for(int i=0;i<=5;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(b,c,0);
for(int i=0;i<=2;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();
*/

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(i,j,0);
glBegin(GL_POLYGON);
glVertex2f(38,187.5);
glVertex2f(38,150);
glVertex2f(152,150);
glVertex2f(171,162.5);
glVertex2f(167,167);
glVertex2f(152,185.5);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(i,j,0);
glBegin(GL_POLYGON);
glVertex2f(95,175);
glVertex2f(76,137.5);
glVertex2f(86,137.5);
glVertex2f(114,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(i,j,0);
glBegin(GL_POLYGON);
glVertex2f(149,162.5);
glVertex2f(149,150);
glVertex2f(152,150);
glVertex2f(171,162.5);
glEnd();
glPopMatrix();

glFlush();
}
GLfloat k=0,l=0;
void update4(int value)
{
	k+=2;
	l-=50;
    if(l<=-200)
		l=300;
    if(k>=500)
        k=0;
	glutPostRedisplay();
	glutTimerFunc(100,update4,0);
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
void airplaneInSky1(void)
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
GLfloat m=0,n=0;
void update5(int value)
{
	m-=30;
	n+=30;
    if(m<-250){
        m=0;
        n=0;
    }
	glutPostRedisplay();
	glutTimerFunc(100,update5,0);
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
GLfloat o=0,p=0;
void update6(int value)
{
	o+=2;
	p-=50;
    if(p<=-200)
		p=300;
    if(o>=500)
        o=0;
	glutPostRedisplay();
	glutTimerFunc(100,update6,0);
}
void cloudBehindAirplane2(){

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(p,0,0);
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
glTranslatef(p,0,0);
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
void cloudFrontAirplane2(){

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(p,0,0);
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
glTranslatef(p,0,0);
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
void airplaneInSky2(void)
{

glClear(GL_COLOR_BUFFER_BIT);

//sky
/*glColor3f(0.565,0.878,0.937);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(500,0);
glVertex2f(500,500);
glVertex2f(0,500);
glEnd();*/

glBegin(GL_POLYGON);
glColor3f(0.659,0.855,0.863);
glVertex2f(0,500);
glColor3f(0.914,0.769,0.416);
glVertex2f(0,0);
glColor3f(0.914,0.769,0.416);
glVertex2f(500,0);
glColor3f(0.659,0.855,0.863);
glVertex2f(500,500);
glEnd();
//glFlush();

cloudBehindAirplane2();

//airplane
glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(o,0,0);
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
glTranslatef(o,0,0);
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
glTranslatef(o,0,0);
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
glTranslatef(o,0,0);
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
glTranslatef(o,0,0);
glBegin(GL_POLYGON);
glVertex2f(19,325);
glVertex2f(19,275);
glVertex2f(76,275);
glVertex2f(38,325);
glEnd();
//glFlush();
glPopMatrix();

cloudFrontAirplane2();

glFlush();

}
GLfloat q=0,r=0,s=0;
void update7(int value)
{
    q-=20;
    r+=2;
    s-=1;
    if(q<=-500)
        q=0;
	glutPostRedisplay();
	glutTimerFunc(100,update7,0);
}
void landing(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

//sky
glBegin(GL_POLYGON);
glColor3f(1,0.282,0);
glVertex2f(0,500);
glColor3f(1,0.71,0);
glVertex2f(0,20);
glColor3f(1,1,1);
glVertex2f(1000,0);
glColor3f(1,0.71,0);
glVertex2f(1000,500);
glEnd();

//building
glPushMatrix();
//glColor3f(0.518,0.824,0.965);
glColor3f(0.02,0.02,0.02);
glLineWidth(50);
glTranslatef(q,0,0);
glBegin(GL_LINES);
glVertex2f(0,375);
glVertex2f(0,0);
glVertex2f(19,300);
glVertex2f(19,0);
glVertex2f(38,275);
glVertex2f(38,0);
glVertex2f(57,350);
glVertex2f(57,0);
glVertex2f(76,250);
glVertex2f(76,0);
glVertex2f(95,250);
glVertex2f(95,0);
glVertex2f(114,300);
glVertex2f(114,0);
glVertex2f(133,350);
glVertex2f(133,0);
glVertex2f(152,275);
glVertex2f(152,0);
glVertex2f(171,325);
glVertex2f(171,0);
glVertex2f(190,375);
glVertex2f(190,0);
glVertex2f(209,325);
glVertex2f(209,0);
glVertex2f(228,275);
glVertex2f(228,0);
glVertex2f(247,350);
glVertex2f(247,0);
glVertex2f(266,375);
glVertex2f(266,0);
glVertex2f(285,325);
glVertex2f(285,0);
glVertex2f(304,275);
glVertex2f(304,0);
glVertex2f(323,300);
glVertex2f(323,0);
glVertex2f(342,350);
glVertex2f(342,0);
glVertex2f(361,300);
glVertex2f(361,0);
glVertex2f(380,350);
glVertex2f(380,0);
glVertex2f(399,275);
glVertex2f(399,0);
glVertex2f(418,325);
glVertex2f(418,0);
glVertex2f(437,375);
glVertex2f(437,0);
glVertex2f(456,325);
glVertex2f(456,0);
glVertex2f(475,275);
glVertex2f(475,0);
glVertex2f(494,350);
glVertex2f(494,0);
glVertex2f(500,375);
glVertex2f(500,0);
glVertex2f(519,300);
glVertex2f(519,0);
glVertex2f(538,275);
glVertex2f(538,0);
glVertex2f(557,350);
glVertex2f(557,0);
glVertex2f(576,250);
glVertex2f(576,0);
glVertex2f(595,250);
glVertex2f(595,0);
glVertex2f(614,300);
glVertex2f(614,0);
glVertex2f(633,350);
glVertex2f(633,0);
glVertex2f(652,275);
glVertex2f(652,0);
glVertex2f(671,325);
glVertex2f(671,0);
glVertex2f(690,375);
glVertex2f(690,0);
glVertex2f(709,325);
glVertex2f(709,0);
glVertex2f(728,275);
glVertex2f(728,0);
glVertex2f(747,350);
glVertex2f(747,0);
glVertex2f(766,375);
glVertex2f(766,0);
glVertex2f(785,325);
glVertex2f(785,0);
glVertex2f(804,275);
glVertex2f(804,0);
glVertex2f(823,300);
glVertex2f(823,0);
glVertex2f(842,350);
glVertex2f(842,0);
glVertex2f(861,300);
glVertex2f(861,0);
glVertex2f(880,350);
glVertex2f(880,0);
glVertex2f(899,275);
glVertex2f(899,0);
glVertex2f(918,325);
glVertex2f(918,0);
glVertex2f(937,375);
glVertex2f(937,0);
glVertex2f(956,325);
glVertex2f(956,0);
glVertex2f(975,275);
glVertex2f(975,0);
glVertex2f(1000,350);
glVertex2f(1000,0);
glEnd();
glPopMatrix();

//building
/*
glPushMatrix();
glColor3f(0.008,0.502,0.565);
glTranslatef(a,0,0);
for(int i=25;i>=10;i--){
draw_circle(256.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0,0.659,0.588);
glTranslatef(a,0,0);
for(int i=0;i<=10;i++){
draw_circle(237.5,250,i);
draw_circle(256.5,250,i);
draw_circle(275.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glTranslatef(a,0,0);
draw_circle(237.5,250,10);
draw_circle(256.5,250,10);
draw_circle(275.5,250,10);
glPopMatrix();

glPushMatrix();
glColor3f(0.008,0.765,0.604);
glTranslatef(a,0,0);
glBegin(GL_POLYGON);
glVertex2f(209,250);
glVertex2f(209,225);
glVertex2f(304,225);
glVertex2f(304,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glLineWidth(5);
glTranslatef(a,0,0);
glBegin(GL_LINES);
glVertex2f(209,245);
glVertex2f(304,245);
glEnd();
glPopMatrix();
*/

//grass
glColor3f(0.667,0.80,0);
glBegin(GL_POLYGON);
glVertex2f(0,225);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,225);
glEnd();

//tree
glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(10);
glTranslatef(q,0,0);
glBegin(GL_LINES);
glVertex2f(76,287.5);
glVertex2f(76,200);
glVertex2f(152,287.5);
glVertex2f(152,200);
glVertex2f(228,287.5);
glVertex2f(228,200);
glVertex2f(304,287.5);
glVertex2f(304,200);
glVertex2f(380,287.5);
glVertex2f(380,200);
glVertex2f(456,287.5);
glVertex2f(456,200);
glVertex2f(576,287.5);
glVertex2f(576,200);
glVertex2f(652,287.5);
glVertex2f(652,200);
glVertex2f(728,287.5);
glVertex2f(728,200);
glVertex2f(804,287.5);
glVertex2f(804,200);
glVertex2f(880,287.5);
glVertex2f(880,200);
glVertex2f(956,287.5);
glVertex2f(956,200);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(5);
glTranslatef(q,0,0);
glBegin(GL_LINES);
glVertex2f(57,250);
glVertex2f(76,225);
glVertex2f(76,225);
glVertex2f(95,250);
glVertex2f(133,250);
glVertex2f(152,225);
glVertex2f(152,225);
glVertex2f(171,250);
glVertex2f(209,250);
glVertex2f(228,225);
glVertex2f(228,225);
glVertex2f(247,250);
glVertex2f(285,250);
glVertex2f(304,225);
glVertex2f(304,225);
glVertex2f(323,250);
glVertex2f(361,250);
glVertex2f(380,225);
glVertex2f(380,225);
glVertex2f(399,250);
glVertex2f(437,250);
glVertex2f(456,225);
glVertex2f(456,225);
glVertex2f(475,250);
glVertex2f(557,250);
glVertex2f(576,225);
glVertex2f(576,225);
glVertex2f(595,250);
glVertex2f(633,250);
glVertex2f(652,225);
glVertex2f(652,225);
glVertex2f(671,250);
glVertex2f(709,250);
glVertex2f(728,225);
glVertex2f(728,225);
glVertex2f(747,250);
glVertex2f(785,250);
glVertex2f(804,225);
glVertex2f(804,225);
glVertex2f(823,250);
glVertex2f(861,250);
glVertex2f(880,225);
glVertex2f(880,225);
glVertex2f(899,250);
glVertex2f(937,250);
glVertex2f(956,225);
glVertex2f(956,225);
glVertex2f(975,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(3);
glTranslatef(q,0,0);
glBegin(GL_LINES);
glVertex2f(57,275);
glVertex2f(76,250);
glVertex2f(76,250);
glVertex2f(95,275);
glVertex2f(133,275);
glVertex2f(152,250);
glVertex2f(152,250);
glVertex2f(171,275);
glVertex2f(209,275);
glVertex2f(228,250);
glVertex2f(228,250);
glVertex2f(247,275);
glVertex2f(285,275);
glVertex2f(304,250);
glVertex2f(304,250);
glVertex2f(323,275);
glVertex2f(361,275);
glVertex2f(380,250);
glVertex2f(380,250);
glVertex2f(399,275);
glVertex2f(437,275);
glVertex2f(456,250);
glVertex2f(456,250);
glVertex2f(475,275);
glVertex2f(557,275);
glVertex2f(576,250);
glVertex2f(576,250);
glVertex2f(595,275);
glVertex2f(633,275);
glVertex2f(652,250);
glVertex2f(652,250);
glVertex2f(671,275);
glVertex2f(709,275);
glVertex2f(728,250);
glVertex2f(728,250);
glVertex2f(747,275);
glVertex2f(785,275);
glVertex2f(804,250);
glVertex2f(804,250);
glVertex2f(823,275);
glVertex2f(861,275);
glVertex2f(880,250);
glVertex2f(880,250);
glVertex2f(899,275);
glVertex2f(937,275);
glVertex2f(956,250);
glVertex2f(956,250);
glVertex2f(975,275);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.31,0.467,0.176);
glTranslatef(q,0,0);
for(int i=0;i<=10;i++){
draw_circle(76,287.5,i);
draw_circle(152,287.5,i);
draw_circle(228,287.5,i);
draw_circle(304,287.5,i);
draw_circle(380,287.5,i);
draw_circle(456,287.5,i);
draw_circle(576,287.5,i);
draw_circle(652,287.5,i);
draw_circle(728,287.5,i);
draw_circle(804,287.5,i);
draw_circle(880,287.5,i);
draw_circle(956,287.5,i);
draw_circle(57,250,i);
draw_circle(95,250,i);
draw_circle(133,250,i);
draw_circle(171,250,i);
draw_circle(209,250,i);
draw_circle(247,250,i);
draw_circle(285,250,i);
draw_circle(323,250,i);
draw_circle(361,250,i);
draw_circle(399,250,i);
draw_circle(437,250,i);
draw_circle(475,250,i);
draw_circle(557,250,i);
draw_circle(595,250,i);
draw_circle(633,250,i);
draw_circle(671,250,i);
draw_circle(709,250,i);
draw_circle(747,250,i);
draw_circle(785,250,i);
draw_circle(823,250,i);
draw_circle(861,250,i);
draw_circle(899,250,i);
draw_circle(937,250,i);
draw_circle(975,250,i);
}
for(int i=0;i<=5;i++){
draw_circle(57,275,i);
draw_circle(95,275,i);
draw_circle(133,275,i);
draw_circle(171,275,i);
draw_circle(209,275,i);
draw_circle(247,275,i);
draw_circle(285,275,i);
draw_circle(323,275,i);
draw_circle(361,275,i);
draw_circle(399,275,i);
draw_circle(437,275,i);
draw_circle(475,275,i);
draw_circle(557,275,i);
draw_circle(595,275,i);
draw_circle(633,275,i);
draw_circle(671,275,i);
draw_circle(709,275,i);
draw_circle(747,275,i);
draw_circle(785,275,i);
draw_circle(823,275,i);
draw_circle(861,275,i);
draw_circle(899,275,i);
draw_circle(937,275,i);
draw_circle(975,275,i);
}
glPopMatrix();

//mid road
/*glPushMatrix();
glColor3f(0.604,0.561,0.592);
glTranslatef(a,0,0);
glBegin(GL_POLYGON);
glVertex2f(95,225);
glVertex2f(76,200);
glVertex2f(76,0);
glVertex2f(190,0);
glVertex2f(190,200);
glVertex2f(171,225);
glEnd();
glPopMatrix();*/

//road
glColor3f(0.604,0.561,0.592);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,200);
glEnd();

glColor3f(0.451,0.435,0.447);
glBegin(GL_POLYGON);
glVertex2f(0,130);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,130);
glEnd();

//land
glColor3f(0.266,0.215,0.258);
glBegin(GL_POLYGON);
glVertex2f(0,75);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,75);
glEnd();

glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(5);
glTranslatef(q,0,0);
glBegin(GL_LINES);
glVertex2f(0,197.5);
//glVertex2f(77,197.5);
//glVertex2f(190,197.5);
glVertex2f(1000,195.5);
glEnd();
glPopMatrix();

/*glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(3);
glTranslatef(a,0,0);
glBegin(GL_LINES);
glVertex2f(77,199);
glVertex2f(96,225);
glVertex2f(191,198);
glVertex2f(172,225);
glEnd();
glPopMatrix();*/

glPushMatrix();
glColor3f(1,1,1);
glLineWidth(7);
glTranslatef(q,0,0);
glBegin(GL_LINES);
glVertex2f(38,162.5);
glVertex2f(76,162.5);
glVertex2f(95,162.5);
glVertex2f(133,162.5);
glVertex2f(152,162.5);
glVertex2f(190,162.5);
glVertex2f(209,162.5);
glVertex2f(247,162.5);
glVertex2f(266,162.5);
glVertex2f(304,162.5);
glVertex2f(323,162.5);
glVertex2f(361,162.5);
glVertex2f(380,162.5);
glVertex2f(418,162.5);
glVertex2f(437,162.5);
glVertex2f(475,162.5);
glVertex2f(538,162.5);
glVertex2f(576,162.5);
glVertex2f(595,162.5);
glVertex2f(633,162.5);
glVertex2f(652,162.5);
glVertex2f(690,162.5);
glVertex2f(709,162.5);
glVertex2f(747,162.5);
glVertex2f(766,162.5);
glVertex2f(804,162.5);
glVertex2f(823,162.5);
glVertex2f(861,162.5);
glVertex2f(880,162.5);
glVertex2f(918,162.5);
glVertex2f(937,162.5);
glVertex2f(975,162.5);
glEnd();
glPopMatrix();

//airplane
glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(r,s,0);
glBegin(GL_POLYGON);
glVertex2f(38,475);
glVertex2f(38,425);
glVertex2f(76,425);
glVertex2f(48,475);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(r,s,0);
glBegin(GL_POLYGON);
glVertex2f(76,450);
glVertex2f(95,425);
glVertex2f(114,425);
glVertex2f(86,450);
glEnd();
glPopMatrix();

/*glPushMatrix();
glColor3f(0,0,0);
glLineWidth(2);
glTranslatef(b,c,0);
glBegin(GL_LINES);
glVertex2f(67,175);
glVertex2f(67,137);
glVertex2f(134,137);
glVertex2f(134,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(b,c,0);
for(int i=0;i<=5;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(b,c,0);
for(int i=0;i<=2;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();
*/

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(r,s,0);
glBegin(GL_POLYGON);
glVertex2f(38,437.5);
glVertex2f(38,400);
glVertex2f(152,400);
glVertex2f(171,412.5);
glVertex2f(167,417);
glVertex2f(152,435.5);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(r,s,0);
glBegin(GL_POLYGON);
glVertex2f(95,425);
glVertex2f(76,387.5);
glVertex2f(86,387.5);
glVertex2f(114,425);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(r,s,0);
glBegin(GL_POLYGON);
glVertex2f(149,412.5);
glVertex2f(149,400);
glVertex2f(152,400);
glVertex2f(171,412.5);
glEnd();
glPopMatrix();

glFlush();
}
GLfloat t=0,u=0;
void update8(int value)
{
    t-=20;
    u+=2;
    if(t<=-500)
        t=0;
	glutPostRedisplay();
	glutTimerFunc(100,update8,0);
}
void runway2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

//sky
glBegin(GL_POLYGON);
glColor3f(1,0.282,0);
glVertex2f(0,500);
glColor3f(1,0.71,0);
glVertex2f(0,20);
glColor3f(1,0.71,0);
glVertex2f(1000,0);
glColor3f(1,0.282,0);
glVertex2f(1000,500);
glEnd();

//building
glPushMatrix();
//glColor3f(0.518,0.824,0.965);
//glColor3f(0.60,0.757,0.871);
glColor3f(0.02,0.02,0.02);
glLineWidth(50);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(0,375);
glVertex2f(0,0);
glVertex2f(19,300);
glVertex2f(19,0);
glVertex2f(38,275);
glVertex2f(38,0);
glVertex2f(57,350);
glVertex2f(57,0);
glVertex2f(76,250);
glVertex2f(76,0);
glVertex2f(95,250);
glVertex2f(95,0);
glVertex2f(114,300);
glVertex2f(114,0);
glVertex2f(133,350);
glVertex2f(133,0);
glVertex2f(152,275);
glVertex2f(152,0);
glVertex2f(171,325);
glVertex2f(171,0);
glVertex2f(190,375);
glVertex2f(190,0);
glVertex2f(209,325);
glVertex2f(209,0);
glVertex2f(228,275);
glVertex2f(228,0);
glVertex2f(247,350);
glVertex2f(247,0);
glVertex2f(266,375);
glVertex2f(266,0);
glVertex2f(285,325);
glVertex2f(285,0);
glVertex2f(304,275);
glVertex2f(304,0);
glVertex2f(323,300);
glVertex2f(323,0);
glVertex2f(342,350);
glVertex2f(342,0);
glVertex2f(361,300);
glVertex2f(361,0);
glVertex2f(380,350);
glVertex2f(380,0);
glVertex2f(399,275);
glVertex2f(399,0);
glVertex2f(418,325);
glVertex2f(418,0);
glVertex2f(437,375);
glVertex2f(437,0);
glVertex2f(456,325);
glVertex2f(456,0);
glVertex2f(475,275);
glVertex2f(475,0);
glVertex2f(494,350);
glVertex2f(494,0);
glVertex2f(500,375);
glVertex2f(500,0);
glVertex2f(519,300);
glVertex2f(519,0);
glVertex2f(538,275);
glVertex2f(538,0);
glVertex2f(557,350);
glVertex2f(557,0);
glVertex2f(576,250);
glVertex2f(576,0);
glVertex2f(595,250);
glVertex2f(595,0);
glVertex2f(614,300);
glVertex2f(614,0);
glVertex2f(633,350);
glVertex2f(633,0);
glVertex2f(652,275);
glVertex2f(652,0);
glVertex2f(671,325);
glVertex2f(671,0);
glVertex2f(690,375);
glVertex2f(690,0);
glVertex2f(709,325);
glVertex2f(709,0);
glVertex2f(728,275);
glVertex2f(728,0);
glVertex2f(747,350);
glVertex2f(747,0);
glVertex2f(766,375);
glVertex2f(766,0);
glVertex2f(785,325);
glVertex2f(785,0);
glVertex2f(804,275);
glVertex2f(804,0);
glVertex2f(823,300);
glVertex2f(823,0);
glVertex2f(842,350);
glVertex2f(842,0);
glVertex2f(861,300);
glVertex2f(861,0);
glVertex2f(880,350);
glVertex2f(880,0);
glVertex2f(899,275);
glVertex2f(899,0);
glVertex2f(918,325);
glVertex2f(918,0);
glVertex2f(937,375);
glVertex2f(937,0);
glVertex2f(956,325);
glVertex2f(956,0);
glVertex2f(975,275);
glVertex2f(975,0);
glVertex2f(1000,350);
glVertex2f(1000,0);
glEnd();
glPopMatrix();

//building
glPushMatrix();
glColor3f(0.008,0.502,0.565);
glTranslatef(t,0,0);
for(int i=25;i>=10;i--){
draw_circle(256.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0,0.659,0.588);
glTranslatef(t,0,0);
for(int i=0;i<=10;i++){
draw_circle(237.5,250,i);
draw_circle(256.5,250,i);
draw_circle(275.5,250,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glTranslatef(t,0,0);
draw_circle(237.5,250,10);
draw_circle(256.5,250,10);
draw_circle(275.5,250,10);
glPopMatrix();

glPushMatrix();
glColor3f(0.008,0.765,0.604);
glTranslatef(t,0,0);
glBegin(GL_POLYGON);
glVertex2f(209,250);
glVertex2f(209,225);
glVertex2f(304,225);
glVertex2f(304,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.02,0.4,0.553);
glLineWidth(5);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(209,245);
glVertex2f(304,245);
glEnd();
glPopMatrix();

//grass
glColor3f(0.667,0.80,0);
glBegin(GL_POLYGON);
glVertex2f(0,225);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,225);
glEnd();

//tree
glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(10);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(76,287.5);
glVertex2f(76,200);
glVertex2f(228,287.5);
glVertex2f(228,200);
glVertex2f(304,287.5);
glVertex2f(304,200);
glVertex2f(380,287.5);
glVertex2f(380,200);
glVertex2f(456,287.5);
glVertex2f(456,200);
glVertex2f(576,287.5);
glVertex2f(576,200);
glVertex2f(652,287.5);
glVertex2f(652,200);
glVertex2f(728,287.5);
glVertex2f(728,200);
glVertex2f(804,287.5);
glVertex2f(804,200);
glVertex2f(880,287.5);
glVertex2f(880,200);
glVertex2f(956,287.5);
glVertex2f(956,200);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(5);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(57,250);
glVertex2f(76,225);
glVertex2f(76,225);
glVertex2f(95,250);
glVertex2f(209,250);
glVertex2f(228,225);
glVertex2f(228,225);
glVertex2f(247,250);
glVertex2f(285,250);
glVertex2f(304,225);
glVertex2f(304,225);
glVertex2f(323,250);
glVertex2f(361,250);
glVertex2f(380,225);
glVertex2f(380,225);
glVertex2f(399,250);
glVertex2f(437,250);
glVertex2f(456,225);
glVertex2f(456,225);
glVertex2f(475,250);
glVertex2f(557,250);
glVertex2f(576,225);
glVertex2f(576,225);
glVertex2f(595,250);
glVertex2f(633,250);
glVertex2f(652,225);
glVertex2f(652,225);
glVertex2f(671,250);
glVertex2f(709,250);
glVertex2f(728,225);
glVertex2f(728,225);
glVertex2f(747,250);
glVertex2f(785,250);
glVertex2f(804,225);
glVertex2f(804,225);
glVertex2f(823,250);
glVertex2f(861,250);
glVertex2f(880,225);
glVertex2f(880,225);
glVertex2f(899,250);
glVertex2f(937,250);
glVertex2f(956,225);
glVertex2f(956,225);
glVertex2f(975,250);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.60,0.345,0.165);
glLineWidth(3);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(57,275);
glVertex2f(76,250);
glVertex2f(76,250);
glVertex2f(95,275);
glVertex2f(209,275);
glVertex2f(228,250);
glVertex2f(228,250);
glVertex2f(247,275);
glVertex2f(285,275);
glVertex2f(304,250);
glVertex2f(304,250);
glVertex2f(323,275);
glVertex2f(361,275);
glVertex2f(380,250);
glVertex2f(380,250);
glVertex2f(399,275);
glVertex2f(437,275);
glVertex2f(456,250);
glVertex2f(456,250);
glVertex2f(475,275);
glVertex2f(557,275);
glVertex2f(576,250);
glVertex2f(576,250);
glVertex2f(595,275);
glVertex2f(633,275);
glVertex2f(652,250);
glVertex2f(652,250);
glVertex2f(671,275);
glVertex2f(709,275);
glVertex2f(728,250);
glVertex2f(728,250);
glVertex2f(747,275);
glVertex2f(785,275);
glVertex2f(804,250);
glVertex2f(804,250);
glVertex2f(823,275);
glVertex2f(861,275);
glVertex2f(880,250);
glVertex2f(880,250);
glVertex2f(899,275);
glVertex2f(937,275);
glVertex2f(956,250);
glVertex2f(956,250);
glVertex2f(975,275);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.31,0.467,0.176);
glTranslatef(t,0,0);
for(int i=0;i<=10;i++){
draw_circle(76,287.5,i);
draw_circle(228,287.5,i);
draw_circle(304,287.5,i);
draw_circle(380,287.5,i);
draw_circle(456,287.5,i);
draw_circle(576,287.5,i);
draw_circle(652,287.5,i);
draw_circle(728,287.5,i);
draw_circle(804,287.5,i);
draw_circle(880,287.5,i);
draw_circle(956,287.5,i);
draw_circle(57,250,i);
draw_circle(95,250,i);
draw_circle(209,250,i);
draw_circle(247,250,i);
draw_circle(285,250,i);
draw_circle(323,250,i);
draw_circle(361,250,i);
draw_circle(399,250,i);
draw_circle(437,250,i);
draw_circle(475,250,i);
draw_circle(557,250,i);
draw_circle(595,250,i);
draw_circle(633,250,i);
draw_circle(671,250,i);
draw_circle(709,250,i);
draw_circle(747,250,i);
draw_circle(785,250,i);
draw_circle(823,250,i);
draw_circle(861,250,i);
draw_circle(899,250,i);
draw_circle(937,250,i);
draw_circle(975,250,i);
}
for(int i=0;i<=5;i++){
draw_circle(57,275,i);
draw_circle(95,275,i);
draw_circle(209,275,i);
draw_circle(247,275,i);
draw_circle(285,275,i);
draw_circle(323,275,i);
draw_circle(361,275,i);
draw_circle(399,275,i);
draw_circle(437,275,i);
draw_circle(475,275,i);
draw_circle(557,275,i);
draw_circle(595,275,i);
draw_circle(633,275,i);
draw_circle(671,275,i);
draw_circle(709,275,i);
draw_circle(747,275,i);
draw_circle(785,275,i);
draw_circle(823,275,i);
draw_circle(861,275,i);
draw_circle(899,275,i);
draw_circle(937,275,i);
draw_circle(975,275,i);
}
glPopMatrix();

//mid road
glPushMatrix();
glColor3f(0.604,0.561,0.592);
glTranslatef(t,0,0);
glBegin(GL_POLYGON);
glVertex2f(95,225);
glVertex2f(76,200);
glVertex2f(76,0);
glVertex2f(190,0);
glVertex2f(190,200);
glVertex2f(171,225);
glEnd();
glPopMatrix();

//road
glColor3f(0.604,0.561,0.592);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,200);
glEnd();

glColor3f(0.451,0.435,0.447);
glBegin(GL_POLYGON);
glVertex2f(0,130);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,130);
glEnd();

//land
glColor3f(0.266,0.215,0.258);
glBegin(GL_POLYGON);
glVertex2f(0,75);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,75);
glEnd();

glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(5);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(0,197.5);
glVertex2f(77,197.5);
glVertex2f(190,197.5);
glVertex2f(1000,195.5);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.266,0.215,0.258);
glLineWidth(3);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(77,199);
glVertex2f(96,225);
glVertex2f(191,198);
glVertex2f(172,225);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glLineWidth(7);
glTranslatef(t,0,0);
glBegin(GL_LINES);
glVertex2f(38,162.5);
glVertex2f(76,162.5);
glVertex2f(209,162.5);
glVertex2f(247,162.5);
glVertex2f(266,162.5);
glVertex2f(304,162.5);
glVertex2f(323,162.5);
glVertex2f(361,162.5);
glVertex2f(380,162.5);
glVertex2f(418,162.5);
glVertex2f(437,162.5);
glVertex2f(475,162.5);
glVertex2f(538,162.5);
glVertex2f(576,162.5);
glVertex2f(595,162.5);
glVertex2f(633,162.5);
glVertex2f(652,162.5);
glVertex2f(690,162.5);
glVertex2f(709,162.5);
glVertex2f(747,162.5);
glVertex2f(766,162.5);
glVertex2f(804,162.5);
glVertex2f(823,162.5);
glVertex2f(861,162.5);
glVertex2f(880,162.5);
glVertex2f(918,162.5);
glVertex2f(937,162.5);
glVertex2f(975,162.5);
glEnd();
glPopMatrix();

//airplane
glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(u,0,0);
glBegin(GL_POLYGON);
glVertex2f(38,225);
glVertex2f(38,175);
glVertex2f(76,175);
glVertex2f(48,225);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(u,0,0);
glBegin(GL_POLYGON);
glVertex2f(76,200);
glVertex2f(95,175);
glVertex2f(114,175);
glVertex2f(86,200);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glLineWidth(2);
glTranslatef(u,0,0);
glBegin(GL_LINES);
glVertex2f(67,175);
glVertex2f(67,137);
glVertex2f(134,137);
glVertex2f(134,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0,0,0);
glTranslatef(u,0,0);
for(int i=0;i<=5;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(u,0,0);
for(int i=0;i<=2;i++){
draw_circle(67,137.5,i);
draw_circle(134,137.5,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(u,0,0);
glBegin(GL_POLYGON);
glVertex2f(38,187.5);
glVertex2f(38,150);
glVertex2f(152,150);
glVertex2f(171,162.5);
glVertex2f(167,167);
glVertex2f(152,185.5);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(u,0,0);
glBegin(GL_POLYGON);
glVertex2f(95,175);
glVertex2f(76,137.5);
glVertex2f(86,137.5);
glVertex2f(114,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(u,0,0);
glBegin(GL_POLYGON);
glVertex2f(149,162.5);
glVertex2f(149,150);
glVertex2f(152,150);
glVertex2f(171,162.5);
glEnd();
glPopMatrix();

glFlush();
}
GLfloat v=0,w=0,x=0;
void update9(int value)
{
    v+=0;
	w-=0;
	x-=10;
	if(x<=-120)
        x=0;
	v+=0;
	w-=0;
	if(w>=-75)
        w-=5;
    if(w<-75)
        v+=15;
    if(v>=150){
        v=0;
        w=0;
    }
	glutPostRedisplay();
	glutTimerFunc(100,update9,0);
}
void human_disembark(){

/*glPushMatrix();
glColor3f(0,0,0);
glTranslatef(c,d,0);
for(int i=1;i<=5;i++){
draw_circle(209,50,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,0.804,0.698);
glLineWidth(10);
glTranslatef(c,d,0);
glBegin(GL_LINES);
glVertex2f(203,45);
glVertex2f(197,20);
glVertex2f(215,45);
glVertex2f(221,20);
glVertex2f(205,25);
glVertex2f(205,5);
glVertex2f(213,25);
glVertex2f(213,5);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.741,0.698,1);
glLineWidth(35);
glTranslatef(c,d,0);
glBegin(GL_LINES);
glVertex2f(209,45);
glVertex2f(209,25);
glEnd();
//glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.51,0.70,0.60);
glLineWidth(10);
glTranslatef(c,d,0);
glBegin(GL_POLYGON);
glVertex2f(218,37.5);
glVertex2f(218,0);
glVertex2f(228,0);
glVertex2f(228,37.5);
glEnd();
//glFlush();
glPopMatrix();
*/
glPushMatrix();
glColor3f(0,0,0);
glTranslatef(v,w,0);
for(int i=1;i<=5;i++){
draw_circle(361,125,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,0.804,0.698);
glTranslatef(v,w,0);
for(int i=1;i<=3;i++){
draw_circle(361,120,i);
}
glPopMatrix();

glPushMatrix();
glColor3f(1,0.686,0.80);
glLineWidth(35);
glTranslatef(v,w,0);
glBegin(GL_LINES);
glVertex2f(361,120);
glVertex2f(361,100);
glEnd();
glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(1,0.804,0.698);
glLineWidth(10);
glTranslatef(v,w,0);
glBegin(GL_LINES);
glVertex2f(355,120);
glVertex2f(349,90);
glVertex2f(367,120);
glVertex2f(373,90);
glVertex2f(357,100);
glVertex2f(357,80);
glVertex2f(365,100);
glVertex2f(365,80);
glEnd();
glFlush();
glPopMatrix();

glPushMatrix();
glColor3f(0.988,0.639,0.067); //361 266
glLineWidth(10);
glTranslatef(v,w,0);
glBegin(GL_POLYGON);
glVertex2f(342,112.5);
glVertex2f(342,75);
glVertex2f(352,75);
glVertex2f(352,112.5);
glEnd();
glPopMatrix();

}
void cloud_disembark(){
glPushMatrix();
glColor3f(0.15,0.15,0.15);
glTranslatef(x,0,0);
for(int i=1;i<=27;i++){
draw_circle(276,425,i);
}
for(int i=1;i<=19;i++){
draw_circle(257,425,i);
}
for(int i=1;i<=19;i++){
draw_circle(295,425,i);
}
for(int i=1;i<=20;i++){
draw_circle(361,450,i);
}
for(int i=1;i<=15;i++){
draw_circle(350,450,i);
}
for(int i=1;i<=15;i++){
draw_circle(374,450,i);
}
glPopMatrix();


}
void disembark(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

//sky

glBegin(GL_POLYGON);
//glColor3f(0.341,0.063,0.537);
glColor3f(0.141,0,0.275);
glVertex2f(0,500);
glColor3f(0.918,0.412,0.545);
glVertex2f(0,200);
glColor3f(0.918,0.412,0.545);
glVertex2f(500,200);
//glColor3f(0.341,0.063,0.537);
glColor3f(0.141,0,0.275);
glVertex2f(500,500);
glEnd();
//glFlush();

cloud_disembark();
//grass
glColor3f(0.22,0.69,0);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(0,175);
glVertex2f(500,175);
glVertex2f(500,200);
glEnd();
//glFlush();

//plants
glColor3f(0,0.502,0);
glBegin(GL_POLYGON);
glVertex2f(0,212.5);
glVertex2f(0,200);
glVertex2f(38,200);
glEnd();
//glFlush();

glColor3f(0,0.502,0);
glBegin(GL_POLYGON);
glVertex2f(0,200);
glVertex2f(38,225);
glVertex2f(57,225);
glVertex2f(95,200);
glEnd();
//glFlush();

glColor3f(0,0.502,0);
glBegin(GL_POLYGON);
glVertex2f(76,200);
glVertex2f(133,225);
glVertex2f(304,225);
glVertex2f(380,200);
glEnd();
//glFlush();

//road
glColor3f(0.125,0.15,0.225);
glBegin(GL_POLYGON);
glVertex2f(0,175);
glVertex2f(0,150);
glVertex2f(500,150);
glVertex2f(500,175);
glEnd();
//glFlush();

glColor3f(0.133,0.20,0.231);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,0);
glVertex2f(500,0);
glVertex2f(500,150);
glEnd();
//glFlush();

//buildings
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(418,350);
glVertex2f(408,325);
glVertex2f(408,200);
glVertex2f(418,200);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(351,425);
glVertex2f(351,400);
glVertex2f(390,400);
glVertex2f(390,425);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(342,400);
glVertex2f(342,200);
glVertex2f(399,200);
glVertex2f(399,400);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(342,400);
glVertex2f(342,200);
glVertex2f(380,200);
glVertex2f(361,400);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(399,300);
glVertex2f(399,200);
glVertex2f(418,200);
glVertex2f(405,300);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(418,400);
glVertex2f(418,200);
glVertex2f(475,200);
glVertex2f(475,375);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(418,400);
glVertex2f(418,200);
glVertex2f(475,200);
glVertex2f(475,300);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(456,300);
glVertex2f(456,200);
glVertex2f(494,200);
glVertex2f(494,350);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(494,350);
glVertex2f(475,275);
glVertex2f(475,200);
glVertex2f(494,200);
glEnd();
//glFlush();

glColor3f(0.275,0.561,0.686);
glBegin(GL_POLYGON);
glVertex2f(475,275);
glVertex2f(475,200);
glVertex2f(500,200);
glVertex2f(500,250);
glEnd();
//glFlush();

glColor3f(0.165,0.435,0.592);
glBegin(GL_POLYGON);
glVertex2f(475,275);
glVertex2f(475,200);
glVertex2f(500,200);
glVertex2f(500,225);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2f(342,400);
glVertex2f(399,400);
glVertex2f(418,400);
glVertex2f(475,375);
glVertex2f(456,300);
glVertex2f(494,350);
glVertex2f(475,275);
glVertex2f(500,250);
glEnd();
//glFlush();

//main building
glColor3f(0.031,0.60,0.729);
glBegin(GL_POLYGON);
glVertex2f(95,325);
glVertex2f(114,200);
glVertex2f(323,200);
glVertex2f(342,325);
glEnd();
//glFlush();

glColor3f(0.125,0.729,0.772);
glBegin(GL_POLYGON);
glVertex2f(98,300);
glVertex2f(114,200);
glVertex2f(323,200);
glVertex2f(339,300);
glEnd();
//glFlush();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(76,350);
glVertex2f(76,325);
glVertex2f(361,325);
glVertex2f(361,350);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(95,325);
glVertex2f(171,200);
glVertex2f(209,200);
glVertex2f(133,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(171,325);
glVertex2f(238,200);
glVertex2f(247,200);
glVertex2f(181,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(209,325);
glVertex2f(266,200);
glVertex2f(285,200);
glVertex2f(228,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(238,325);
glVertex2f(295,200);
glVertex2f(323,200);
glVertex2f(266,325);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(295,325);
glVertex2f(331,250);
glVertex2f(333,275);
glVertex2f(304,325);
glEnd();
//glFlush();

glColor3f(0.369,0.392,0.447);
glBegin(GL_POLYGON);
glVertex2f(133,400);
glVertex2f(133,350);
glVertex2f(152,350);
glVertex2f(152,400);
glEnd();
//glFlush();

glColor3f(0.49,0.522,0.592);
glBegin(GL_POLYGON);
glVertex2f(133,475);
glVertex2f(133,400);
glVertex2f(152,400);
glVertex2f(152,475);
glEnd();
//glFlush();

glColor3f(0.125,0.729,0.772);
glBegin(GL_POLYGON);
glVertex2f(133,462.5);
glVertex2f(114,450);
glVertex2f(119,400);
glVertex2f(164,400);
glVertex2f(171,450);
glVertex2f(152,462.5);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(114,450);
glVertex2f(133,400);
glVertex2f(135,400);
glVertex2f(124,450);
glEnd();
//glFlush();

glColor3f(0.384,0.714,0.796);
glBegin(GL_POLYGON);
glVertex2f(133,450);
glVertex2f(152,400);
glVertex2f(163,425);
glVertex2f(152,450);
glEnd();
//glFlush();

glColor3f(0.49,0.522,0.592);
glBegin(GL_POLYGON);
glVertex2f(109,455);
glVertex2f(109,450);
glVertex2f(176,450);
glVertex2f(176,455);
glEnd();
//glFlush();

glColor3f(0.49,0.522,0.592);
glBegin(GL_POLYGON);
glVertex2f(119,400);
glVertex2f(114,387.5);
glVertex2f(171,387.5);
glVertex2f(164,400);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(1);
glBegin(GL_LINES);
glVertex2f(114,325);
glVertex2f(114,200);
glVertex2f(133,325);
glVertex2f(133,200);
glVertex2f(152,325);
glVertex2f(152,200);
glVertex2f(171,325);
glVertex2f(171,200);
glVertex2f(190,325);
glVertex2f(190,200);
glVertex2f(209,325);
glVertex2f(209,200);
glVertex2f(228,325);
glVertex2f(228,200);
glVertex2f(247,325);
glVertex2f(247,200);
glVertex2f(266,325);
glVertex2f(266,200);
glVertex2f(285,325);
glVertex2f(285,200);
glVertex2f(304,325);
glVertex2f(304,200);
glVertex2f(323,325);
glVertex2f(323,200);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2f(133,250);
glVertex2f(133,200);
glVertex2f(171,250);
glVertex2f(171,200);
glVertex2f(200,250);
glVertex2f(200,200);
glVertex2f(238,250);
glVertex2f(238,200);
glVertex2f(266,250);
glVertex2f(266,200);
glVertex2f(304,250);
glVertex2f(304,200);
glVertex2f(133,250);
glVertex2f(171,250);
glVertex2f(200,250);
glVertex2f(238,250);
glVertex2f(266,250);
glVertex2f(304,250);
glEnd();
//glFlush();

//lights
glColor3f(0.424,0.459,0.49);
glLineWidth(3);
glBegin(GL_LINES);
glVertex2f(76,275);
glVertex2f(76,200);
glVertex2f(133,275);
glVertex2f(133,200);
glVertex2f(323,275);
glVertex2f(323,200);
glVertex2f(380,275);
glVertex2f(380,200);
glEnd();
//glFlush();

glColor3f(0.424,0.459,0.49);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2f(76,250);
glVertex2f(76,200);
glVertex2f(133,250);
glVertex2f(133,200);
glVertex2f(323,250);
glVertex2f(323,200);
glVertex2f(380,250);
glVertex2f(380,200);
glEnd();
//glFlush();

glColor3f(1,0.835,0);
glLineWidth(10);
glBegin(GL_LINES);
glVertex2f(95,287.5);
glVertex2f(76,275);
glVertex2f(152,287.5);
glVertex2f(133,275);
glVertex2f(304,287.5);
glVertex2f(323,275);
glVertex2f(361,285.5);
glVertex2f(380,275);
glEnd();
//glFlush();

glColor3f(0.424,0.459,0.49);
glLineWidth(3);
glBegin(GL_LINES);
glVertex2f(95,287.5);
glVertex2f(76,275);
glVertex2f(152,287.5);
glVertex2f(133,275);
glVertex2f(304,287.5);
glVertex2f(323,275);
glVertex2f(361,285.5);
glVertex2f(380,275);
glEnd();
//glFlush();

//airplane
glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(76,300);
glVertex2f(95,175);
glVertex2f(152,175);
glVertex2f(95,290);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(133,200);
glVertex2f(133,175);
glVertex2f(171,175);
glEnd();
//glFlush();

glColor3f(0,0,0);
glLineWidth(25);
glBegin(GL_LINES);
glVertex2f(209,100);
glVertex2f(209,73);
glVertex2f(399,100);
glVertex2f(399,73);
glEnd();
//glFlush();

glColor3f(0,0,0);
draw_circle(209,62.5,10);
draw_circle(399,62.5,10);

glColor3f(1,1,1);
draw_circle(209,62.5,5);
draw_circle(399,62.5,5);

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(76,175);
glVertex2f(67,162.5);
glVertex2f(171,100);
glVertex2f(380,85);
glVertex2f(437,100);
glVertex2f(447,112.5);
glVertex2f(447,137.5);
glVertex2f(380,187.5);
glEnd();
//glFlush();

glColor3f(0,0.706,0.847);
glBegin(GL_POLYGON);
glVertex2f(399,175);
glVertex2f(380,175);
glVertex2f(410,150);
glVertex2f(429,150);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(67,187.5);
glVertex2f(76,162.5);
glVertex2f(114,150);
glVertex2f(124,160);
glEnd();
//glFlush();

glColor3f(0,0.706,0.847);
glLineWidth(25);
glBegin(GL_LINES);
glVertex2f(171,150);
glVertex2f(171,137.5);
glVertex2f(190,150);
glVertex2f(190,137.5);
glVertex2f(209,150);
glVertex2f(209,137.5);
glVertex2f(228,150);
glVertex2f(228,137.5);
glVertex2f(247,150);
glVertex2f(247,137.5);
glVertex2f(266,150);
glVertex2f(266,137.5);
glVertex2f(285,150);
glVertex2f(285,137.5);
glVertex2f(304,150);
glVertex2f(304,137.5);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(190,175);
glVertex2f(190,137.5);
glVertex2f(209,98);
glVertex2f(209,125);
glEnd();
//glFlush();

glColor3f(0.839,0.157,0.157);
glBegin(GL_POLYGON);
glVertex2f(209,97);
glVertex2f(380,85);
glVertex2f(190,137.5);
glEnd();
//glFlush();

glColor3f(0.424,0.459,0.49);
glBegin(GL_POLYGON);
glVertex2f(342,150);
glVertex2f(342,87.5);
glVertex2f(380,87.5);
glVertex2f(380,150);
glEnd();
//glFlush();

glColor3f(0.678,0.71,0.741);
glBegin(GL_POLYGON);
glVertex2f(380,87.5);
glVertex2f(342,85.5);
glVertex2f(342,25);
glVertex2f(380,25);
glEnd();
//glFlush();

glColor3f(1,1,1);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(342,25);
glVertex2f(380,25);
glVertex2f(342,37.5);
glVertex2f(380,37.5);
glVertex2f(342,50);
glVertex2f(380,50);
glVertex2f(342,62.5);
glVertex2f(380,62.5);
glVertex2f(342,75);
glVertex2f(380,75);
glVertex2f(342,87.5);
glVertex2f(380,87.5);
glEnd();
//glFlush();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(342,100);
glVertex2f(342,25);
glVertex2f(380,100);
glVertex2f(380,25);
glEnd();
//glFlush();

glColor3f(0.960,0.952,0.956);
glBegin(GL_POLYGON);
glVertex2f(285,100);
glVertex2f(255,100);
glVertex2f(228,87.5);
glVertex2f(255,75);
glVertex2f(285,75);
glEnd();
//glFlush();

glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(285,100);
glVertex2f(255,100);
glVertex2f(255,75);
glVertex2f(285,75);
glEnd();
//glFlush();

glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(285,100);
glVertex2f(285,75);
glVertex2f(290,80);
glVertex2f(290,95);
glEnd();
//glFlush();

//human
human_disembark();

glFlush();

}
void inside(void)
{
   // mciSendString("airplane_anouncement.wav alias bkmusic",NULL,0,NULL);
    //mciSendString("play bkmusic",NULL,0,NULL);
	glClear(GL_COLOR_BUFFER_BIT);//clears buffer to preset values.Clear window.

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(0.0, 0.0, 1.0, 0.9); //the whole plane

			glBegin(GL_POLYGON);
            glVertex2f(0,0);
            glVertex2f(0,500);
            glVertex2f(500,500);
			glVertex2f(500,0);
			glEnd();
			//glFlush();

			glColor3f(0.7,0.7,0.7);  //the ceiling top
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
			glVertex2f(235,490);//vertex1
			glVertex2f(225,500);//vertex2
			glVertex2f(275,500);//vertex 3
			glVertex2f(265,490);//vertex4
			glEnd();
			//glFlush();//draw all objects

            glColor3f(0.7,0.7,0.7);
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
			glVertex2f(235,470);//vertex1
			glVertex2f(225,480);//vertex2
			glVertex2f(275,480);//vertex 3
			glVertex2f(265,470);//vertex4
			glEnd();
			//glFlush();//draw all objects

            glColor3f(0.7,0.7,0.7);    //the ceiling
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
			glVertex2f(235,450);//vertex1
			glVertex2f(225,460);//vertex2
			glVertex2f(275,460);//vertex 3
			glVertex2f(265,450);//vertex4
			glEnd();
			//glFlush();//draw all objects

			/*glColor3f(0.0,1.0,1.0);  //the pathway
			glBegin(GL_LINES);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(200,430);
            glVertex2f(300,430);
            glVertex2f(200,430);
            glVertex2f(100,200);
            glVertex2f(300,430);
            glVertex2f(400,200);
			glEnd();
			glFlush();//draw all objects*/

            glColor3f(0.6,0.6,0.6);  //the door
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(225,200);
            glVertex2f(225,400);
			glVertex2f(275,400);
			glVertex2f(275,200);
			glEnd();
			//glFlush();//draw all objects

			glColor3f(1,0.9,0.8);  //the luggage keeper above left first box
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(100,500);
            glVertex2f(200,430);
			glVertex2f(190,400);
			glVertex2f(50,500);
			glEnd();
			//glFlush();//draw all objects

			glColor3f(1,0.9,0.8);  //the luggage keeper above rigth first box
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(400,500);
            glVertex2f(300,430);
			glVertex2f(310,400);
			glVertex2f(450,500);
			glEnd();
			//glFlush();//draw all objects



			/*glColor3f(0.6,0.6,0.6);  //the luggage keeper above left second box
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(0,500);
            glVertex2f(180,380);
			glVertex2f(190,400);
			glVertex2f(50,500);
			glEnd();
			glFlush();//draw all objects

			glColor3f(0.7,0.7,0.7);  //the luggage keeper above right second box
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(450,500);
            glVertex2f(310,400);
			glVertex2f(320,380);
			glVertex2f(500,500);
			glEnd();
			glFlush();//draw all objects*/

           glColor3f(0.9,0.8,0.5);  //the luggage keeper above left third box
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(0,500);
            glVertex2f(120,380);
			glVertex2f(170,360);
			glVertex2f(0,470);
			glEnd();
			//glFlush();//draw all objects

            glColor3f(0.9,0.8,0.5);  //the luggage keeper above right third box
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(500,500);
            glVertex2f(320,380);
			glVertex2f(330,360);
			glVertex2f(500,470);
			glEnd();
			//glFlush();//draw all objects*/

            glColor3f(0.7,0.7,0.7);
            glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(0,500);
            glVertex2f(60,440);
			glVertex2f(60,493);
			glVertex2f(50,500);
			glEnd();
			//glFlush();//draw all objects

			glColor3f(0.8,0.8,0.8);  //the luggage keeper above right outline
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(60,440);
            glVertex2f(120,380);
			glVertex2f(120,450);
			glVertex2f(60,493);
			glEnd();
			//glFlush();

			glColor3f(0.9,0.9,0.9);  //the luggage keeper above right outline
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(120,380);
            glVertex2f(180,350);
			glVertex2f(190,400);
			glVertex2f(120,450);
			glEnd();
			//glFlush();


            glColor3f(0.9,0.9,0.9);
            glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(310,400);
            glVertex2f(360,436);
			glVertex2f(360,380);
			glVertex2f(320,350);
			glEnd();
			//glFlush();//draw all objects

			glColor3f(0.8,0.8,0.8);  //the luggage keeper above right outline
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(360,436);
            glVertex2f(400,464);
			glVertex2f(400,410);
			glVertex2f(360,380);
			glEnd();
			//glFlush();

			glColor3f(0.7,0.7,0.7);  //the luggage keeper above right outline
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(400,464);
            glVertex2f(450,500);
			glVertex2f(500,500);
			glVertex2f(400,410);
			glEnd();
			//glFlush();

            //chair 1

            glColor3f(0.7,0.7,0.7);  //the chair bottom base
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(10,40);
            glVertex2f(60,40);
			glVertex2f(60,60);
			glVertex2f(10,60);
			glEnd();
			//glFlush();


            glColor3f(0.7,0.7,0.7);  //the chair the back leaner
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(10,60);
            glVertex2f(15,120);
			glVertex2f(55,120);
			glVertex2f(60,60);
			glEnd();
			//glFlush();

            glColor3f(0.7,0.7,0.7);  //the chair the base support
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(25,30);
            glVertex2f(45,30);
			glVertex2f(45,40);
			glVertex2f(25,40);
			glEnd();
			//glFlush();

			glColor3f(0,0,0); //the head
			glBegin(GL_POLYGON);
            glVertex2f(25,120);
            glVertex2f(25,140);
			glVertex2f(40,140);
			glVertex2f(40,120);
			glEnd();
			//glFlush();

			//chair 2

            glColor3f(0.7,0.7,0.7);  //the chair bottom base
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(90,40);
            glVertex2f(90,60);
			glVertex2f(140,60);
			glVertex2f(140,40);
			glEnd();
			//glFlush();


            glColor3f(0.7,0.7,0.7);  //the chair the back leaner
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(90,60);
            glVertex2f(95,120);
			glVertex2f(135,120);
			glVertex2f(140,60);
			glEnd();
			//glFlush();

            glColor3f(0.7,0.7,0.7);  //the chair the base support
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(105,30);
            glVertex2f(105,40);
			glVertex2f(125,40);
			glVertex2f(125,30);
			glEnd();
			//glFlush();

			glColor3f(0,0,0); //the head
			glBegin(GL_POLYGON);
            glVertex2f(105,120);
            glVertex2f(105,140);
			glVertex2f(120,140);
			glVertex2f(120,120);
			glEnd();
			//glFlush();

			//chair 4
			glColor3f(0.7,0.7,0.7);  //the chair bottom base
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(440,40);
            glVertex2f(440,60);
			glVertex2f(490,60);
			glVertex2f(490,40);
			glEnd();
			//glFlush();


            glColor3f(0.7,0.7,0.7);  //the chair the back leaner
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(440,60);
            glVertex2f(445,120);
			glVertex2f(485,120);
			glVertex2f(490,60);
			glEnd();
			//glFlush();

            glColor3f(0.7,0.7,0.7);  //the chair the base support
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(455,30);
            glVertex2f(455,40);
			glVertex2f(475,40);
			glVertex2f(475,30);
			glEnd();
			//glFlush();

			glColor3f(0,0,0); //the head
			glBegin(GL_POLYGON);
            glVertex2f(455,120);
            glVertex2f(455,140);
			glVertex2f(470,140);
			glVertex2f(470,120);
			glEnd();
			//glFlush();

			//chair 3

			glColor3f(0.7,0.7,0.7);  //the chair bottom base
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(360,40);
            glVertex2f(360,60);
			glVertex2f(410,60);
			glVertex2f(410,40);
			glEnd();
			//glFlush();


            glColor3f(0.7,0.7,0.7);  //the chair the back leaner
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(360,60);
            glVertex2f(365,120);
			glVertex2f(405,120);
			glVertex2f(410,60);
			glEnd();
			//glFlush();

            glColor3f(0.7,0.7,0.7);  //the chair the base support
			glBegin(GL_POLYGON);//draws a connected group of line //segments from the first vertex to the last.
            glVertex2f(375,30);
            glVertex2f(375,40);
			glVertex2f(395,40);
			glVertex2f(395,30);
			glEnd();
			//glFlush();

			glColor3f(0,0,0); //the head
			glBegin(GL_POLYGON);
            glVertex2f(375,120);
            glVertex2f(375,140);
			glVertex2f(390,140);
			glVertex2f(390,120);
			glEnd();
			//glFlush();




			//the airhostess
			glColor3f(1,0.9,0.8);//head
			glBegin(GL_POLYGON);
            glVertex2f(220,300);
            glVertex2f(220,325);
			glVertex2f(240,325);
			glVertex2f(240,300);
			glEnd();
			//glFlush();

			glColor3f(1,0.9,0.8); //the neck
			glBegin(GL_POLYGON);
            glVertex2f(225,290);
            glVertex2f(225,300);
			glVertex2f(235,300);
			glVertex2f(235,290);
			glEnd();
			//glFlush();

			glColor3f(1,0.9,0.8); //the body
			glBegin(GL_POLYGON);
            glVertex2f(215,290);
            glVertex2f(245,290);
			glVertex2f(245,240);
			glVertex2f(215,240);
			glEnd();
			//glFlush();

			glColor3f(0,0,0.5); //the dress left side
			glBegin(GL_POLYGON);
            glVertex2f(215,290);
            glVertex2f(225,290);
			glVertex2f(230,280);
			glVertex2f(230,240);
            glVertex2f(215,240);
			glEnd();
			//glFlush();

			glColor3f(0,0,0.5); //the dresss right side
			glBegin(GL_POLYGON);
            glVertex2f(245,290);
            glVertex2f(235,290);
			glVertex2f(230,280);
			glVertex2f(230,240);
            glVertex2f(245,240);
			glEnd();
			//glFlush();

			glColor3f(0,0,0.2); //the skirt
			glBegin(GL_POLYGON);
            glVertex2f(215,240);
            glVertex2f(245,240);
			glVertex2f(245,200);
			glVertex2f(215,200);
			glEnd();
			//glFlush();

            glColor3f(1,0.9,0.8); //the leg left side
			glBegin(GL_POLYGON);
            glVertex2f(222,200);
            glVertex2f(230,200);
			glVertex2f(230,150);
			glVertex2f(222,150);
			glEnd();
			//glFlush();


            glColor3f(1,0.9,0.8); //the leg right side
			glBegin(GL_POLYGON);
            glVertex2f(232,200);
            glVertex2f(240,200);
			glVertex2f(240,150);
			glVertex2f(232,150);
			glEnd();
			//glFlush();

            glColor3f(0,0,0); //the sandal left side
			glBegin(GL_POLYGON);
            glVertex2f(222,150);
            glVertex2f(225,140);
			glVertex2f(230,150);
			//glVertex2f(222,150);
			glEnd();
			//glFlush();

            glColor3f(0,0,0); //the sandal right side
			glBegin(GL_POLYGON);
            glVertex2f(232,150);
            glVertex2f(240,150);
			glVertex2f(235,140);
			//glVertex2f(232,150);
			glEnd();
			//glFlush();



            glColor3f(1,0.9,0.8);//the hand left side
			glBegin(GL_POLYGON);
            glVertex2f(215,290);
            glVertex2f(210,290);
			glVertex2f(210,240);
			glVertex2f(215,240);
			glEnd();
			//glFlush();


            glColor3f(1,0.9,0.8);//the hand right side
			glBegin(GL_POLYGON);
            glVertex2f(245,290);
            glVertex2f(250,290);
			glVertex2f(250,240);
			glVertex2f(245,240);
			glEnd();
			//glFlush();


            glColor3f(0.196,0.6,0.8); //the window1
			glBegin(GL_POLYGON);
            glVertex2f(20,300);
            glVertex2f(60,300);
			glVertex2f(60,250);
			glVertex2f(20,250);
			glEnd();
			//glFlush();

            glColor3f(0.196,0.6,0.8);//the window2
			glBegin(GL_POLYGON);
            glVertex2f(65,350);
            glVertex2f(95,350);
			glVertex2f(95,400);
			glVertex2f(65,400);
			glEnd();
			//glFlush();

            glColor3f(0.196,0.6,0.8);//the window3
			glBegin(GL_POLYGON);
            glVertex2f(475,300);
            glVertex2f(435,300);
			glVertex2f(435,250);
			glVertex2f(475,250);
			glEnd();
			//glFlush();

            glColor3f(0.196,0.6,0.8); //the window4
			glBegin(GL_POLYGON);
            glVertex2f(400,400);
            glVertex2f(430,400);
			glVertex2f(430,350);
			glVertex2f(400,350);
			glEnd();
			//glFlush();


            glColor3f(0,0,0); //the hair
			glBegin(GL_POLYGON);
            glVertex2f(210,300);
            glVertex2f(220,300);
            glVertex2f(220,320);
			glVertex2f(230,325);
			glVertex2f(230,335);
			glVertex2f(215,335);
			glEnd();
			//glFlush();
			 glColor3f(0,0,0); //the hair
			glBegin(GL_POLYGON);
            glVertex2f(250,300);
            glVertex2f(240,300);
            glVertex2f(240,320);
			glVertex2f(230,325);
			glVertex2f(230,335);
			glVertex2f(245,335);
			glEnd();
			//glFlush();



			glColor3f(0,0,0); //the eyes
			glBegin(GL_POINTS);
            glVertex2f(225,315);
            glVertex2f(235,315);
			glEnd();
			//glFlush();

			glColor3f(1,0,0); //the lips
			glBegin(GL_LINES);
            glVertex2f(227,305);
            glVertex2f(232,305);
			glEnd();
			glFlush();

}
void MyTimerFunc(int value)
{
    if (value == 0){
        glutCreateWindow("Airplane Simulation");
        glutDisplayFunc(boarding);
        init();
        glutTimerFunc(100, update1, 0);
        glutTimerFunc(10000, MyTimerFunc, 1);
    }
    else if (value == 1){
        glutDisplayFunc(runway1);
        init();
        glutTimerFunc(100, update2, 0);
        glutTimerFunc(20000, MyTimerFunc, 2);
    }
    else if (value == 2){
        glutDisplayFunc(takeoff);
        init();
        glutTimerFunc(100, update3, 0);
        glutTimerFunc(20000, MyTimerFunc, 3);
    }
    else if (value == 3){
        glutDisplayFunc(airplaneInSky1);
        init();
        glutTimerFunc(100, update4, 0);
        glutTimerFunc(20000, MyTimerFunc,4);
    }
    else if (value == 4){
        glutDisplayFunc(inside);
        init();
        glutTimerFunc(5000, MyTimerFunc,5);
    }
    else if (value == 5){
        glutDisplayFunc(cockpit);
        init();
        glutTimerFunc(100, update5, 0);
        glutTimerFunc(15000, MyTimerFunc,6);
    }
    else if (value == 6){
        glutDisplayFunc(airplaneInSky2);
        init();
        glutTimerFunc(100, update6, 0);
        glutTimerFunc(20000, MyTimerFunc,7);
    }
    else if (value == 7){
        glutDisplayFunc(landing);
        init();
        glutTimerFunc(100, update7, 0);
        glutTimerFunc(20000, MyTimerFunc, 8);
    }
    else if (value == 8){
        glutDisplayFunc(runway2);
        init();
        glutTimerFunc(100, update8, 0);
        glutTimerFunc(20000, MyTimerFunc, 9);
    }
    else if (value == 9){
        glutDisplayFunc(disembark);
        init();
        glutTimerFunc(100, update9, 0);
    }
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Airplane Simulation");
	glutDisplayFunc(frontscreen);
	myinit();
    glEnable(GL_DEPTH_TEST);
    glutTimerFunc(3000,MyTimerFunc,0);
	glutMainLoop();
}
