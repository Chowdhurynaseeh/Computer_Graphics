
#include<MMSystem.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

float speed, b = 0.5;
char r, s;
int boatStatus = 0;
int boatStatus1 = 0;
int meghStatus = 0;
int sunStatus = 0;
int moonStatus = 0;
int rainbowStatus = 0;
int rcloudStatus = 0;
int rainStatus = 0;

int shipStatus = 0;
int shipStatus1 = 0;

float boatX = 0;
float boatY = 0;

float boatX1 = 0;
float boatY1 = 0;

float sunX = 0;
float sunY = 0;

float moonX = 0;
float moonY = 0;

float cloudX = 0;
float cloudY = 0;

float shipX = 0;
float shipY = 0;

float ship1X = 0;
float ship1Y = 0;

float rainbowX = 0;
float rainbowY = 0;

float rainX = 0;
float rainY = 0;

float rcloudX = 0;
float rcloudY = 0;

float move, angle;

static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;


void DrawCircle(float cx, float cy, float r, int num_segments) {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component
		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}
void DrawhalfCircle(float cx, float cy, float r, int num_segments) {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component
		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}
void drawSun(int x)
{

	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 243, (1.0f / 255) * 202);
	DrawCircle(540, 1300, 105, 1300);

	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 234, (1.0f / 255) * 162);
	DrawCircle(540, 1300, 100, 1300);

	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 232, (1.0f / 255) * 149);
	DrawCircle(540, 1300, 95, 1300);

	glColor3f((1.0f / 255) * 254, (1.0f / 255) * 222, (1.0f / 255) * 112);
	DrawCircle(540, 1300, 90, 1300);

	glColor3f((1.0f / 255) * 254, (1.0f / 255) * 215, (1.0f / 255) * 78);
	DrawCircle(540, 1300, 85, 1300);

	glColor3f(1, .953, .792);
	DrawCircle(540, 1300, 80, 1300);

	glColor3f((1.0f / 255) * 253, (1.0f / 255) * 142, (1.0f / 255) * 0);
	DrawCircle(540, 1300, 75, 1300);

	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 158, (1.0f / 255) * 2);
	DrawCircle(540, 1300, 67, 1304);

	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 180, (1.0f / 255) * 1);
	DrawCircle(540, 1300, 63, 1308);

	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 197, (1.0f / 255) * 1);
	DrawCircle(540, 1300, 58, 1313);
}

void drawMoon() {

	glColor3f(0.980, 0.980, 0.824);///moon color
	DrawCircle(290, 0, 70, 1300);
}
void moveMoon()
{
	if (moonStatus == 1)
	{

		if (moonY >= 1300)
		{
			moonY = 1300;

		}
		else
		{
			moonY += .50;

		}

	}

	glPushMatrix();

	glTranslatef(moonX, moonY, 0);

	drawMoon();
	glPopMatrix();


}

void sky() {

	glBegin(GL_POLYGON); //Sky
	glColor3f(0.34, 0.808, 1.0);
	glVertex2i(2000, 1500);
	glVertex2i(0, 1500);
	glColor3f(2.49, 1.87, 1.0);
	glVertex2i(0, 970);
	glVertex2i(2000, 970);
	glEnd();

}

void cloud(int x) {
	if (sunY <= -350)
	{
		glColor3f(.7, .7, .7);
	}
	else {
		glColor3f(1.0, 1.0, 1.0);
	}

	DrawCircle(100, 1300, 60, 2000);//1
	DrawCircle(150, 1350, 60, 2000);//2
	DrawCircle(150, 1250, 60, 2000);//3
	DrawCircle(200, 1300, 80, 2000);//4


	DrawCircle(250, 1250, 60, 2000);//5
	DrawCircle(250, 1350, 60, 2000);//6
	DrawCircle(300, 1300, 55, 2000);//7

	DrawCircle(700, 1300, 60, 2000);//1
	DrawCircle(800, 1300, 80, 2000);//2
	DrawCircle(900, 1300, 55, 2000);//3

	if (sunY <= -350)
	{
		glColor3f(.7, .7, .7);
	}
	else { glColor3f(1.0, 1.0, 1.0); }

	int transfer = 1200;

	DrawCircle(100 + transfer, 1300, 60, 2000);//1
	DrawCircle(150 + transfer, 1350, 60, 2000);//2
	DrawCircle(150 + transfer, 1250, 60, 2000);//3


	DrawCircle(200 + transfer, 1300, 80, 2000);//4
	DrawCircle(250 + transfer, 1250, 60, 2000);//5
	DrawCircle(250 + transfer, 1350, 60, 2000);//6
	DrawCircle(300 + transfer, 1300, 55, 2000);//7

	if (sunY <= -350)
	{
		glColor3f(.7, .7, .7);
	}
	else
        { glColor3f(1.0, 1.0, 1.0); }

	transfer = 1000;
	DrawCircle(700 + transfer, 1300, 60, 2000);//1
	DrawCircle(800 + transfer, 1300, 80, 2000);//2
	DrawCircle(900 + transfer, 1300, 55, 2000);//3
}

void moveCloud()

{
	if (meghStatus == 1)
	{
		cloudX += .2;
	}
	if (cloudX>2000)
	{
		cloudX = -200;
	}
	glPushMatrix();
	glTranslatef(cloudX, cloudY, 0);
	cloud(1);
	glPopMatrix();

}

