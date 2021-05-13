#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
GLfloat a=0,b=0,c=0;
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
    a-=20;
    b+=1;
    c+=1;
    if(a<=-500)
        a=0;
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
void display(void)
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
glTranslatef(a,0,0);
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
glTranslatef(a,0,0);
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
glTranslatef(a,0,0);
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
glTranslatef(a,0,0);
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
glTranslatef(a,0,0);
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
glTranslatef(a,0,0);
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
glTranslatef(a,0,0);
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
glTranslatef(b,c,0);
glBegin(GL_POLYGON);
glVertex2f(38,225);
glVertex2f(38,175);
glVertex2f(76,175);
glVertex2f(48,225);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(b,c,0);
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
glTranslatef(b,c,0);
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
glTranslatef(b,c,0);
glBegin(GL_POLYGON);
glVertex2f(95,175);
glVertex2f(76,137.5);
glVertex2f(86,137.5);
glVertex2f(114,175);
glEnd();
glPopMatrix();

glPushMatrix();
glColor3f(0.839,0.157,0.157);
glTranslatef(b,c,0);
glBegin(GL_POLYGON);
glVertex2f(149,162.5);
glVertex2f(149,150);
glVertex2f(152,150);
glVertex2f(171,162.5);
glEnd();
glPopMatrix();

glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1500,1500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Airplane Takeoff");
	glutDisplayFunc(display);
	init();
	glutTimerFunc(100,update,0);
	glutMainLoop();
}
