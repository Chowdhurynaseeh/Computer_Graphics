#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <string>
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#include <stdarg.h>                       // Header File For Variable Argument Routines   ( ADD )
#include <gl\gl.h>                        // Header File For The OpenGL32 Library
#include <gl\glu.h>                       // Header File For The GLu32 Library
#include <GL/glut.h>
#include "imageloader.h"
#include "imageloader.cpp"
using namespace std;


using namespace std;

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float zex = -100.0;


bool   pause = false;
  //for rotation

float movePoke =0.0,
 moveCam =0.0;


float SCORE = 0.0;
float LIFE = 100;
float fire1 =0.0;
bool fire = false;
///////colition
float shipposition = -200;
float shipX = 2.0;
float shipY = -.8;
float shipZ = 0.0;
float colition = 0;

float shipposition2 = -150;
float ship2X = 0.0;
float ship2Z = 0.0;
float colition2 = 0;

float position3 = -100;
float ship3X = -2.0;
float ship3Z = 0.0;
float colition3 = 0;
float bullet_size = .75;
float speed1 = 50 , speed2 = 100;



GLUquadric *quad; //for texturing
GLuint _mar; //The id of earth texture
GLuint _mars; //The id of moon texture
GLuint _khora; //The id of mars texture
GLuint _un_1; //The id of mars texture

GLuint loadTexture(Image* image)
{
  GLuint mar;
  glGenTextures(1, &mar); //Make room for our texture
  glBindTexture(GL_TEXTURE_2D, mar); //Tell OpenGL which texture to edit
  //Map the image to the texture
  glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
         0,                            //0 for now
         GL_RGB,                       //Format OpenGL uses for image
         image->width, image->height,  //Width and height
         0,                            //The border of the image
         GL_RGB, //GL_RGB, because pixels are stored in RGB format
         GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                           //as unsigned numbers
         image->pixels);               //The actual pixel data
  return mar; //Returns the id of the texture
}


GLuint loadTexture2(Image* image2)
{
  GLuint mars;
  glGenTextures(1, &mars);
  glBindTexture(GL_TEXTURE_2D, mars);

  glTexImage2D(GL_TEXTURE_2D,
         0,
         GL_RGB,
         image2->width, image2->height,
         0,
         GL_RGB,
         GL_UNSIGNED_BYTE,
         image2->pixels);
  return mars;
}


GLuint loadTexture3(Image* image3)
{
  GLuint khora;
  glGenTextures(1, &khora);
  glBindTexture(GL_TEXTURE_2D, khora);

  glTexImage2D(GL_TEXTURE_2D,
         0,
         GL_RGB,
         image3->width, image3->height,
         0,
         GL_RGB,
         GL_UNSIGNED_BYTE,
         image3->pixels);
  return khora;
}

GLuint loadTexture4(Image* image4)
{
  GLuint un_1;
  glGenTextures(1, &un_1);
  glBindTexture(GL_TEXTURE_2D, un_1);
  glTexImage2D(GL_TEXTURE_2D,
         0,
         GL_RGB,
         image4->width, image4->height,
         0,
         GL_RGB,
         GL_UNSIGNED_BYTE,
                           //as unsigned numbers
         image4->pixels);               //The actual pixel data
  return un_1; //Returns the id of the texture
}






void initRendering() {
	glEnable(GL_DEPTH_TEST);
  quad = gluNewQuadric();

  Image* image = loadBMP("mar.bmp");//earth
  _mar = loadTexture(image);
   delete image;

  Image* image2 = loadBMP("mars.bmp");//moon
  _mars = loadTexture2(image2);

  delete image2;

   Image* image3 = loadBMP("khora.bmp");//mars
  _khora= loadTexture3(image3);

  delete image3;

    Image* image4 = loadBMP("un_1.bmp");//sat
  _un_1= loadTexture4(image4);

  delete image4;

}

//Called when the window is resized