void star()
{
	int x = 0;int y = 0;
	for (x = 0, y = 0;x < 1000, y < 500;x = x + 110, y = y + 60)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(100.0 + x, 1085.0 + y);
		glVertex2f(85.0 + x, 1115.0 + y);
		glVertex2f(115.0 + x, 1115.0 + y);

		glEnd();


		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(100.0 + x, 1125.0 + y);
		glVertex2f(85.0 + x, 1100.0 + y);
		glVertex2f(115.0 + x, 1100.0 + y);
		glEnd();
	}
		for (x = 900, y = 0;x<2000, y<500;x = x + 110, y = y + 60)
		{
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_TRIANGLES);
			glVertex2f(100.0 + x, 1085.0 + y);
			glVertex2f(85.0 + x, 1115.0 + y);
			glVertex2f(115.0 + x, 1115.0 + y);

			glEnd();

			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_TRIANGLES);
			glVertex2f(100.0 + x, 1125.0 + y);
			glVertex2f(85.0 + x, 1100.0 + y);
			glVertex2f(115.0 + x, 1100.0 + y);
			glEnd();
		}
}



void raincloud()
	{
		int x = 100;int y = 100;
		glColor3f(0.863, 0.863, 0.863);
		for (x = 100;x<3500;x += 355)
		{
			DrawCircle(100 + x, 1300 + y, 60, 2000);//1
			DrawCircle(150 + x, 1350 + y, 60, 2000);//2
			DrawCircle(150 + x, 1250 + y, 60, 2000);//3
			DrawCircle(200 + x, 1300 + y, 80, 2000);//4


			DrawCircle(250 + x, 1250 + y, 60, 2000);//5
			DrawCircle(250 + x, 1350 + y, 60, 2000);//6
			DrawCircle(300 + x, 1300 + y, 55, 2000);//7
		}

	}
void moveraincloud()
	{
		if (rcloudStatus == 1)
		{
			rcloudX -= 2.5;
		}
		if (rcloudX>2000)
		{
			rcloudX = -200;
		}
		glPushMatrix();
		glTranslatef(rcloudX, rcloudY, 0);
		raincloud();
		glPopMatrix();

	}
void skynight() {

	if (sunY <= -300)
	{
		glColor3f(0.0, 0.0, 0.0);


	}


	else if (sunY <= -225)//Green Yellow	173-255-47
	{
		glColor3f(1, .498, .278);
	}


	glBegin(GL_POLYGON); //Sky

	glVertex2i(2000, 1500);
	glVertex2i(0, 1500);
	glColor3f(2.49, 1.87, 1.0);
	glVertex2i(0, 970);
	glVertex2i(2000, 970);
	glEnd();


}
void moveSun()
{


	if (sunStatus == 1)// {

	{
		sunY -= .15;

	}

	glPushMatrix();

	glTranslatef(sunX, sunY, 0);

	drawSun(1);
	glPopMatrix();

}


void sea() {

	glBegin(GL_POLYGON); // sea
	if (sunY <= -350)
	{
		glColor3f(.1, 0, .08);

	}
	else
	{
		glColor3f(.106, .69, .918);
	}


	glVertex2i(0, 200);

	if (sunY <= -350)
	{
		glColor3f(.1, 0, .08);

	}
	else
	{
		glColor3f(0.255, 0.412, 0.882);
	}

	glVertex2i(1000, 200);

	if (sunY <= -350)
	{
		glColor3f(0, 0, .08);

	}
	else
	{
		glColor3f(0.106, 1.69, .918);
	}



	glVertex2i(2000, 200);
	if (sunY <= -350)
	{
		glColor3f(0, 0, .2);

	}
	else
	{
		glColor3f(0.733, 0.886, .953);
	}


	glVertex2i(2000, 970);
	if (sunY <= -300)
	{
		glColor3f(.2, 0, .8);

	}
	else
	{
		glColor3f(0.937, .89, .69);
	}

	glVertex2i(1000, 970);
	if (sunY <= -300)
	{
		glColor3f(0, 0, .09);

	}
	else
	{
		glColor3f(0.733, 0.886, .953);
	}

	glVertex2i(0, 970);

	glEnd();


}
void tree()
{
  int xt=115+30-5-3;
  int yt=250;

//  int xt1=150;
//  int yt1=250;

   int x=40;
   int y=200;
   int xx=3;
   int yy=2;


   int x1=90;



      glColor3f(0.545, 0.271, 0.075);//tree 1 body
      glBegin(GL_POLYGON);
      glVertex2i(100+xt, 50+yt);
      glVertex2i(137+xt, 50+yt);
      glVertex2i(137+xt, 350+yt);
      glVertex2i(100+xt, 350+yt);
      glEnd();

       xt=300-10-5;
 glColor3f(0.5, 0.27, 0.07);//tree 2 body
      glBegin(GL_POLYGON);
      glVertex2i(100+xt, 50+yt);
      glVertex2i(137+xt, 50+yt);
      glVertex2i(137+xt, 350+yt);
      glVertex2i(100+xt, 350+yt);
      glEnd();




    glBegin(GL_POLYGON); //tree1

         glColor3f(0.0, 0.6, 0.1);//leaves


         glVertex2i((36+x)*xx, (70+y)*yy);
         glVertex2i((20+x)*xx, (80+y)*yy);
         glVertex2i((10+x)*xx, (90+y)*yy);
         glVertex2i((35+x)*xx, (100+y)*yy);
         glVertex2i((20+x)*xx, (120+y)*yy);
         glVertex2i((10+x)*xx, (130+y)*yy);
         glVertex2i((30+x)*xx, (120+y)*yy);
         glVertex2i((20+x)*xx, (150+y)*yy);
         glVertex2i((40+x)*xx, (130+y)*yy);
         glVertex2i((45+x)*xx, (170+y)*yy);

         glColor3f(0.8, 0.8, 0.1);

         glVertex2i((50+x)*xx, (130+y)*yy);
         glVertex2i((70+x)*xx, (150+y)*yy);
         glVertex2i((60+x)*xx, (120+y)*yy);
         glVertex2i((80+x)*xx, (130+y)*yy);
         glVertex2i((70+x)*xx, (120+y)*yy);
         glVertex2i((80+x)*xx, (110+y)*yy);
         glVertex2i((70+x)*xx, (70+y)*yy);
         glVertex2i((35+x)*xx, (100+y)*yy);
             glEnd();


         glBegin(GL_POLYGON); //tree2

        glColor3f(0.0, 0.6, 0.1);//leaves


         glVertex2i((36+x1)*xx, (70+y)*yy);
         glVertex2i((20+x1)*xx, (80+y)*yy);
         glVertex2i((10+x1)*xx, (90+y)*yy);
         glVertex2i((35+x1)*xx, (100+y)*yy);
         glVertex2i((20+x1)*xx, (120+y)*yy);
         glVertex2i((10+x1)*xx, (130+y)*yy);
         glVertex2i((30+x1)*xx, (120+y)*yy);
         glVertex2i((20+x1)*xx, (150+y)*yy);
         glVertex2i((40+x1)*xx, (130+y)*yy);
         glVertex2i((45+x1)*xx, (170+y)*yy);

         glColor3f(0.8, 0.8, 0.1);

         glVertex2i((50+x1)*xx, (130+y)*yy);
         glVertex2i((70+x1)*xx, (150+y)*yy);
         glVertex2i((60+x1)*xx, (120+y)*yy);
         glVertex2i((80+x1)*xx, (130+y)*yy);
         glVertex2i((70+x1)*xx, (120+y)*yy);
         glVertex2i((80+x1)*xx, (110+y)*yy);
         glVertex2i((70+x1)*xx, (70+y)*yy);
         glVertex2i((35+x1)*xx, (100+y)*yy);
             glEnd();



}



