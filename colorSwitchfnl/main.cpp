
#include<windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include<GL/glu.h>
#include <GL/glut.h>
#define UP 1
#define DOWN 2
#define RIGHT -1
#define LEFT -2
using namespace std;
//using namespace std;
int sd ;
int c = 0;
int x, y;
bool gameover = false;
float random;
int score;

string b = "Score";

string a=" ";

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



float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float angx = 1;
float angy = 0;
float angz = 0;
float zoom = 1;
int countkey = 0;
float rl = 0.0;
float ud = -2.3;
float ab = 5;
float boxlr = 0.0;
float speed = 0.01;
int red = 255;
int green = 0;
int blue = 0;
string Result;
////////////////////////////////////////////////////////////

void drawText(char ch[],float xpos, float ypos,float zpos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos3f( xpos , ypos, zpos);
    for (int i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}

///////////////////END//////////////////////////////////////
//Draws the 3D scene
void game() //last black screen with gameover text
{
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-5,-3.9,2);
    glVertex3f(5,-3.9,2);
    glVertex3f(5,4.1,2);
    glVertex3f(-5,4.1,2);
    glEnd();
    glFlush();

}
void text() //gameover text
{
    glColor3f(1.000, 1.000, 1.000);
   drawText("GAME OVER press esc to EXIT", -0.1,0,-1);


	glRasterPos3d(-5,2.5,0.0);
    glColor3f(0.000, 1.000, 1.000);
	for(int i=0;b[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,b[i]);

	glRasterPos3d(-4.5,2.5,0.0);

	for(int i=0;Result[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,Result[i]);
}
void drawScene() {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity(); //Reset the drawing perspective
	//
	glTranslatef(1.0, 0.0, -7.0); //Move forward 5 units



glClear(GL_COLOR_BUFFER_BIT);
glClearColor(.184,.310,.310,0 );




glPushMatrix(); //Save the transformations performed thus far
///the cube starts

for(int i = 1; i<8; i+=2)
{


glPushMatrix();

glPushMatrix();

glTranslatef(boxlr, ab+i, 0.0);//down up -(a+i)

glScalef(1.5,0.2,0.1);
glColor3ub(red, green, blue);
glutSolidCube(1);
glPopMatrix();

///the cube ends

///the cube starts
glPushMatrix();

glTranslatef(-5, ab+i, 0.0);
glScalef(1.5,0.2,0.1);
glPushMatrix();
for (int i = 1; i <50; i++)
{
glTranslatef(i/8, 0, 0.0);

glColor3ub(green*i, i, blue*green); //change
glutSolidCube(1);
}
glPopMatrix();
glPopMatrix();
}
glPopMatrix();
///the cube ends


///the dot starts

glTranslatef(rl, ud, 0.0); //Move to the center of the trapezoid
glScalef(zoom,zoom,zoom);
glRotated(angx,1.0, 0.0, 0.0);
glRotated(angy,0.0, 1.0, 0.0);
glRotated(angz,0.0, 0.0, 1.0);

glPushMatrix();

glColor3ub(red, green, blue);

glutSolidSphere(0.2,50,50);
switch (sd)
			{

			case RIGHT:
				 glutSolidSphere(.2+2,50+1,50);
				break;
			case LEFT:

				break;
			}


glPopMatrix();


///the dot ends



glPopMatrix();
glColor3ub(0, 255, 0);

	glRasterPos3d(-5,-2.0,0.0);

	for(int i=0;a[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,a[i]);
        if(gameover)
            {
              //
           // glColor3f(0.000, 1.000, 1.000);
           //drawText("**********OWWWWWWWW***********", 0,0,-1);
           game();
           text();
            }
stringstream convert; // stringstream used for the conversion

convert << score;//add the value of Number to the characters in the stream

Result = convert.str();//set Result to the content of the stream




	glRasterPos3d(-5,2.5,0.0);

	for(int i=0;b[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,b[i]);

	glRasterPos3d(-4.5,2.5,0.0);

	for(int i=0;Result[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,Result[i]);


glutSwapBuffers();



}



void update(int value) {



	ab -=speed;
if (ab < -10) {




        red = red - 50;
             if (red < 0 ) {
		red = 255;
	}

        green = green + 50;

          if (green > 255 ) {
		green = 0;
          }
  blue = blue + 50;

          if (blue > 255 ) {
		blue = 0;
          }

		ab = 3.5;

speed= speed +0.0002;

		score = score +5;


    for (int i= 0; i<100; i++)
    {

random = (rand() /(float)RAND_MAX)/2;
    cout<<random<<endl;

		boxlr = boxlr+random;
		if (boxlr > 5 )
            {
		boxlr = -4;
         }

    }


		  //if (boxlr > 5 ) {
		//boxlr = -4;
         // }

	}
	if((boxlr != rl && (rl > boxlr+.6 || rl < boxlr-.6) && ab <= -3.2 ))
    {
        gameover = true;
    }



	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(1, update, 0);

}

void keyboard(unsigned char key, int x, int y)
{


	switch (key)
	{
    case '4':
        if(rl>-5)
	rl = rl - 0.8;
	break;


	case '6':
	    if(rl <5)
	rl = rl + 0.8;
	break;


	case 27:
        exit(0);
        break;

	countkey++;
    cout<<"Step : " << countkey <<endl;
    cout<<"pressed : "<<key<<endl;
    cout<<"x : "<<angx-1<<"` "<<"y : "<<angy<<"` "<<"z : "<<angz<<"` "<<endl;
    cout<<"zoom = "<<zoom<<"; Translate(x,y) : ("<<rl<<","<<ud<<")"<<endl;
    cout<<endl;

	}
}
void input(int key, int x, int y)
{
	switch (key)
	{

	case GLUT_KEY_RIGHT:
		if (sd != LEFT)

			 if(rl <5)
	rl = rl + 0.2;

		break;
	case GLUT_KEY_LEFT:
		if (sd != RIGHT)
			if(rl>-5)
	rl = rl - 0.8;
		break;
	}

}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1360, 760);
	//glColor3f(1.0,0.0,0.0);
	//glColor3f(1.0,0.0,0.0);

	//Create the window

	glutCreateWindow("3d");
	//gluOrtho2D(-800, 800, -800,800);
	initRendering();



	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboard);


	glutSpecialFunc(input);

	glutTimerFunc(10, update, 0); //Add a timer
    glutFullScreen();
	glutMainLoop();
	return 0;
}
