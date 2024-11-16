
#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <mmsystem.h>
#include <sstream>
using namespace std;
float yellowAudience=0.0;
float blueAudience = 0.0;
float danceMove = 0.0;
float triTemp = 0.0;
float triget = 0.0;
float ball_x= 0;
float ball_y=-6;
float ball_z=0;
float keeper_x =0;
float keeper_y=0;
float keeper_z=0;
float tricker_x=0;
float tricker_y=0;
float tricker_z=0;
bool kickRightCorner = false;
bool kickRight  = false;
bool kickLeftCorner = false;
bool kickLeft = false;
bool kickUp = false;
bool end_game = false;
int p1=0,p2=0;
int counterSec = 0;
int keepercounterSec = 0;
int i;
bool goalsaveshow = false;
bool goalshow    = false;
bool greenLight1 = false;
bool greenLight2 = false;
bool greenLight3 = false;
bool greenLight4 = false;
bool greenLight5 = false;
bool redLight1 = false;
bool redLight2 = false;
bool redLight3 = false;
bool redLight4 = false;
bool redLight5 = false;
bool greenLight2_1 = false;
bool greenLight2_2 = false;
bool greenLight2_3 = false;
bool greenLight2_4 = false;
bool greenLight2_5 = false;
bool redLight2_1 = false;
bool redLight2_2 = false;
bool redLight2_3 = false;
bool redLight2_4 = false;
bool redLight2_5 = false;
bool startgame = true;
int countshoot = 0;
int movement =0;
int sound = 0;
int total_game[10]={0,0,0,0,0,0,0,0,0,0},t_G = 0;
bool turn = true;
void endGame();
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float trickerRound = 0.0;