void moon()
{
	glPushMatrix();
	glTranslatef(0.0, -3.6, 4.0);
	glScalef(2.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D); //for texturing
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //for texturing
    glBindTexture(GL_TEXTURE_2D, _mars);//for texturing
    //Bottom
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //for texturing
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//for texturing
    gluQuadricTexture(quad,1);//for texturing
    gluSphere(quad,2.8,20,20);//for texturing
    glDisable(GL_TEXTURE_2D);//for texturing

	glPopMatrix();


}

void mars()
{
    glRotatef(60, -2.50, -1.0, 0.0);
    glPushMatrix();

//glRotatef(_angle_1, 0.0, 0.0, 1.0);
    glPushMatrix();
	glTranslatef(-1.9, -1.0, 3.0);

//	glRotatef(_angle_1, 0.0, 0.0, 1.0);
//	glRotatef(50.0, -1.0, 0.0, 0.0);
    glColor3f(1.0, 0.4, 0.0);


	glPopMatrix();


	glTranslatef(-1.9, -1.0, 3.0);


    glEnable(GL_TEXTURE_2D); //for texturing
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //for texturing
    glBindTexture(GL_TEXTURE_2D, _khora);//for texturing
    //Bottom
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //for texturing
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//for texturing
    gluQuadricTexture(quad,1);//for texturing
    gluSphere(quad,1.25,30,30);//for texturing
    glDisable(GL_TEXTURE_2D);//for texturing





	glPopMatrix();

}

void earth()
{
    glRotatef(40, -2.50, -1.0, 0.0);
    glPushMatrix();
//  glRotatef(_angle_1, 0.0, 1.7, 1.0);
	glTranslatef(3.3, 4.0, 0.0);

	glEnable(GL_TEXTURE_2D); //for texturing
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //for texturing
    glBindTexture(GL_TEXTURE_2D, _mar);//for texturing
    //Bottom
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //for texturing
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//for texturing
    gluQuadricTexture(quad,1);//for texturing
    gluSphere(quad,3,20,20);//for texturing
    glDisable(GL_TEXTURE_2D);//for texturing

    glPopMatrix();

}

void saturnx()
{
    glRotatef(55, -2.50, -1.0, 0.0);
    glPushMatrix();
//glRotatef(_angle_1, 0.0, 0.0, 1.0);
	glTranslatef(-6.2, -5.0, 0.2);

    glEnable(GL_TEXTURE_2D); //for texturing
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //for texturing
    glBindTexture(GL_TEXTURE_2D, _un_1);//for texturing
    //Bottom
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //for texturing
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//for texturing
    gluQuadricTexture(quad,1);//for texturing
    gluSphere(quad,1.55,30,30);//for texturing
    glDisable(GL_TEXTURE_2D);//for texturing

	glPopMatrix();
}