void umbrella()
{
    int x=0+30;
    int y=0+40;
    float xx=1;
    float yy=1;

    glBegin(GL_TRIANGLE_FAN); //umbrella

             glColor3f(0.863, 0.078, 0.235);//// left part

             glVertex2i(635*xx+x, 350*yy+y);
             glVertex2i(535*xx+x, 290*yy+y);
             glVertex2i(573*xx+x, 295*yy+y);

             glColor3f(0.196, 0.804, 0.196);

             glVertex2i(610*xx+x, 270*yy+y);

             glColor3f(0.000, 0.000, 1.000);
             glVertex2i(633*xx+x, 290*yy+y);

              glColor3f(0.863, 0.078, 0.235);

             glVertex2i(668*xx+x, 270*yy+y);


             glColor3f(0.196, 0.804, 0.196);
                glVertex2i(690*xx+x, 295*yy+y);


             glColor3f(0.863, 0.078, 0.235);
                glVertex2i(735*xx+x, 290*yy+y);

              glEnd();

        glColor3f(0.000, 0.000, 0.000);//umbrella Handle
        x=620+30;
        y=190+40;
       glBegin(GL_POLYGON);
      glVertex2i(10*xx+x,1*yy+y);
      glVertex2i(17*xx+x,1*yy+y);
      glVertex2i(17*xx+x,100*yy+y);
      glVertex2i(10*xx+x,100*yy+y);
      glEnd();

  //------------------------------------------------------
  //umbrella 2
     x=0+30+300;
     y=0+40;
     xx=1;
     yy=1;

    glBegin(GL_TRIANGLE_FAN); //umbrella

             glColor3f(0.863, 0.078, 0.235);//// left part

             glVertex2i(635*xx+x, 350*yy+y);
             glVertex2i(535*xx+x, 290*yy+y);
             glVertex2i(573*xx+x, 295*yy+y);

             glColor3f(0.196, 0.804, 0.196);

             glVertex2i(610*xx+x, 270*yy+y);

             glColor3f(0.000, 0.000, 1.000);
             glVertex2i(633*xx+x, 290*yy+y);

              glColor3f(0.863, 0.078, 0.235);

             glVertex2i(668*xx+x, 270*yy+y);


             glColor3f(0.196, 0.804, 0.196);
                glVertex2i(690*xx+x, 295*yy+y);


             glColor3f(0.863, 0.078, 0.235);
                glVertex2i(735*xx+x, 290*yy+y);

              glEnd();

        glColor3f(0.000, 0.000, 0.000);//umbrella Handle
        x=620+30+300;
        y=190+40;
       glBegin(GL_POLYGON);
      glVertex2i(10*xx+x,1*yy+y);
      glVertex2i(17*xx+x,1*yy+y);
      glVertex2i(17*xx+x,100*yy+y);
      glVertex2i(10*xx+x,100*yy+y);
      glEnd();

}

void grass()
{
    int x=-630;
    int y=170;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();

//--------------------------------------------------------------
    x=-580;
    y=140;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();
         //--------------------------------------------------------------
               x=-580;
            y=200;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();

         //--------------------------------------------------------------
               x=-540;
                y=130;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();
         //--------------------------------------------------------------
                  x=-470;
                  y=130;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();




                     //--------------------------------------------------------------
               x=-600;
                y=130;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();

                     //--------------------------------------------------------------
               x=-700;
                y=180;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();

//--------------------------------------------------------------
               x=-400;
                y=230;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();

               x=-475;
                y=230;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();

               x=-510;
                y=230;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();





                     //--------------------------------------------------------------
               x=-400;
                y=140;
    glBegin(GL_POLYGON); //Grass
         //glColor3f(102, 0, 51);
         glColor3f(0.596, 0.984, 0.596);
         glVertex2i((835+x), (100+y));
         glVertex2i((820+x), (120+y));
         glVertex2i((810+x), (130+y));

         glColor3f(0.502, 0.502, 0.000);

         glVertex2i((830+x), (120+y));
         glVertex2i((820+x), (150+y));
         glVertex2i((840+x), (130+y));
         glVertex2i((845+x), (170+y));

         glColor3f(0.855, 0.647, 0.125);
         glVertex2i((850+x), (130+y));
         glVertex2i((870+x), (150+y));
         glVertex2i((860+x), (120+y));
         glVertex2i((880+x), (130+y));
         glVertex2i((870+x), (120+y));
         glVertex2i((855+x), (100+y));
         glEnd();



}