void drawText(char ch[],float xpos, float ypos,float zpos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos3f( xpos , ypos, zpos);
    for (i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}

//SKY SKY SKY SKY
void sky()
{
       //sky starts here
    glBegin(GL_QUADS);
    glColor3f(0.690, 0.769, 0.871);
    glVertex3f(-10,5,-5.0);
    glVertex3f(12,5,-5.0);
    glVertex3f(12,1.7,-4.5);
    glVertex3f(-10,1.7,-4.5);
    glEnd();
    glFlush();
    //ends here sky
}
void score(){drawText("Score:", 1.5,0.8,-2.5);}
//audience
void audience()
{
    ////////////////////////////
    float s=-9.2;
    float d=-9.2;
    for(s;s<9;s+=.1)
    {
    s += .1;
    d = s+.2;
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.000);
    glVertex3f(s,4.5,-4.5);
    glVertex3f(d,4.5,-4.5);
    glVertex3f(d,4.2,-4.5);
    glVertex3f(s,4.2,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }
         for(s=-9.15;s<9;s+=.1)
    {
    s += .1;
    d = s+.09;
    glBegin(GL_POINTS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(s,4.6,-4.5);
    glVertex3f(d,4.6,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }

    ////////////////////////////

    for(s=-9.2;s<9;s+=.1)
    {
    s += .1;
    d = s+.2;
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.627, 0.478);
    glVertex3f(s,4.7,-4.5);
    glVertex3f(d,4.7,-4.5);
    glVertex3f(d,4.2,-4.5);
    glVertex3f(s,4.2,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }



}

void greenAudience()
{
     ////////////////////////////
    float s;
    float d;

      for(s=-9.2;s<9;s+=.1)
    {
    //jersey
    s += .1;
    d = s+.2;
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.545);
    glVertex3f(s,3.5,-4.5);
    glVertex3f(d,3.5,-4.5);
    glVertex3f(d,3.9,-4.5);
    glVertex3f(s,3.9,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }
    ///////////////
    for(s=-9.15;s<9;s+=.1)
    {
    s += .1;
    d = s+.09;
    glBegin(GL_POINTS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(s,4.04,-4.5);
    glVertex3f(d,4.04,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }


    ////////////



    //face
    for(s=-9.2;s<9;s+=.1)
    {
    d=-9.2;
    s += .1;
    d = s+.2;
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.871, 0.678);
    glVertex3f(s,3.9,-4.5);
    glVertex3f(d,3.9,-4.5);
    glVertex3f(d,4.1,-4.5);
    glVertex3f(s,4.1,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }


    ////////////////////////////

}

void dancer()
{
    float s;
    float d;

      for(s=-9.2;s<9;s+=.1)
    {
    //jersey
    s += .1;
    d = s+.2;
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.980, 0.980);
    glVertex3f(s,2.8,-4.5);
    glVertex3f(d,2.8,-4.5);
    glVertex3f(d,3.2,-4.5);
    glVertex3f(s,3.2,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }
    ///////////////
    for(s=-9.15;s<9;s+=.1)
    {
    s += .1;
    d = s+.09;
    glBegin(GL_POINTS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(s,3.34,-4.5);
    glVertex3f(d,3.34,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }


    ////////////



    //face
    for(s=-9.2;s<9;s+=.1)
    {
    d=-9.2;
    s += .1;
    d = s+.2;
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.871, 0.678);
    glVertex3f(s,3.2,-4.5);
    glVertex3f(d,3.2,-4.5);
    glVertex3f(d,3.4,-4.5);
    glVertex3f(s,3.4,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }
}
//banner
void banner()
{

    //red banner
     glBegin(GL_QUADS);
    glColor3f(rand()%20, 0.000, 0.000);
    glVertex3f(-20,2,-2.5);
    glVertex3f(-9,2,-2.5);
    glVertex3f(-9,1.3,-2.5);
    glVertex3f(-20,1.3,-2.5);
    glEnd();


    //blue banner
    glBegin(GL_QUADS);
    glColor3f(0.098, 0.098, rand()%10);
    glVertex3f(-9,2,-2.5);
    glVertex3f(0,2,-2.5);
    glVertex3f(0,1.3,-2.5);
    glVertex3f(-9,1.3,-2.5);
    glEnd();

    //yellow banner
    glBegin(GL_QUADS);
    glColor3f(rand()%25, rand()%20, 0.000);
    glVertex3f(-2,2,-2.5);
    glVertex3f(12,2,-2.5);
    glVertex3f(12,1.3,-2.5);
    glVertex3f(-2,1.3,-2.5);
    glEnd();
    glFlush();



}

void field()
{

    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(-8.1,2.0,-3);
    glVertex3f(8.1,2.0,-3);
    glVertex3f(6,-3,0);
    glVertex3f(-6,-3,0);
    glEnd();



//white line on 2nd shape
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-8,0.85,-1.6);
    glVertex3f(8,0.85,-1.6);
    glVertex3f(8,0.9,-1.6);
    glVertex3f(-8,0.9,-1.6);
    glEnd();

//2nd shape
    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 0.000);
    glVertex3f(-8,0,-1.6);
    glVertex3f(8,0,-1.6);
    glVertex3f(8,0.9,-1.6);
    glVertex3f(-8,0.9,-1.6);
    glEnd();


//white line on 3rd shape
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-4.0,-0.5,0);
    glVertex3f(4.0,-0.5,0);
    glVertex3f(4.0,-0.6,0);
    glVertex3f(-4.0,-0.6,0);
    glEnd();

//right line white
     glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(4,-0.8,0);
    glVertex3f(4,0.88,-1.3);
    glVertex3f(4.1,0.88,-1.3);
    glVertex3f(4.1,-0.8,0);
    glEnd();

//left line white
     glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-4,-0.8,0);
    glVertex3f(-4,0.88,-1.3);
    glVertex3f(-4.1,0.88,-1.3);
    glVertex3f(-4.1,-0.8,0);
    glEnd();

//3rd shape

    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 0.000);
    glVertex3f(-6,-0.5,0);
    glVertex3f(6,-0.5,0);
    glVertex3f(6,-1.7,0);
    glVertex3f(-6,-1.7,0);
    glEnd();

//4th shape
    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 0.000);
    glVertex3f(-6,-2.4,0);
    glVertex3f(6,-2.4,0);
    glVertex3f(6,-3,0);
    glVertex3f(-6,-3,0);
    glEnd();

    glFlush ();

}


void goalpost()
{


//left behind stand
     glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
    glVertex3f(-2.9,2.7,-2);
    glVertex3f(-3,2.7,-2);
    glVertex3f(-3,1.2,-2);
    glVertex3f(-2.9,1.2,-2);
    glEnd();
//right behind stand

     glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
    glVertex3f(2.9,2.7,-2);
    glVertex3f(3,2.7,-2);
    glVertex3f(3,1.2,-2);
    glVertex3f(2.9,1.2,-2);
    glEnd();
//top behind stand
        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
    glVertex3f(-3,2.7,-2);
    glVertex3f(3,2.7,-2);
    glVertex3f(3,2.8,-2);
    glVertex3f(-3,2.8,-2);
    glEnd();
//left front side bar
     glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
//glPointSize(100.0);
    glVertex3f(-3,2.8,-1.5);
    glVertex3f(-3.12,2.8,-1.5);
    glVertex3f(-3.12,0.9,-1.5);
    glVertex3f(-3,0.9,-1.5);
    glEnd();

//right front side bar

    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
//glPointSize(100.0);
    glVertex3f(3,2.8,-1.5);
    glVertex3f(3.12,2.8,-1.5);
    glVertex3f(3.12,0.9,-1.5);
    glVertex3f(3,0.9,-1.5);
    glEnd();

//top front bar
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3.12,2.8,-1.5);
    glVertex3f(3.12,2.8,-1.5);
    glVertex3f(3.12,2.9,-1.5);
    glVertex3f(-3.12,2.9,-1.5);
    glEnd();

//right upper corner
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,2.9,-1.5);
    glVertex3f(3.12,2.9,-1.5);
    glVertex3f(3,2.7,-2);
    glVertex3f(2.9,2.7,-2);
    glEnd();
// left upper corner
      glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,2.9,-1.5);
    glVertex3f(-3.12,2.9,-1.5);
    glVertex3f(-3,2.7,-2);
    glVertex3f(-2.9,2.7,-2);
    glEnd();
