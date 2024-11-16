
#include<windows.h>
#include<stdio.h>
#include <iostream>
#include <GL/glut.h>
#include<math.h>

using namespace std;

float _angle;		//Angle, on which object will be rotated;
float _angInc;		//Incremented Angle With respect to time;
float X = -2.2;		//Initial value of X axis of the subject;
float Y = -1.4;		//Initial value of X axis of the subject;
float v;			//Initial velocity ;
float theta;        //Angle,on which object will be thrown;
float incrT;
float time;
float r = 0.0005;  //radius of circular path

void ball();
void display_callback() ;
void update(int value);
void calculate(float time);
void incraseAxis(int value);

void ball()
{
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(X, Y, -6.0);
	glutSolidSphere(0.09, 100, 360);
	glPopMatrix();

}

void ground(){
    glPushMatrix();
    glColor3ub(0, 179, 0);
    glBegin(GL_POLYGON);
    glVertex3f(3,-3,-6.0);
    glVertex3f(-3,-3,-6.0);
    glVertex3f(-3,-1.5,-6.0);
    glVertex3f(3,-1.5,-6.0);
    glEnd();
    glPopMatrix();

}
void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	ball();
	ground();

	glutSwapBuffers();
}

void update(int value)
{
	_angle += _angInc;
	if (_angle > 360)
	{
		_angle -= 360;
	}

	time = time + 0.01;

	float Wi = (v / r) * 2 * 3.1416;                                 //Angular velocity count and conversion the value in radian;

	float alpha = (0 - Wi) / (time);

	if (Y >= -1.4) {
		_angInc = (((Wi*time) + (.5*alpha*time*time))) - _angle;       //angle will incremented until it touch the plane to be landed;
	}
	else {
		_angInc = 0;
	}


	glutPostRedisplay();
	glutTimerFunc(1, update, 0);

}

void calculate(float time)
{

	float p = (theta*3.14159) / 180.0;           //given angle of throwing converted into radian;
	float Vix = v*cosf(p);                      //vertical component of motion;
	float Viy = v*sinf(p);						//horizontal component of motion
	float g = -.098;							//gravitational acceleration;
	cout << Vix << endl;
	cout << Viy << endl;
	float Yt = (Viy*time) + (0.5*g*time*time);   //Y axis's position on specific time;
	float Xt = (Vix*time);                       //X axis's position on specific time;
	cout << Yt << endl;
	cout << Xt << endl;
	X += Xt;                                  //xIncr;
	Y += Yt;                                  //yIncr;
	cout << "Value  of  X :" << X << endl;
	cout << "Value  of  Y :" << Y << endl;

}


void incraseAxis(int value)
{

	incrT += .01;
	calculate(incrT);

	 if (Y <= -1.4)
	{

	cout<<" Successfully landed"<<endl;
		return;
	}

	glutTimerFunc(10, incraseAxis, 0);

}

void initialize() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 100.0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	cout << "Input your  velocity Between 0 to 100" << endl;
	while (cin >> v)
	{
		if (v <= 100.0 && v >= 0.0)
		{
			v = v / 1000;
			break;
		}
		else
		{
			cout << "Error..Input again... velocity should be between 0 to 100" << endl;
		}
	}
	cout << "Input your  Angle between 0 to 90 degree" << endl;
	while (cin >> theta)
	{
		if (theta <= 90.0 && theta >= 0.0)
		{
			break;
		}
		else
		{
			cout << "Error..Input again...Angle should be between 0 to 90 degree" << endl;
		}


	}

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Projectile Motion");

	initialize();
	glutDisplayFunc(display_callback);

	glutTimerFunc(1, update, 0);
	glutTimerFunc(10, incraseAxis, 0);
	glutMainLoop();

	return 0;
}