void chair()

{
          int x=0+380;
          int y=0-40;
          float xx=1;
          float yy=1;

            glBegin(GL_QUADS);
            glColor3f(102, 0, 51);

         glVertex2i(300+x,300+y);//main body box
         glVertex2i(340+x,280+y);
         glVertex2i(400+x,360+y);
         glVertex2i(350+x,360+y);
         glEnd();

          glBegin(GL_QUADS);
            glColor3f(0,0,0);

         glVertex2i(305+x,295+y);//lower main body
         glVertex2i(340+x,275+y);
         glVertex2i(340+x,280+y);
         glVertex2i(300+x,300+y);
         glEnd();

          glBegin(GL_QUADS);
            glColor3f(0,0,.4);

         glVertex2i(340+x,275+y);//right side main body
         glVertex2i(400+x,355+y);
         glVertex2i(400+x,360+y);
         glVertex2i(340+x,280+y);
         glEnd();

          glBegin(GL_QUADS);
            glColor3f(0,0,.4);

         glVertex2i(340+x,280+y);//upper side main body
         glVertex2i(320+x,310+y);
         glVertex2i(275+x,320+y);
         glVertex2i(300+x,300+y);
         glEnd();

//--------------------------------------------------

        glColor3f(0.000, 0.000, 0.000);//chair 1st Handle
       glBegin(GL_QUADS);
      glVertex2i(310*xx+x,235*yy+y);
      glVertex2i(315*xx+x,235*yy+y);
      glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,295*yy+y);
      glEnd();

       glColor3f(0.000, 0.000, 0.000);//chair 2nd Handle
        x=40+380;
        y=0-40;
       glBegin(GL_QUADS);
      glVertex2i(310*xx+x,235*yy+y);
      glVertex2i(315*xx+x,235*yy+y);
      glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,295*yy+y);
      glEnd();

      glColor3f(0.000, 0.000, 0.000);//chair 3rd Handle
        x=75+380;
        y=50-40;
       glBegin(GL_QUADS);
      glVertex2i(310*xx+x,235*yy+y);
      glVertex2i(315*xx+x,235*yy+y);
      glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,295*yy+y);
      glEnd();


      //...............................................
      //chair 2

        x=0+380+300;
        y=0-40;
        xx=1;
        yy=1;

            glBegin(GL_QUADS);
            glColor3f(102, 0, 51);

         glVertex2i(300+x,300+y);//main body box
         glVertex2i(340+x,280+y);
         glVertex2i(400+x,360+y);
         glVertex2i(350+x,360+y);
         glEnd();

          glBegin(GL_QUADS);
            glColor3f(0,0,0);

         glVertex2i(305+x,295+y);//lower main body
         glVertex2i(340+x,275+y);
         glVertex2i(340+x,280+y);
         glVertex2i(300+x,300+y);
         glEnd();

          glBegin(GL_QUADS);
            glColor3f(0,0,.4);

         glVertex2i(340+x,275+y);//right side main body
         glVertex2i(400+x,355+y);
         glVertex2i(400+x,360+y);
         glVertex2i(340+x,280+y);
         glEnd();

          glBegin(GL_QUADS);
            glColor3f(0,0,.4);

         glVertex2i(340+x,280+y);//upper side main body
         glVertex2i(320+x,310+y);
         glVertex2i(275+x,320+y);
         glVertex2i(300+x,300+y);
         glEnd();

//--------------------------------------------------

        glColor3f(0.000, 0.000, 0.000);//chair 1st Handle
       glBegin(GL_QUADS);
      glVertex2i(310*xx+x,235*yy+y);
      glVertex2i(315*xx+x,235*yy+y);
      glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,295*yy+y);
      glEnd();

       glColor3f(0.000, 0.000, 0.000);//chair 2nd Handle
        x=40+380+300;
        y=0-40;
       glBegin(GL_QUADS);
      glVertex2i(310*xx+x,235*yy+y);
      glVertex2i(315*xx+x,235*yy+y);
      glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,295*yy+y);
      glEnd();

      glColor3f(0.000, 0.000, 0.000);//chair 3nd Handle
        x=75+380+300;
        y=50-40;
       glBegin(GL_QUADS);
      glVertex2i(310*xx+x,235*yy+y);
      glVertex2i(315*xx+x,235*yy+y);
      glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,295*yy+y);
      glEnd();


}