//left lower corner
      glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,0.9,-1.5);
    glVertex3f(-3.12,0.9,-1.5);
    glVertex3f(-3,1.2,-2);
    glVertex3f(-2.9,1.2,-2);
    glEnd();

         glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,0.9,-1.5);
    glVertex3f(3.12,0.9,-1.5);
    glVertex3f(3,1.2,-2);
    glVertex3f(2.9,1.2,-2);
    glEnd();
 //upper net


    float t=-1.5;
    float y=-1.5;
    for(t;t>-2;t-=.05)
    {
    y=t-.01;
      glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
//glPointSize(100.0);
    glVertex3f(-3,2.8,t);
    glVertex3f(3,2.8,t);
    glVertex3f(3,2.81,y);
    glVertex3f(-3,2.81,y);
    glEnd();
    glFlush();
    t-=.01;
    }
 //left net



//ends upper net

    glFlush();

}
void net()
{
  //net behind vertical
      float c=-2.9;
    float v=-2.9;
    for(v;v<2.9;v += 0.03)
    {
        c=v+0.01;
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(v,2.7,-2);
    glVertex3f(c,2.7,-2);
    glVertex3f(c,1.2,-2);
    glVertex3f(v,1.2,-2);

    glEnd();
    glFlush();
      v=v+.01;
    }

    float b=1.2;
    float n=1.2;

    //net horizental
    for(b;b<2.69;b += 0.01)
    {

    n=b+0.01;

    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,b,-2);
    glVertex3f(3,b,-2);
    glVertex3f(3,n,-2);
    glVertex3f(-3,n,-2);
    glEnd();
    glFlush();
    b=b+0.01;

    }

       glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,1.1,-1.5);
    glVertex3f(-3.01,1.1,-1.5);
    glVertex3f(-3.01,1.3,-2);
    glVertex3f(-3,1.3,-2);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,1.4,-1.5);
    glVertex3f(-3.01,1.4,-1.5);
    glVertex3f(-3.01,1.6,-2);
    glVertex3f(-3,1.6,-2);
    glEnd();


    //
        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,1.7,-1.5);
    glVertex3f(-3.01,1.7,-1.5);
    glVertex3f(-3.01,1.9,-2);
    glVertex3f(-3,1.9,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,1.13,-1.5);
    glVertex3f(-3.01,1.13,-1.5);
    glVertex3f(-3.01,1.13,-2);
    glVertex3f(-3,1.13,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,2.1,-1.5);
    glVertex3f(-3.01,2.1,-1.5);
    glVertex3f(-3.01,2.1,-2);
    glVertex3f(-3,2.1,-2);
    glEnd();

         glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,2.3,-1.5);
    glVertex3f(-3.01,2.3,-1.5);
    glVertex3f(-3.01,2.3,-2);
    glVertex3f(-3,2.3,-2);
    glEnd();

             glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(-3,2.5,-1.5);
    glVertex3f(-3.01,2.5,-1.5);
    glVertex3f(-3.01,2.5,-2);
    glVertex3f(-3,2.5,-2);
    glEnd();

    /////////////left net ends////////////


    //////////////Right net starts//////////

           glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,1.1,-1.5);
    glVertex3f(3.01,1.1,-1.5);
    glVertex3f(3.01,1.3,-2);
    glVertex3f(3,1.3,-2);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,1.4,-1.5);
    glVertex3f(3.01,1.4,-1.5);
    glVertex3f(3.01,1.6,-2);
    glVertex3f(3,1.6,-2);
    glEnd();


    //
        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,1.7,-1.5);
    glVertex3f(3.01,1.7,-1.5);
    glVertex3f(3.01,1.9,-2);
    glVertex3f(3,1.9,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,1.13,-1.5);
    glVertex3f(3.01,1.13,-1.5);
    glVertex3f(3.01,1.13,-2);
    glVertex3f(3,1.13,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,2.1,-1.5);
    glVertex3f(3.01,2.1,-1.5);
    glVertex3f(3.01,2.1,-2);
    glVertex3f(3,2.1,-2);
    glEnd();

         glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,2.3,-1.5);
    glVertex3f(3.01,2.3,-1.5);
    glVertex3f(3.01,2.3,-2);
    glVertex3f(3,2.3,-2);
    glEnd();

             glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.941);
//glPointSize(100.0);
    glVertex3f(3,2.5,-1.5);
    glVertex3f(3.01,2.5,-1.5);
    glVertex3f(3.01,2.5,-2);
    glVertex3f(3,2.5,-2);
    glEnd();
    ////////////////right net ends//////////////////////


    glFlush();

}

void football()
{
    glColor3f(0.098, 0.098, 0.439);
    glutSolidSphere(0.90,30,30);
}

void lightBar()
{
     glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);

    glVertex3f(4,2.8,-1.5);
    glVertex3f(5.7,2.8,-1.5);
    glVertex3f(5.7,2.4,-1.5);
    glVertex3f(4,2.4,-1.5);

    glEnd();
    glFlush();

}
//1rst green light
void greenLight11()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);

    glVertex3f(4.1,2.6,-1.4);
    glVertex3f(4.3,2.6,-1.4);
    glVertex3f(4.3,2.5,-1.4);
    glVertex3f(4.1,2.5,-1.4);


    glEnd();
    glFlush();
}

