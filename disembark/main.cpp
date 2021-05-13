#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
GLfloat v=0,w=0,x=0;
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

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Disembark");
	glutDisplayFunc(disembark);
	init();
	glutTimerFunc(100,update9,0);
	glutMainLoop();
}