void field() {

	glBegin(GL_POLYGON); //Middle ground


	if (sunY <= -350)
	{
		glColor3f(.02, .04, .03);

	}

	else if (sunY <= -200)
	{
		glColor3f((1.0f / 245) * 34, (1.0f / 255) * 139, (1.0f / 255) * 34);//Forest Green	34-139-34


	}

	else
	{
		glColor3f(0.545, .671, .0313);

	}

	glVertex2i(0, 0);
	glVertex2i(2000, 0);
	glVertex2i(2000, 450);
	glVertex2i(1870, 420);
	glVertex2i(1850, 410);
	glVertex2i(1830, 390);
	glVertex2i(1800, 380);
	glVertex2i(1750, 370);
	glVertex2i(1700, 360);
	glVertex2i(1600, 360);
	glVertex2i(1500, 365);
	glVertex2i(1350, 375);
	glVertex2i(1200, 390);
	glVertex2i(1000, 410);
	glVertex2i(1700 - 700, 350 + 60);
	glVertex2i(1600 - 700, 370 + 50);
	glVertex2i(1500 - 700, 375 + 50);
	glVertex2i(1350 - 700, 365 + 50);
	glVertex2i(1200 - 700, 390 + 60);
	glVertex2i(1000 - 700, 410 + 50);
	glVertex2i(200, 455);
	glVertex2i(100, 465);
	glVertex2i(0, 500);
	glEnd();


	glBegin(GL_POLYGON); //Middle ground


	if (sunY <= -350)
	{
		glColor3f(.01, .02, .01);
	}
	else if (sunY <= -200)
	{
		glColor3f(0.6549, .780, .1098);

	}
	else
	{
		glColor3f(0.6549, .780, .1098);

	}
	glVertex2i(0, 0);
	glVertex2i(2000, 0);
	glVertex2i(2000, 450 - 5);
	glVertex2i(1870, 420-5);
	glVertex2i(1850, 410-5);
	glVertex2i(1830, 390-5);
	glVertex2i(1800, 380-5);
	glVertex2i(1750, 370-5);
	glVertex2i(1600, 370 - 5);
	glVertex2i(1500, 375 - 5);
	glVertex2i(1350, 365 - 5);
	glVertex2i(1200, 390 - 5);
	glVertex2i(1000, 410 - 5);
	glVertex2i(1700 - 700, 350 + 55);
	glVertex2i(1600 - 700, 370 + 45);
	glVertex2i(1500 - 700, 375 + 45);
	glVertex2i(1350 - 700, 365 + 45);
	glVertex2i(1200 - 700, 390 + 55);
	glVertex2i(1000 - 700, 410 + 45);
	glVertex2i(200, 455 - 5);
	glVertex2i(100, 465 - 5);
	glVertex2i(0, 485 - 5);
	glEnd();


	//glBegin(GL_POLYGON); ////**
	if (sunY <= -350)
	{
		glColor3f(.01, .02, .08);

	}
	else if (sunY <= -200)
	{
		glColor3f((1.0f / 245) * 34, (1.0f / 255) * 139, (1.0f / 255) * 34);

	}
	else
	{
		glColor3f(.537, 1.776, .239);

	}
	glBegin(GL_POLYGON); //Middle ground

	glVertex2i(0, 0);
	glVertex2i(2000, 0);
	if (sunY <= -350)
	{
		glColor3f(.5, .5, .5);
	}
	else if (sunY <= -200)
	{
		glColor3f((1.0f / 245) * 34, (1.0f / 255) * 139, (1.0f / 255) * 34);

	}
	else
	{
		glColor3f(0.6549, .780, .1098);

	}

	glVertex2i(2000, 450 -15);
	glVertex2i(1870, 420-15);
	glVertex2i(1850, 410-15);
	glVertex2i(1830, 390-15);
	glVertex2i(1800, 380-15);
	glVertex2i(1750, 370-15);
	glVertex2i(1500, 375 - 15);
	glVertex2i(1350, 365 - 15);
	glVertex2i(1200, 390 - 15);
	glVertex2i(1000, 410 - 15);
	glVertex2i(1700 - 700, 350 + 45);
	glVertex2i(1600 - 700, 370 + 35);
	glVertex2i(1500 - 700, 375 + 35);
	glVertex2i(1350 - 700, 365 + 35);
	glVertex2i(1200 - 700, 390 + 45);
	glVertex2i(1000 - 700, 410 + 35);
	glVertex2i(200, 455 - 15);
	glVertex2i(100, 465 - 15);
	glVertex2i(0, 485 - 15);
	glEnd();


}
void moveboat()
{
	int x;
	x = 1200;
	int y = 870;
	glColor3f((1.0f / 255) * 0, (1.0f / 255) * 0, (1.0f / 255) * 0);
	glBegin(GL_POLYGON);//ship dock color black
	glVertex2f(30 + x, 50 + y);
	glVertex2f(480 + x, 50 + y);
	glVertex2f(500 + x, 160 + y);
	glVertex2f(30 + x, 160 + y);
	glEnd();
	glColor3f((1.0f / 255) * 0, (1.0f / 255) * 0, (1.0f / 255) * 0);
	glBegin(GL_TRIANGLES);//ship front
	glVertex2f(30 + x, 50 + y);
	glVertex2f(30 + x, 160 + y);
	glVertex2f(-30 + x, 200 + y);
	glEnd();
	glColor3f((1.0f / 255) * 255, (1.0f / 255) * 255, (1.0f / 255) * 0);
	glBegin(GL_POLYGON);//first layer
	glVertex2f(30 + x, 160 + y);
	glVertex2f(480 + x, 160 + y);
	glVertex2f(480 + x, 220 + y);
	glVertex2f(30 + x, 220 + y);
	glEnd();

	glColor3f((1.0f / 255) * 107, (1.0f / 255) * 142, (1.0f / 255) * 35);
	glBegin(GL_POLYGON);//2nd layer
	glVertex2f(60 + x, 220 + y);
	glVertex2f(440 + x, 220 + y);
	glVertex2f(440 + x, 240 + y);
	glVertex2f(60 + x, 240 + y);
	glEnd();
	glColor3f((1.0f / 255) * 216, (1.0f / 255) * 191, (1.0f / 255) * 216);
	glBegin(GL_POLYGON);//3rd layer
	glVertex2f(90 + x, 240 + y);
	glVertex2f(400 + x, 240 + y);
	glVertex2f(400 + x, 260 + y);
	glVertex2f(90 + x, 260 + y);
	glEnd();
	glColor3f((1.0f / 255) * 0, (1.0f / 255) * 0, (1.0f / 255) * 0);
	int z = 20;
	glBegin(GL_POLYGON);//1st chonngga
	glVertex2f(140 + x - z, 260 + y);
	glVertex2f(190 + x - z, 260 + y);
	glVertex2f(190 + x - z, 360 + y);
	glVertex2f(140 + x - z, 340 + y);
	glEnd();
	glColor3f((1.0f / 255) * 0, (1.0f / 255) * 0, (1.0f / 255) * 0);
	glBegin(GL_POLYGON);//2nd chonngga
	z = 40;
	glVertex2f(260 + x - z, 260 + y);
	glVertex2f(330 + x - z, 260 + y);
	glVertex2f(330 + x - z, 420 + y);
	glVertex2f(260 + x - z, 390 + y);
	glEnd();
	glColor3f((1.0f / 255) * 0, (1.0f / 255) * 0, (1.0f / 255) * 0);
	glBegin(GL_POLYGON);//3rd chonngga
	z = 200;
	glBegin(GL_POLYGON);//1st chonngga cum last chonnga
	glVertex2f(140 + x + z, 260 + y);
	glVertex2f(190 + x + z, 260 + y);
	glVertex2f(190 + x + z, 360 + y);
	glVertex2f(140 + x + z, 340 + y);
	glEnd();


	if (sunY <= -350)
	{


		x = 1200;y = 870;

		glColor3f(0.855, 0.647, 0.125);
		glBegin(GL_TRIANGLES);

		glVertex2f(20 + x, 120.0 + y);
		glVertex2f(-300.0 + x, 70.0 + y);
		glVertex2f(-300.0 + x, 120.0 + y);
		glEnd();

		//window light at night
		int i = -195;
		//int x;
		glColor3f(1.0, 1.0, 1.0);
		for (x = 1250;x <= 1525;x = x + 25)
		{
			glBegin(GL_POLYGON);
			glVertex2f(50 + x, 1250 + i);
			glVertex2f(60 + x, 1250 + i);
			glVertex2f(60 + x, 1260 + i);
			glVertex2f(50 + x, 1260 + i);
			glEnd();
		}
		i = -213;
		glColor3f(1.0, 1.0, 1.0);
		for (x = 1220;x <= 1575;x = x + 25)
		{
			glBegin(GL_POLYGON);
			glVertex2f(50 + x, 1250 + i);
			glVertex2f(60 + x, 1250 + i);
			glVertex2f(60 + x, 1260 + i);
			glVertex2f(50 + x, 1260 + i);
			glEnd();
		}
		i = -233;
		glColor3f(1.0, 1.0, 1.0);
		for (x = 1190;x <= 1600;x = x + 25)
		{
			glBegin(GL_POLYGON);
			glVertex2f(50 + x, 1250 + i);
			glVertex2f(60 + x, 1250 + i);
			glVertex2f(60 + x, 1260 + i);
			glVertex2f(50 + x, 1260 + i);
			glEnd();
		}

	}

}