//2nd green light
void greenLight22()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

    glVertex3f(4.4,2.6,-1.4);
    glVertex3f(4.6,2.6,-1.4);
    glVertex3f(4.6,2.5,-1.4);
    glVertex3f(4.4,2.5,-1.4);





    glEnd();
    glFlush();
}
//3rd greenlight
void greenLight33()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

    glVertex3f(4.7,2.6,-1.4);
    glVertex3f(4.9,2.6,-1.4);
    glVertex3f(4.9,2.5,-1.4);
    glVertex3f(4.7,2.5,-1.4);





    glEnd();
    glFlush();
}
//4th greenlight
void greenLight44()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

    glVertex3f(5.0,2.6,-1.4);
    glVertex3f(5.2,2.6,-1.4);
    glVertex3f(5.2,2.5,-1.4);
    glVertex3f(5.0,2.5,-1.4);





    glEnd();
    glFlush();
}
//5th greenlight

void greenLight55()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

     glVertex3f(5.3,2.6,-1.4);
    glVertex3f(5.5,2.6,-1.4);
    glVertex3f(5.5,2.5,-1.4);
    glVertex3f(5.3,2.5,-1.4);





    glEnd();
    glFlush();
}

void redLight11()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

    glVertex3f(4.1,2.6,-1.4);
    glVertex3f(4.3,2.6,-1.4);
    glVertex3f(4.3,2.5,-1.4);
    glVertex3f(4.1,2.5,-1.4);





    glEnd();
    glFlush();
}

//red
void redLight22()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

    glVertex3f(4.4,2.6,-1.4);
    glVertex3f(4.6,2.6,-1.4);
    glVertex3f(4.6,2.5,-1.4);
    glVertex3f(4.4,2.5,-1.4);

    glEnd();
    glFlush();
}
//3rd redlight
void redLight33()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

     glVertex3f(4.7,2.6,-1.4);
    glVertex3f(4.9,2.6,-1.4);
    glVertex3f(4.9,2.5,-1.4);
    glVertex3f(4.7,2.5,-1.4);




    glEnd();
    glFlush();
}
//4th redlight
void redLight44()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

    glVertex3f(5.0,2.6,-1.4);
    glVertex3f(5.2,2.6,-1.4);
    glVertex3f(5.2,2.5,-1.4);
    glVertex3f(5.0,2.5,-1.4);


    glEnd();
    glFlush();
}
//5th redlight

void redLight55()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

    glVertex3f(5.3,2.6,-1.4);
    glVertex3f(5.5,2.6,-1.4);
    glVertex3f(5.5,2.5,-1.4);
    glVertex3f(5.3,2.5,-1.4);





    glEnd();
    glFlush();
}

void lightBar_2()
{
     glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);

    glVertex3f(-4,2.8,-1.5);
    glVertex3f(-5.7,2.8,-1.5);
    glVertex3f(-5.7,2.4,-1.5);
    glVertex3f(-4,2.4,-1.5);
    glEnd();
    glFlush();

}
//1rst green light
void greenLight11_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

        glVertex3f(-4.1,2.6,-1.4);
    glVertex3f(-4.3,2.6,-1.4);
    glVertex3f(-4.3,2.5,-1.4);
    glVertex3f(-4.1,2.5,-1.4);

    glEnd();
    glFlush();
}

//2nd green light
void greenLight22_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

        glVertex3f(-4.4,2.6,-1.4);
    glVertex3f(-4.6,2.6,-1.4);
    glVertex3f(-4.6,2.5,-1.4);
    glVertex3f(-4.4,2.5,-1.4);

    glEnd();
    glFlush();
}
//3rd greenlight
void greenLight33_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

        glVertex3f(-4.7,2.6,-1.4);
    glVertex3f(-4.9,2.6,-1.4);
    glVertex3f(-4.9,2.5,-1.4);
    glVertex3f(-4.7,2.5,-1.4);

    glEnd();
    glFlush();
}
//4th greenlight
void greenLight44_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

        glVertex3f(-5.0,2.6,-1.4);
    glVertex3f(-5.2,2.6,-1.4);
    glVertex3f(-5.2,2.5,-1.4);
    glVertex3f(-5.0,2.5,-1.4);

    glEnd();
    glFlush();
}
//5th greenlight

void greenLight55_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.000, 0.392, 0.000);
//glPointSize(100.0);

        glVertex3f(-5.3,2.6,-1.4);
    glVertex3f(-5.5,2.6,-1.4);
    glVertex3f(-5.5,2.5,-1.4);
    glVertex3f(-5.3,2.5,-1.4);

    glEnd();
    glFlush();
}

void redLight11_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

        glVertex3f(-4.1,2.6,-1.4);
    glVertex3f(-4.3,2.6,-1.4);
    glVertex3f(-4.3,2.5,-1.4);
    glVertex3f(-4.1,2.5,-1.4);

    glEnd();
    glFlush();
}