void life()
{

    if (LIFE <= 10)
    {
        glBegin(GL_QUADS);
        glColor3f(0, 0, 1);

        glVertex2f( -3,  0);
        glVertex2f( -2.8,  0);
        glVertex2f( -2.8,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }




    else if (LIFE <= 20)
    {
        glBegin(GL_QUADS);
        glColor3f(1, 0, 0);

        glVertex2f( -3,  0);
        glVertex2f( -2.1,  0);
        glVertex2f( -2.1,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }

    else if (LIFE <= 30)
    {
        glBegin(GL_QUADS);
        glColor3f(1, 1, 0);

        glVertex2f( -3,  0);
        glVertex2f( -1.4,  0);
        glVertex2f( -1.4,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }


    else if (LIFE <= 40)
    {
        glBegin(GL_QUADS);
        glColor3f(1, 1, 0);

        glVertex2f( -3,  0);
        glVertex2f( -.7,  0);
        glVertex2f( -.7,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }

    else if (LIFE <= 50)
    {
        glBegin(GL_QUADS);
        glColor3f(0, 1, 1);

        glVertex2f( -3,  0);
        glVertex2f( 0,  0);
        glVertex2f( 0,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }

    else if (LIFE <= 60)
    {
        glBegin(GL_QUADS);
        glColor3f(.5, .1, .5);

        glVertex2f( -3,  0);
        glVertex2f( 0.9,  0);
        glVertex2f( 0.9,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }

    else if (LIFE <= 70)
    {
        glBegin(GL_QUADS);
        glColor3f(0, 0, 1);

        glVertex2f( -3,  0);
        glVertex2f( 1.6,  0);
        glVertex2f( 1.6,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }

    else if (LIFE <= 80)
    {
        glBegin(GL_QUADS);
        glColor3f(0, 0, 1);

        glVertex2f( -3,  0);
        glVertex2f( 2.3,  0);
        glVertex2f( 2.3,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }

    else if (LIFE <=90)
    {

        glBegin(GL_QUADS);
        glColor3f(0, 1, 0);

        glVertex2f( -3,  0);
        glVertex2f( 2.5,  0);
        glVertex2f( 2.5,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }


    else if (LIFE <=100)
    {

        glBegin(GL_QUADS);
        glColor3f(0, 1, 0);

        glVertex2f( -3,  0);
        glVertex2f( 3,  0);
        glVertex2f( 3,  .1);
        glVertex2f( -3,  .1);
        glEnd();
    }


}






void myDisplayFunction(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //RenderToDisplay();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 3200);
    glMatrixMode(GL_MODELVIEW);
}



void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (double)w / (double)h, 1.0, 200.0);

}

void enemy1()
{
           glPushMatrix();
glScalef(1,-2.2,1.3);
   glTranslatef(1,.1,1);
    glRotatef(90,-3,0.0,0.0);
    //glRotatef(_angle,0.0,0.0,0.0);
     glColor3ub(102, 196, 196);
    glutSolidTorus(.04, .30, 20, 20);
    glColor3ub(165, 101, 216);
    glutSolidSphere(.2,10,10);
    glPopMatrix();


}

void enemy5()
{
            glPushMatrix();
glScalef(1,-2.2,1.3);
   glTranslatef(1,.1,1);
    glRotatef(90,-3,0.0,0.0);
    //glRotatef(_angle,0.0,0.0,0.0);
     glColor3ub(102, 196, 196);
    glutSolidTorus(.04, .30, 20, 20);
    glColor3ub(165, 101, 216);
    glutSolidSphere(.2,10,10);
    glPopMatrix();



}

void enemy4()
{

        glPushMatrix();
glScalef(1,-2.2,1.3);
   glTranslatef(1,.1,1);
    glRotatef(90,-3,0.0,0.0);
    //glRotatef(_angle,0.0,0.0,0.0);
     glColor3ub(102, 196, 196);
    glutSolidTorus(.04, .30, 20, 20);
    glColor3ub(165, 101, 216);
    glutSolidSphere(.2,10,10);
    glPopMatrix();



}

void shipMove()
{

    glPushMatrix();
    glTranslatef(0,0,shipposition);
    shipZ = shipposition;

   glTranslatef(0,shipY,0);
    glTranslatef(0,0,3);
    glColor3f(1,0,0);
    glTranslatef(shipX,0.0,0);

    glTranslatef(0.0,0.0,-100);
    glTranslatef(0,.15,3);
    enemy1();
    glTranslatef(0.0,0.0,70);

    glPopMatrix();



    glPushMatrix();
    glTranslatef(0,0,shipposition2);
    ship2Z = shipposition2;

    glTranslatef(0,shipY,0);
    glTranslatef(0,0,5);
    glColor3f(1,0,0);
    glTranslatef(ship2X,0.0,0);

    glTranslatef(0.0,0.0,-100);

    glTranslatef(0,.15,3);
    enemy5();

    glTranslatef(0.0,0.0,70);

    glPopMatrix();



    glPushMatrix();
    glTranslatef(0,0,position3);
    ship3Z = position3;

    glTranslatef(0,shipY,0);
    glTranslatef(0,0,5);
    glColor3f(1,0,0);
    glTranslatef(ship3X,0.0,0);

    glTranslatef(0.0,0.0,-100);

    glTranslatef(0,.15,3);
    enemy4();
    glTranslatef(0.0,0.0,70);

    glPopMatrix();

}

void ship()
{



    glPushMatrix();
glScalef(1,-2.2,1.3);
   glTranslatef(-.10,-0.30,-7.0);
    glRotatef(90,-3,0.0,0.0);

     glColor3ub(244, 209, 66);
    glutSolidTorus(.04, .30, 20, 20);
    glColor3ub(65, 202, 244 );
    glutSolidSphere(.2,10,10);
    glPopMatrix();

}


/*void ship_Yellow()
{



        glPushMatrix();
glScalef(1,-2.2,1.3);
   glTranslatef(1,.1,1);
    glRotatef(90,-3,0.0,0.0);
    //glRotatef(_angle,0.0,0.0,0.0);
     glColor3ub(102, 196, 196);
    glutSolidTorus(.04, .30, 20, 20);
    glColor3ub(165, 101, 216);
    glutSolidSphere(.2,10,10);
    glPopMatrix();




}*/
void drawtext(const char *text,int length,int x,int y)
{
    glMatrixMode(GL_PROJECTION);
    double* matrix=new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,matrix);
    glLoadIdentity();
    glOrtho(0,800,0,600,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0; i<length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);

}

void checkCollision()
{

    if((shipZ ==94 && movePoke <=-2) && !pause )
    {
        LIFE -= 9;
        cout << "SCORE = " << SCORE<<endl;
        cout << "LIFE = " << LIFE<<endl;
        cout<<endl;
    }

    if((ship2Z ==94 && movePoke >= ship2X-1 && movePoke <= ship2X+1  ) && !pause )
    {
        LIFE -= 9;
        cout << "SCORE = " << SCORE<<endl;
        cout << "LIFE = " << LIFE<<endl;
        cout<<endl;
    }

    if((ship3Z ==94 && movePoke >= -2*ship3X-1&& movePoke <= -2*ship3X+1) && !pause )
    {
        LIFE -= 9;
        cout << "SCORE = " << SCORE<<endl;
        cout << "LIFE = " << LIFE<<endl;
        cout<<endl;
    }





    if((colition <= shipZ && colition+2 >= shipZ&& colition !=0 && (-1*movePoke) >= (2*shipX)-bullet_size-1 && (-1*movePoke) <= (2*shipX)+bullet_size+1 ) && !pause )    // collide with Poke bullet
    {
        //pause = true;
        shipposition = -250;
        fire1 = 0.0;
        fire = false;
        colition = 0;
        SCORE++;
        cout << "SCORE = " << SCORE<<endl;
        cout << "LIFE = " << LIFE<<endl;
        cout<<endl;
    }







    if((colition2 <= ship2Z && colition2+2 >= ship2Z && colition2 !=0 && (-1*movePoke) >= (2*ship2X)-bullet_size-1 && (-1*movePoke) <= (2*ship2X)+bullet_size+1 ) && !pause )    // collide with Poke bullet
    {
        shipposition2 = -150;
        fire1 = 0.0;
        fire = false;
        colition2 = 0.0;
        SCORE++;
        cout << "SCORE = " << SCORE<<endl;
        cout << "LIFE = " << LIFE<<endl;
        cout<<endl;
    }



    if ( (colition3 <= ship3Z && colition3+2 >= ship3Z && colition3 !=0 && (-1*movePoke) >= (2*ship3X)-bullet_size-1 && (-1*movePoke) <= (2*ship3X)+bullet_size+1 ) && !pause )    // collide with Poke bullet
    {
        position3 = -180;
        fire1 = 0.0;
        fire = false;
        colition3 = 0.0;
        SCORE++;
        cout << "SCORE = " << SCORE<<endl;
        cout << "LIFE = " << LIFE<<endl;
        cout<<endl;
    }
    if( ( shipZ == 94 || ship2Z == 94 || ship3Z == 94) && !pause ) {

        LIFE -=1;
    }







}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor (0,0,0,0);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
glPushMatrix();
moon();
mars();
earth();
saturnx();

glPopMatrix();
glPushMatrix();
glTranslatef(-1.2,6.5,0);
glScalef(2,3.5,0);
life();
glPopMatrix();
glPushMatrix();
    glColor3f(1,0,0);

    int i = SCORE;
    string s = SSTR( i );
    string text;

    text="Score: " + s;
    drawtext(text.data(),text.size(),680,585);

    i = LIFE;
    s = SSTR( i );

    text="Health: "+s;
    drawtext(text.data(),text.size(),10,585);

    text="Move Left   : Mouse Left ";
    drawtext(text.data(),text.size(),15,530);
    text="Move Right  : Mouse Right ";
    drawtext(text.data(),text.size(),15,510);
    text="Fire        : SPACE ";
    drawtext(text.data(),text.size(),15,490);
    text="Start & Stop: S ";
    drawtext(text.data(),text.size(),15,470);

    glTranslatef(0.0, 2.5, 0.0);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(0,-.63,0);
    glTranslatef(0,0,1);
    glRotatef(180, 0.0, 1.0, 0.0);
    glScalef(.5,.5,.5);

    glTranslatef(movePoke,0.0,0.0);

    if(SCORE < 10)
       ship();
   else ship();


    glPushMatrix();




    if(fire)
    {

        glColor3f(1.0,0.0,0.0);
        glTranslatef(0.0,0.0,fire1);
        glutSolidSphere(bullet_size-.55,30,30);

    }

    glPopMatrix();
    checkCollision();


    glPopMatrix();
glPushMatrix();
    shipMove();
    glPopMatrix();

glPopMatrix();


    glutSwapBuffers();
}

void update(int value)
{

    if(!pause)
    {
        if(SCORE == 20 && speed1 > 25) speed1 = 25;

        zex += .5;
        if(zex > 3) zex = -100;



        //craftX +=0.01;        c


        if(fire )
        {
            fire1 +=3;
            if(fire1 > 80)
            {
                fire1 = 0.0;
                fire = false;
                colition = 0.0;
                colition2 = 0.0;
                colition3 = 0.0;
            }
        }


        if(!pause)                                               // car run
        {
            shipposition += 2;
            if(shipposition > 150) shipposition = -200;

            shipposition2 += 2;
            if(shipposition2 > 150) shipposition2 = -150;

            position3 += 2;
            if(position3 > 150) position3 = -250;
        }


    }

    glutPostRedisplay();
    glutTimerFunc(speed1, update, 0);

}

void keyboard(unsigned char key, int x, int y)
{


    if( key == 'e' || key == 'E' )
    {
        exit(0);
    }



    if( (key == 's' ||  key == ' ' || key == 'S' ) & !fire )
    {
        fire = true;

        int temp = (96-shipposition)/2;
        colition = temp + shipposition+3;

        temp = (96-shipposition2)/2;
        colition2 = temp + shipposition2+3;

        temp = (96-position3)/2;
        colition3 = temp + position3+3;
    }

    if( key == 's' || key == 'S')
    {
        if(!pause)
            pause = true;
        else pause = false;
    }




    glutPostRedisplay();
}
void myMouse(int b, int s, int x, int y) {      // mouse click callback
	if (s == GLUT_DOWN) {


		if ((b == GLUT_LEFT_BUTTON) &&!pause){
                if(movePoke <3){

			  movePoke +=.25;
           // moveCam +=.12;
           // angleCAM +=.2;
			glutPostRedisplay();
		}
		}
		else if ((b == GLUT_RIGHT_BUTTON)&&!pause){
                if(movePoke >-3){
                         movePoke -=.25;
           // moveCam -=.12;
           // angleCAM -=.2;
            glutPostRedisplay();
		}
		}
	}
}
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1366, 768);

    glutCreateWindow("POKEBALL FIRE");
    glutFullScreen();
    initRendering();

    pause = true;

    glutDisplayFunc(drawScene);

    glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboard);

    glutTimerFunc(speed2, update, 0); //Add a timer
glutMouseFunc(myMouse);
    glutMainLoop();


    return 0;
}