void moveboat1(int x)
{
	glBegin(GL_QUADS); //BOAT 1
	glColor3f(0.0, 150.0, 0.0);
	int xp = 40; int yp = -300;
	float xx=1.2;
	float yy=1.16;

	glVertex2i(100*xx + xp, 800*yy + yp);
	glVertex2i(150*xx + xp, 800*yy + yp);
	glVertex2i(175*xx + xp, 825*yy + yp);
	glVertex2i(100*xx + xp, 825*yy + yp);
	glVertex2i(50*xx + xp, 800*yy + yp);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	glVertex2f(150*xx + xp, 825*yy+ yp);
	glVertex2f(140*xx + xp, 845*yy + yp);
	glEnd();

	xp = 600;yp = -290;
	glBegin(GL_QUADS); //BOAT 2
	glColor3f(1.9, 0.0, 0.0);

	glVertex2i(100*xx + xp, 800*yy + yp);
	glVertex2i(150*xx + xp, 800*yy + yp);
	glVertex2i(175 *xx+ xp, 825*yy + yp);
	glVertex2i(100*xx + xp, 825*yy + yp);
	glVertex2i(50*xx + xp, 800*yy + yp);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	glVertex2f(150 *xx+ xp, 825*yy + yp);
	glVertex2f(140 *xx+ xp, 845*yy + yp);
	glEnd();

}


void boat(int s, int x, int b)
{
	if (boatStatus == 1)
	{

		boatX += -.18;
	}
	if (boatX>2000)
	{
		boatX = -600;
	}
	glPushMatrix();
	glTranslatef(boatX, boatY, 0);
	moveboat();
	glPopMatrix();
}
void boat1()
{
	if (boatStatus1 == 1)
	{
		boatX1 += .39;
	}
	if (boatX1>2000)
	{
		boatX1 = -600;
	}
	glPushMatrix();
	glTranslatef(boatX1, boatY1, 0);
	moveboat1(1);
	glPopMatrix();
}