//red
void redLight22_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

        glVertex3f(-4.4,2.6,-1.4);
    glVertex3f(-4.6,2.6,-1.4);
    glVertex3f(-4.6,2.5,-1.4);
    glVertex3f(-4.4,2.5,-1.4);

    glEnd();
    glFlush();
}
//3rd redlight
void redLight33_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);

        glVertex3f(-4.7,2.6,-1.4);
    glVertex3f(-4.9,2.6,-1.4);
    glVertex3f(-4.9,2.5,-1.4);
    glVertex3f(-4.7,2.5,-1.4);

    glEnd();
    glFlush();
}
//4th redlight
void redLight44_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);

        glVertex3f(-5.0,2.6,-1.4);
    glVertex3f(-5.2,2.6,-1.4);
    glVertex3f(-5.2,2.5,-1.4);
    glVertex3f(-5.0,2.5,-1.4);

    glEnd();
    glFlush();
}
//5th redlight

void redLight55_2()
{
      glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.000);
//glPointSize(100.0);
        glVertex3f(-5.3,2.6,-1.4);
    glVertex3f(-5.5,2.6,-1.4);
    glVertex3f(-5.5,2.5,-1.4);
    glVertex3f(-5.3,2.5,-1.4);

    glEnd();
    glFlush();
}

void goalkeeper()
{
    //jersey
    glBegin(GL_QUADS);
    //if(turn){glColor3f(1.000, 1.000, 0.000);}
    glColor3f(0.000, 0.000, 0.545);
    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.2,1.2,-1.5);
    glVertex3f(-0.2,1.2,-1.5);
    glEnd();

    //face
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glEnd();

    //mouth
     glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.09,1.55,-1.4);
    glVertex3f(0.09,1.55,-1.4);
    glVertex3f(0.09,1.53,-1.4);
    glVertex3f(-0.09,1.53,-1.4);
    glEnd();

    //left sided eye
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.15,1.6,-1.4);
    glVertex3f(-0.1,1.6,-1.4);
    glVertex3f(-0.1,1.65,-1.4);
    glVertex3f(-0.15,1.65,-1.4);
    glEnd();

    //right sided eye

    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.15,1.6,-1.4);
    glVertex3f(0.1,1.6,-1.4);
    glVertex3f(0.1,1.65,-1.4);
    glVertex3f(0.15,1.65,-1.4);
    glEnd();

    //hair
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.8,-1.5);
    glVertex3f(-0.2,1.8,-1.5);
    glEnd();

    //left sided hand
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(-0.5,1.5,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(-0.2,1.4,-1.5);
    glVertex3f(-0.5,1.4,-1.5);
    glEnd();

    //right sided hand gloves
    glBegin(GL_QUADS);
    glColor3f(0.098, 0.098, 0.439);
    glVertex3f(-0.5,1.5,-1.5);
    glVertex3f(-0.6,1.5,-1.5);
    glVertex3f(-0.6,1.4,-1.5);
    glVertex3f(-0.5,1.4,-1.5);
    glEnd();

    //right sided hand
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(0.5,1.5,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.2,1.4,-1.5);
    glVertex3f(0.5,1.4,-1.5);
    glEnd();

    //right sided hand gloves
    glBegin(GL_QUADS);
    glColor3f(0.098, 0.098, 0.439);
    glVertex3f(0.5,1.5,-1.5);
    glVertex3f(0.6,1.5,-1.5);
    glVertex3f(0.6,1.4,-1.5);
    glVertex3f(0.5,1.4,-1.5);
    glEnd();

    //pant
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-0.2,1.2,-1.5);
    glVertex3f(0.2,1.2,-1.5);
    glVertex3f(0.2,1.0,-1.5);
    glVertex3f(-0.2,1.0,-1.5);
    glEnd();

    //left sided leg

    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(-0.2,1.0,-1.5);
    glVertex3f(-0.1,1.0,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.2,0.8,-1.5);
    glEnd();

    //right sided leg
    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(0.2,1.0,-1.5);
    glVertex3f(0.1,1.0,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.2,0.8,-1.5);
    glEnd();

    //right sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.2,0.8,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.1,0.7,-1.5);
    glVertex3f(0.2,0.7,-1.5);
    glEnd();

    //left sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,0.8,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.1,0.7,-1.5);
    glVertex3f(-0.2,0.7,-1.5);
    glEnd();

    glFlush();
}
///////////////////////////winning///////////////////////////////////////////