void boat2(){

    int x = 1000;int y = -400;
	glColor3f(0.541, 0.169, 0.886);
	glBegin(GL_POLYGON);//boat2
	glVertex2f(600.0 + x, 820.0 + y);
	glVertex2f(800.0 + x, 820.0 + y);
	glVertex2f(800.0 + x, 900.0 + y);
	glVertex2f(600.0 + x, 900.0 + y);
	glEnd();

    x=1575,y=345;
	glColor3f(0.541, 0.169, 0.886);
	glBegin(GL_POLYGON);//boat 2 front
	glVertex2f(30 + x, 50 +20+ y);
	glVertex2f(30 + x, 160 + y -5-3);
	glVertex2f(-25 + x, 160 + y);
	glVertex2f(-30 + x, 160 + y-5-3);

	glVertex2f(30 + x, 50 +20+ y);
	glEnd();

	 x=1570+200,y=345;
	glColor3f(0.541, 0.169, 0.886);
	glBegin(GL_POLYGON);//boat 2 back side
	glVertex2f(30 + x, 50+20+ y);
	glVertex2f(80+x,160 + y);
	glVertex2f(30 + x, 160 + y);

	glEnd();

	x=1400-30;
	y=-160;
	float xx=1;
	float yy=2.8;
        glColor3f(1, 0.000, 0.000);//boat Handle
       glBegin(GL_QUADS);
      glVertex2i(310*xx+x,235*yy+y);
      glVertex2i(315*xx+x,235*yy+y);
      glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,295*yy+y);
      glEnd();

    glColor3f(0.118, 0.565, 1.000);//boat pal right
       glBegin(GL_TRIANGLES);
      glVertex2i(310*xx+x,235*yy+y+20);
      glVertex2i(460*xx+x,235*yy+y+20);
     // glVertex2i(315*xx+x,290*yy+y);
      glVertex2i(310*xx+x,310*yy+y);
      glEnd();

     glColor3f(0.500, 0.502, 0.000);//boat pal left
      glBegin(GL_TRIANGLES);
      glVertex2i(310*xx+x,235*yy+y+20);
      glVertex2i(310*xx+x,300*yy+y);
      glVertex2i(460*xx+x-260,235*yy+y+20);
     // glVertex2i(315*xx+x,290*yy+y);

      glEnd();
//	x=1670,y=440;
//	glColor3f(0.722, 0.525, 0.043);
//	glBegin(GL_QUADS);//boat 2 upper side
//	glVertex2f(20 + x, 50+40+ y);
//	glVertex2f(60 + x, 60 + y);
//	glVertex2f(65 + x,170 + y);
//	glVertex2f(20 + x, 140 + y);
//    glEnd();
}

void ship() {

	int x = 0;int y = 0;
	glColor3f(0.914, 0.588, 0.478);

	glBegin(GL_POLYGON);//ship body
	glVertex2f(600.0 + x, 800.0 + y+30);
	glVertex2f(800.0 + x, 800.0 + y+30);
	glVertex2f(820.0 + x, 900.0 + y);
	glVertex2f(600.0 + x, 900.0 + y);
	glEnd();

    x=570,y=750;
    glColor3f(0.914, 0.588, 0.478);
	glBegin(GL_TRIANGLES);//ship  front
	glVertex2f(30 + x, 50 + y+30);
	glVertex2f(30 + x, 160 + y -5-3);
	glVertex2f(-15 + x, 200 + y-5-5);
	glEnd();

	 x=0,y=0;
    glColor3f(1.000, 0.549, 0.000);//ship upper
	glBegin(GL_QUADS);

	glVertex2f(600.0+30 + x, 900.0 + y);
	glVertex2f(820.0-30 + x, 900.0 + y);
	glVertex2f(820.0-40+ x, 900.0+40 + y);
	glVertex2f(600.0+30+30+ x, 900.0+40 + y);
	glEnd();
//
//	x = 800; y=-20;
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);//ship 2
//	glVertex2f(600.0 + x, 800.0 + y);
//	glVertex2f(800.0 + x, 800.0 + y);
//	glVertex2f(820.0 + x, 900.0 + y);
//	glVertex2f(600.0 + x, 900.0 + y);
//	glEnd();
//
//	x=570+800,y=730;
//    glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_TRIANGLES);//ship 2 front
//	glVertex2f(30 + x, 50 + y);
//	glVertex2f(30 + x, 160 + y -5-3);
//	glVertex2f(-15 + x, 200 + y-5-5);
//	glEnd();

	if (sunY <= -350)
		{
	glColor3f(0.855, 0.647, 0.125);
	x=470;y=750;
	glBegin(GL_TRIANGLES);//ship light

	  glVertex2f(115+x,100.0+y);
	  glVertex2f(-50.0+x,75.0+y);
	  glVertex2f(-50.0+x,110.0+y);
	glEnd();

//	x=1300;y=750;
//	glBegin(GL_TRIANGLES);//ship light
//
//	  glVertex2f(100+x,100.0+y);
//	  glVertex2f(-50.0+x,75.0+y);
//	  glVertex2f(-50.0+x,100.0+y);
//	glEnd();
			}
}
void moveship(int s, int x, int b)
{
	if (shipStatus == 1)
	{

		shipX -= 1;

	}
	if (shipX<-2000)
	{
		shipX = 2000;
	}
	glPushMatrix();
	glTranslatef(shipX, shipY, 0);
	ship();
	glPopMatrix();
}
void ship1()
{
	// ship1 body
	glBegin(GL_POLYGON);
	int x =0;int y = -150;
	glColor3f(0.804, 0.361, 0.361);
	glBegin(GL_POLYGON);
	glVertex2f(800.0 + x, 800.0+30 + y);
	glVertex2f(1000.0 + x, 800.0+30 + y);
	glVertex2f(1000.0 + x, 900.0 + y);
	glVertex2f(785.0 + x, 900.0 + y);
	glEnd();


	//ship1 left
	glBegin(GL_POLYGON);
	 x =0;
    y = -150;
	glColor3f(0.804, 0.361, 0.361);
	glBegin(GL_TRIANGLES);
	glVertex2f(1000.0 + x, 800.0+30 + y);
	glVertex2f(1000.0 + x+30, 900.0+30+ y);
	glVertex2f(1000.0 + x, 900.0 + y);

	glEnd();

	// ship1 upper
	glBegin(GL_POLYGON);
	 x =0;
	 y = -150;
	glColor3f(1.000, 0.843, 0.000);
	glBegin(GL_QUADS);
	glVertex2f(800.0+30 + x, 900.0 + y);
	glVertex2f(1000.0-30 + x, 900.0 + y);
	glVertex2f(1000.0-40 + x, 940.0 + y);
	glVertex2f(800.0+40 + x, 940.0 + y);

	glEnd();



}
void moveship1()
{
	if (shipStatus1 == 1)
	{

		ship1X += 1;

	}
	if (ship1X<-2000)
	{
		ship1X = 2000;
	}
	glPushMatrix();
	glTranslatef(ship1X, ship1Y, 0);
	ship1();
	glPopMatrix();
}