void GoalDisplay()
{
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(-0.19,-0.01,-1.5);
    glVertex3f(-0.1,-0.01,-1.5);
    glVertex3f(-0.1,-0.04,-1.5);
    glVertex3f(-0.19,-0.04,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(-0.19,-0.05,-1.5);
    glVertex3f(-0.11,-0.05,-1.5);
    glVertex3f(-0.11,-0.09,-1.5);
    glVertex3f(-0.19,-0.09,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex3f(-0.2,0,-1.5);
    glVertex3f(-0.1,0,-1.5);
    glVertex3f(-0.1,-0.1,-1.5);
    glVertex3f(-0.2,-0.1,-1.5);
    glEnd();




    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(-0.08,-0.01,-1.5);
    glVertex3f(0.01,-0.01,-1.5);
    glVertex3f(0.01,-0.09,-1.5);
    glVertex3f(-0.08,-0.09,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex3f(-0.09,0,-1.5);
    glVertex3f(0.02,0,-1.5);
    glVertex3f(0.02,-0.1,-1.5);
    glVertex3f(-0.09,-0.1,-1.5);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(0.04,-0.06,-1.5);
    glVertex3f(0.11,-0.06,-1.5);
    glVertex3f(0.11,-0.1,-1.5);
    glVertex3f(0.04,-0.1,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(0.04,-0.01,-1.5);
    glVertex3f(0.11,-0.01,-1.5);
    glVertex3f(0.11,-0.05,-1.5);
    glVertex3f(0.04,-0.05,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex3f(0.03,0,-1.5);
    glVertex3f(0.12,0,-1.5);
    glVertex3f(0.12,-0.1,-1.5);
    glVertex3f(0.03,-0.1,-1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex3f(0.03,0,-1.5);
    glVertex3f(0.12,0,-1.5);
    glVertex3f(0.12,-0.1,-1.5);
    glVertex3f(0.03,-0.1,-1.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(0.15,0,-1.5);
    glVertex3f(0.21,0,-1.5);
    glVertex3f(0.21,-0.08,-1.5);
    glVertex3f(0.15,-0.08,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex3f(0.13,0,-1.5);
    glVertex3f(0.21,0,-1.5);
    glVertex3f(0.21,-0.1,-1.5);
    glVertex3f(0.13,-0.1,-1.5);
    glEnd();





    glFlush();
}

/////////////////////////END////////////////////////////////////////////////


void movekeeperup()
{

    keeper_y +=0.5;
    keeper_z += 0.5;
    if(keeper_y<2.8)
    {

        keeper_y += keeper_y;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void movekeeperRightUppercorner()
{
    keeper_x +=1.0;
    keeper_y +=0.5;
    keeper_z += 0.5;
    if(keeper_x<1.5 && keeper_y<1)
    {
        keeper_x += keeper_x;
        keeper_y += keeper_y;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }

    glutPostRedisplay();
}
void movekeeperLeftUppercorner()
{
    keeper_x =keeper_x-1.0;
    keeper_y +=0.5;
    keeper_z += 0.5;
    if(keeper_x>-1.5 && keeper_y<1)
    {
        keeper_x = keeper_x-1.0;
        keeper_y += keeper_y;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void movekeeperRight()
{
    keeper_x +=1.2;
    keeper_y +=0.0;
    keeper_z += 0.5;
    if(keeper_x<2.2 )
    {
        keeper_x += keeper_x;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void movekeeperLeft()
{
    keeper_x =keeper_x - 1.2;
    keeper_y +=0.0;
    keeper_z += 0.5;
    if(keeper_x<2.2 )
    {
        keeper_x = keeper_x-1.2;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void moveFootballRightUppercorner()
{

        ball_x  += 0.85;
        ball_z -= 0.10;
        ball_y +=1.6;
        if(ball_x>5 && ball_y>5.9 && ball_z>-2)
        {
            ball_x += ball_x;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickRightCorner = false;
        }
        glutPostRedisplay();
}

void moveFootballLeftCorner()
{
        ball_x -= 1.6;
        ball_z -= 0.10;
        ball_y += 1.6;
        if(ball_x<-2 && ball_y>5.9 && ball_z>-2)
        {
            ball_x = ball_x-1.6;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickLeftCorner = false;
        }



        glutPostRedisplay();
}


void moveFootballRight()
{

        ball_x  += 0.80;
        ball_z -= 0.10;
        ball_y +=1.0;
        if(ball_x>2 && ball_y>2.8 &&  ball_z>-5)
        {
            ball_x += ball_x;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickRight = false;
        }
        glutPostRedisplay();
}



void moveFootballLeft()
{
        ball_x  -= 1.4;
        ball_z -= 0.10;
        ball_y +=1.0;
        if(ball_x<8 && ball_y>2.8 &&  ball_z>-2)
        {
            ball_x = ball_x-1.4;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickLeft = false;
        }



        glutPostRedisplay();

}

void moveFootballUp()
{
    ball_y += 1.8;
    if(ball_y>6 && ball_z >-2)
    {
            ball_y += ball_y;
            ball_z -= ball_z;
            kickUp = false;
    }
      glutPostRedisplay();
}

void reset()
{
     ball_x= 0;
     ball_y=-6;
     ball_z=0;
     keeper_x =0;
     keeper_y=0;
     keeper_z=0;
     trickerRound =0;
     goalsaveshow = false;
     goalshow = false;
     movement =0;
     glutPostRedisplay();
}

void newgame()
{
     ball_x= 0;
     ball_y=-6;
     ball_z=0;
     keeper_x =0;
     keeper_y=0;
     keeper_z=0;
     movement =0;
     trickerRound =0;
     goalsaveshow = false;
     goalshow = false;
     greenLight1 = false;
     greenLight2 = false;
     greenLight3 = false;
     greenLight4 = false;
     greenLight5 = false;
     redLight1 = false;
     redLight2 = false;
     redLight3 = false;
     redLight4 = false;
     redLight5 = false;
     greenLight2_1 = false;
     greenLight2_2 = false;
     greenLight2_3 = false;
     greenLight2_4 = false;
     greenLight2_5 = false;
     redLight2_1 = false;
     redLight2_2 = false;
     redLight2_3 = false;
     redLight2_4 = false;
     redLight2_5 = false;
     tricker_x=0;
     tricker_y=0;
     tricker_z=0;
     countshoot =0;
     end_game = false;
     t_G = 0;
     for(int x=0;x<10;x++){
        total_game[x] = 0;
     }
     glutPostRedisplay();
}

void speedmeter()
{
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.502, 0.502);
    glVertex3f(3,-1,0);
    glVertex3f(4,-1,0);
    glVertex3f(4,-2,0);
    glVertex3f(3,-2,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.863, 0.078, 0.235);
    glVertex3f(4,-1,0);
    glVertex3f(5,-1,0);
    glVertex3f(5,-2,0);
    glVertex3f(4,-2,0);
    glEnd();
    glFlush();
}

void speedtricker()
{
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 0.000);
    glVertex3f(4,2.3,-1.5);
    glVertex3f(5.7,2.3,-1.5);
    glVertex3f(5.7,2.1,-1.5);
    glVertex3f(4,2.1,-1.5);
    glEnd();
    glFlush();
}



void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    glPushMatrix();
    glTranslatef(triTemp, triget, 0.0);
    glScalef(1,1,1);
    banner();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,yellowAudience,0);
    glScalef(1,1,1);
    audience();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,blueAudience,0);
    glScalef(1,1,1);
    greenAudience();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,danceMove,0);
    glScalef(1,1,1);
    dancer();
    glPopMatrix();



    sky();
    field();
    lightBar();
    lightBar_2();
    if(greenLight1)
    {
    greenLight11();
    }
    if(greenLight2)
    {
        greenLight22();
    }
    if(greenLight3)
    {
        greenLight33();
    }
    if(greenLight4)
    {
        greenLight44();
    }
    if(greenLight5)
    {
        greenLight55();
    }
    if(redLight1)
    {
        redLight11();
    }
    if(redLight2)
    {
        redLight22();
    }
    if(redLight3)
    {
        redLight33();
    }
    if(redLight4)
    {
        redLight44();
    }
    if(redLight5)
    {
        redLight55();
    }

    if(greenLight2_1)
    {
    greenLight11_2();
    }
    if(greenLight2_2)
    {
        greenLight22_2();
    }
    if(greenLight2_3)
    {
        greenLight33_2();
    }
    if(greenLight2_4)
    {
        greenLight44_2();
    }
    if(greenLight2_5)
    {
        greenLight55_2();
    }
    if(redLight2_1)
    {
        redLight11_2();
    }
    if(redLight2_2)
    {
        redLight22_2();
    }
    if(redLight2_3)
    {
        redLight33_2();
    }
    if(redLight2_4)
    {
        redLight44_2();
    }
    if(redLight2_5)
    {
        redLight55_2();
    }



    goalpost();
    net();

    glPushMatrix();
    glScalef(.15,.15,.15);
    glTranslatef(ball_x,ball_y,ball_z);
    football();
    glPopMatrix();


//goalkeeper
    glPushMatrix();
    glTranslatef(keeper_x,keeper_y,keeper_z);
    goalkeeper();
    glPopMatrix();
      //startscreen();


   // score();



    if(goalsaveshow)
    {
        glColor3f(1.000, 0.000, 0.000);
        drawText("**********OWWWWWWWW***********", -0.2,0,-1);
    }
    else if(goalshow)
    {
      //  drawText("**********GOAL***********", -0.1,0,-1);
      glPushMatrix();
   // glScalef(.15,.15,.15);
    glTranslatef(0,0,trickerRound);
    GoalDisplay();
    glPopMatrix();
    }

    if(end_game){
        for(int x=0;x<10;x++){
            if(x%2==0){
                p1+=total_game[x];
            }
            else{
                p2+=total_game[x];
            }
//            cout << total_game[x];
        }
//        cout << p1 << p2;
        if(p1>p2){
//            stringstream str;
//            str << "Player 1 WINS by "<<p1<<" - "<<p2;
//            string str2 = str.str();
            drawText("Player 1 WINS",-0.2,0,-1);
        }
        else if(p1<p2){
//            stringstream str;
//            str << "Player 2 WINS by "<<p1<<" - "<<p2;
            drawText("Player 2 wins",-0.2,0,-1);
        }
        else{
            stringstream str;
//            str << "Match Draw "<<p1<<" - "<<p2;
            drawText("Match Draw",-0.2,0,-1);
        }
    }

  //  speedmeter();
 if(startgame)
    {
     glColor3f(0.000, 0.000, 0.000);
    drawText("Press esc to exit", 0.7,-0.30,-2);
    drawText("Press h to next round", 0.7,-0.35,-2);
    drawText("Press n to new game", 0.7,-0.40,-2);
    drawText("Press d to move the ball Right", 0.7,-0.45,-2);
    drawText("Press a to move the ball Left", 0.7,-0.50,-2);
    drawText("Press e to move the ball Right upper corner", 0.7,-0.55,-2);
    drawText("Press w to move the ball Up", 0.7,-0.60,-2);
    drawText("Press q to move the ball Left upper corner", 0.7,-0.65,-2);
    drawText("Press v to (Hide/Show)", 0.7,-0.7,-2);
    }

	glutSwapBuffers();
}

void update(int value) {


	triTemp += 0.1;

	if(triTemp > 11)
        {

        triTemp = -4;

        }
        counterSec++;
        if(counterSec>5)
        {
           danceMove +=.09;
            if(danceMove>=.18)
            {
                danceMove =0;
            }
            counterSec =0;
        }


    if(goalshow)
        {
            trickerRound +=.1;
            if(trickerRound > 8)
            {
                    trickerRound=0;
            }

            yellowAudience +=.09;
            if(yellowAudience>=.18)
            {
                yellowAudience =0;
            }

        }
    if(goalsaveshow)
    {
        blueAudience += .09;
        if(blueAudience >=.18)
        {
            blueAudience =0;
        }
    }





     if(kickRightCorner)
        {

        if(counterSec >= 0)
            moveFootballRightUppercorner();





        }

        if(kickRight)
        {
        counterSec += 1;
        if(counterSec > 0)
            moveFootballRight();

        }

    if(kickLeftCorner)
    {
       counterSec += 1;
        //cout << "Sec: " <<  counterSec << endl;
        if(counterSec > 0)
            moveFootballLeftCorner();

    }

     if(kickLeft)
    {
       counterSec += 1;
       // cout << "Sec: " <<  counterSec << endl;
        if(counterSec > 0)
            moveFootballLeft();



    }

         if(kickUp)
    {
       counterSec += 1;
      //  cout << "Sec: " <<  counterSec << endl;
        if(counterSec > 0)
            moveFootballUp();


    }



	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{

    int r;
   switch(key)
   {

    case 'v':
        if(!startgame)
        {
            startgame = true;
        }
        else if(startgame)
        {
            startgame = false;
        }
        break;

     case 'V':
        if(!startgame)
        {
            startgame = true;
        }
        else if(startgame)
        {
            startgame = false;
        }
        break;



    case 'e':
    case 'E':
if(movement==0)
{
    if(countshoot==10){newgame();}
    kickRightCorner = true;
    //PlaySound(TEXT("Ball_Kicked"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    srand(time(NULL));//required for "randomness"


        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
       //first green light if red not blink
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}
         goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
          PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
         //countshoot++;
        }
    else if(r==1)
       {

        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;}
        goalsaveshow = true;
        glutIdleFunc(movekeeperRightUppercorner);
       // countshoot++;

       }
    else if(r==2)
    {
     //first green light if red not blink
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}
      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
      //countshoot++;
    }
    else if(r==3)
    {
    //first green light if red not blink
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}
      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
     // countshoot++;
    }
    else if(r==4)
    {
//first green light if red not blink
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
       //countshoot++;
    }

    countshoot++;
    movement++;

}
else
    {
        reset();

    }
        turn = !turn;
        t_G++;
    break;

    case 'q':
    case 'Q':

if(movement==0)
{

      if(countshoot==10){newgame();}

      kickLeftCorner = true;
      srand(time(NULL));//required for "randomness"


        r=rand()%5;//generate a number between 0 and 5

    if(r==0)
        {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}
        goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;}
      goalsaveshow=true;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
    }
    countshoot++;
    movement++;

}
else{reset();}


t_G++;
turn = !turn;
    break;

    case 'a':
    case 'A':
if(movement==0)
{
    if(countshoot==10){newgame();}
    kickLeft = true;
     srand(time(NULL));//required for "randomness"



       // int r;
        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

         goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;}
      goalsaveshow = true;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
      PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
      if(countshoot==0){greenLight1 = true;}
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
    }
    countshoot++;
    movement++;

}
else{reset();}
    t_G++;
    turn = !turn;
    break;
    case 'w':
    case 'W':
if(movement==0)
{
       if(countshoot==10){newgame();}
       kickUp = true;
       srand(time(NULL));//required for "randomness"

        //int r;
        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

         goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;}
       goalsaveshow = true;
       glutIdleFunc(movekeeperup);
    }
    countshoot++;
    movement++;

}
else{reset();}
t_G++;
turn = !turn;
        break;


    case 'd':
    case 'D':
 if(movement==0)
{
    if(countshoot==10){newgame();}
    kickRight = true;
    srand(time(NULL));//required for "randomness"

        //int r;
        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;}
         goalsaveshow = true;
         glutIdleFunc(movekeeperRight);
       //  drawText("!!!!!!!!!!!!!!!!Nice Save!!!!!!!!!!!!!!!!", 2, 2);//
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
    }
     countshoot++;
     movement++;

}
else{reset();}
    t_G++;
    turn = !turn;
    break;


     case 'h':

     case 'H':

       reset();
    break;

     case 'n':
        newgame();
        break;
      case 'N':
        newgame();
        break;
      case 27:
        exit(0);
        break;


   }
   endGame();
}
void endGame()
{
    end_game = false;
    if(countshoot==10){
        end_game = true;
    }
}
int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1366, 768);

	//Create the window
	glutCreateWindow("Penalty Shootout");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboard);
    PlaySound(TEXT("Sports_Stadium_Crowd_Cheering_Sound_Effect_Mp3Conv"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