void mountaion()
{
    int x=0;
    int y=0;


	glColor3f(0.180, 0.545, 0.341);
	 glBegin(GL_POLYGON);

	glVertex2f(0,970);//mountain 1
	glVertex2f(4,980);
	glVertex2f(9,1000);
	glVertex2f(15,1025);
	glVertex2f(20,1045);
	glVertex2f(30,1120);

	//glColor3f(0.196, 0.804, 0.196);

	glVertex2f(45,1155);
	glVertex2f(59,1170);
	glVertex2f(70,1170);
	glVertex2f(85,1180);
	glVertex2f(100,1190);
	glVertex2f(120,1185);
	glVertex2f(134,1175);

	glColor3f(0.235, 0.702, 0.443);

	glVertex2f(150,1170);
	glVertex2f(160,1160);
	glVertex2f(170,1148);
	glVertex2f(185,1144);
	glVertex2f(190,1138);
	glVertex2f(202,1128);
	glVertex2f(210,1118);
	glVertex2f(217,1105);
	glVertex2f(223,1092);
	glVertex2f(231,1080);

	glVertex2f(250,970);

	glVertex2f(0,970);

	glEnd();

	glColor3f(0.180, 0.545, 0.341);//mountain 3
	 glBegin(GL_POLYGON);

	glVertex2f(235,970);
	glVertex2f(244,980);
	glVertex2f(259,1000);
	glVertex2f(270,1025);
	glVertex2f(282,1045);
	glVertex2f(293,1120);
	glVertex2f(305,1155);
	glVertex2f(313,1170);
	glVertex2f(328,1170);
	glVertex2f(341,1180);
	glVertex2f(356,1190);
	glVertex2f(372,1185);
	glVertex2f(387,1175);
	glVertex2f(401,1170);
	glVertex2f(408,1160);
	glVertex2f(416,1148);
	glVertex2f(428,1144);
	glVertex2f(434,1138);
	glVertex2f(441,1128);
	glVertex2f(445,1118);
	glVertex2f(453,1105);
	glVertex2f(461,1092);
	glVertex2f(469,1080);

	glVertex2f(487,970);

	glVertex2f(235,970);

	glEnd();

	glColor3f(0.333, 0.420, 0.184);//mountain 2
	 glBegin(GL_POLYGON);

	glVertex2f(115,970);
	glVertex2f(125,985);
	glVertex2f(135,1000);
	glVertex2f(140,1020);
	glVertex2f(150,1035);
	glVertex2f(160,1050);
	glVertex2f(160,1067);
	glVertex2f(175,1082);
	glVertex2f(185,1078);
	glVertex2f(196,1067);
	glVertex2f(206,1053);
	glVertex2f(217,1041);
	glVertex2f(229,1028);
	glVertex2f(242,1015);
	glVertex2f(254,1007);
	glVertex2f(265,990);
	glVertex2f(273,970);

	glVertex2f(115,970);

	glEnd();
}

void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}
void reset()
{
	spin_x = 0;
	spin_y = 1;
	spin_z = 0;
	translate_x = 0.0;
	translate_y = 0.0;
	translate_z = -30.0;
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void spinDisplay(void)
{
	spin = spin + spin_speed;
	if (spin>360.0)
	{
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}
void spinDisplayReverse(void)
{
	spin = spin - spin_speed;
	if (spin<360.0)
	{
		spin = spin + 360.0;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 's' || key == 'S')///start
	{
		boatStatus = 1;
		boatStatus1 = 1;
		sunStatus = 1;
		meghStatus = 1;

		shipStatus = 1;
		shipStatus1 = 1;

		moonStatus = 1;
		rainbowStatus = 1;
		rcloudStatus = 1;
		rainStatus = 1;
		speed = -.5;
	}
	else if (key == 'd' || key == 'D')///stop
	{
		boatStatus1 = 0;
		boatStatus = 0;
		speed = 0;
		sunStatus = 0;
		meghStatus = 0;
		shipStatus = 0;
		shipStatus1 = 0;
		moonStatus = 0;
		rainbowStatus = 0;
		rcloudStatus = 0;
		rainStatus = 0;
	}

	else if(key == 'k' || key == 'K')///speed up Ship
    {
        boatX += -.45;
    }

}
void myDisplay(void)
{


		sky();
		boat2();

	if (sunY <= -200)
	{
		skynight();

	}

	if (sunY <= -425)
	{
		star();
	}

	moveSun();
	moveMoon();
	mountaion();

	if (sunY <= -50)
	{
		moveraincloud();

	}
	else
	{
		moveCloud();
	}

	if(sunY<=-198)
	{
		moveCloud();
	}


	sea();

    boat(s, b, speed);

	moveship1();

	moveship(s, b, speed);

	field();

	grass();

	boat1();

	tree();

	umbrella();

	chair();



    boat2();

	glFlush();

	glutPostRedisplay();

	glutSwapBuffers();
}
void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
}
int  main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(2000, 1500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("NATURE 2D ANIMATION");
	glutKeyboardFunc(keyboard);

	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();
}
