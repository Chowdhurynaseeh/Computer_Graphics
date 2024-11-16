
// Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/GL.h>

int width = 500, height = 500; //Window width and height.
int score = 0; //Counts scores.
char buffer[10]; //For converting integer to string.

bool isRunning = false; //Checking if game is running.
bool isFinished = false; //Checking if the game is over.
bool collision = false; //Checks if the car collides.
bool isFullScreen = false; //Checks if fullscreen.

int vehicleX = width/2 - 50, vehicleY = 70; //User cars initial X axis and Y axis value.
int oVehicleX[4], oVehicleY[4]; //Other vehicles array.
int divX = width / 2, divY = 4, moved = 0; //Divider x-axis, y-axis & movement value.

void drawText(char ch[], int xPos, int yPos) //Draws the texts for messages.
{
	int numOfChar = strlen(ch);
	glLoadIdentity();
	glRasterPos2i(xPos, yPos);
	for (int i = 0; i <= numOfChar; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ch[i]); //Selects font.
	}
}

void drawNum(char ch[], int numText, int xPos, int yPos) //Counting and drawing the score.
{
	int len = numText - strlen(ch);
	int k = 0;
	glLoadIdentity();
	glRasterPos2i(xPos, yPos);
	for (int i = 0; i < numText; i++)
	{
		if (i < len)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		else
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
			k++;
		}
	}
}

void oVehiclePos(void) //Determines the initial positions of other cars.
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		if (rand() % 2 == 0)
			oVehicleX[i] = divX - 50; //Other vehicle x-axis value.
		else
			oVehicleX[i] = divX + 50; //Other vehicle x-axis value.
		oVehicleY[i] = 1000 - i * 200; //Other vehicle y-axis value.
	}
}

void drawRoad() //Draws the road.
{
	glBegin(GL_QUADS);
		glColor3f(0.412, 0.412, 0.412);
		glVertex2i(width / 2 - 100, height);
		glVertex2i(width / 2 - 100, 0);
		glVertex2i(width / 2 + 100, 0);
		glVertex2i(width / 2 + 100, height);
	glEnd();
}

void drawDivider() //Draws the divider.
{
	glLoadIdentity();
	glTranslatef(0, moved, 0);
	glColor3f(1, 1, 1);
	for (int i = 1; i <= 20; i++)
	{
		glBegin(GL_QUADS);
			glVertex2f(divX - 5, divY * 15 * i + 18);
			glVertex2f(divX - 5, divY * 15 * i - 18);
			glVertex2f(divX + 5, divY * 15 * i - 18);
			glVertex2f(divX + 5, divY * 15 * i + 18);
		glEnd();
	}
	glLoadIdentity();
}

void drawVehicle() //Draws user's car.
{
	glPointSize(10.0);
	glBegin(GL_POINTS); //Wheel.
		glColor3f(.9, .9, 0);
		glVertex2f(vehicleX - 25, vehicleY + 16);
		glVertex2f(vehicleX + 25, vehicleY + 16);
		glVertex2f(vehicleX - 25, vehicleY - 16);
		glVertex2f(vehicleX + 25, vehicleY - 16);
	glEnd();

	glBegin(GL_QUADS); //Middle.
		glColor3f(1, 0, 0);
		glVertex2f(vehicleX - 25, vehicleY + 20);
		glVertex2f(vehicleX - 25, vehicleY - 20);
		glVertex2f(vehicleX + 25, vehicleY - 20);
		glVertex2f(vehicleX + 25, vehicleY + 20);
	glEnd();

	glBegin(GL_QUADS); //Top.
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX - 23, vehicleY + 20);
		glVertex2f(vehicleX - 19, vehicleY + 40);
		glVertex2f(vehicleX + 19, vehicleY + 40);
		glVertex2f(vehicleX + 23, vehicleY + 20);
	glEnd();

	glBegin(GL_QUADS); //Bottom.
		glColor3f(0, 0, 1);
		glVertex2f(vehicleX - 23, vehicleY - 20);
		glVertex2f(vehicleX - 19, vehicleY - 35);
		glVertex2f(vehicleX + 19, vehicleY - 35);
		glVertex2f(vehicleX + 23, vehicleY - 20);
	glEnd();
}

void drawOVehicle(void) //Draws other cars.
{
	for (int i = 0; i < 4; i++)
	{
		glPointSize(10.0);
		glBegin(GL_POINTS); //Wheel.
			glColor3f(0, 0, 0);
			glVertex2f(oVehicleX[i] - 25, oVehicleY[i] + 16);
			glVertex2f(oVehicleX[i] + 25, oVehicleY[i] + 16);
			glVertex2f(oVehicleX[i] - 25, oVehicleY[i] - 16);
			glVertex2f(oVehicleX[i] + 25, oVehicleY[i] - 16);
		glEnd();

		glBegin(GL_QUADS); //Middle.
		glColor3f(0.753, 0.753, 0.753);
			glVertex2f(oVehicleX[i] - 25, oVehicleY[i] + 20);
			glVertex2f(oVehicleX[i] - 25, oVehicleY[i] - 20);
			glVertex2f(oVehicleX[i] + 25, oVehicleY[i] - 20);
			glVertex2f(oVehicleX[i] + 25, oVehicleY[i] + 20);
		glEnd();

		glBegin(GL_QUADS); //Top.
		glColor3f(0.9, 1, 0.9);
			glVertex2f(oVehicleX[i] - 23, oVehicleY[i] + 20);
			glVertex2f(oVehicleX[i] - 19, oVehicleY[i] + 40);
			glVertex2f(oVehicleX[i] + 19, oVehicleY[i] + 40);
			glVertex2f(oVehicleX[i] + 23, oVehicleY[i] + 20);
		glEnd();

		glBegin(GL_QUADS); //Bottom.
		glColor3f(0.9, 1, 0.9);
			glVertex2f(oVehicleX[i] - 23, oVehicleY[i] - 20);
			glVertex2f(oVehicleX[i] - 19, oVehicleY[i] - 35);
			glVertex2f(oVehicleX[i] + 19, oVehicleY[i] - 35);
			glVertex2f(oVehicleX[i] + 23, oVehicleY[i] - 20);
		glEnd();

		oVehicleY[i] -= 8;

		if (((oVehicleY[i] - 35 > 35 && oVehicleY[i] - 35 < 110) && oVehicleX[i] == vehicleX) || (
			(oVehicleY[i] + 40 < 110 && oVehicleY[i] + 40 > 35) && oVehicleX[i] == vehicleX)) //Collision detection.
		{
			collision = true;
		}

		

		//printf("oVehicleY= %d\tvehicleY=%d\n",oVehicleY[i]-35,vehicleY+40);
		
		if (oVehicleY[i] < -25) //Repositioning the cars after they disappear.
		{
			if (rand() % 2 == 0)
				oVehicleX[i] = divX-50;
			else
				oVehicleX[i] = divX+50;
			oVehicleY[i] = height+400;
		}
	}
}



void instruction(void) //Draws instruction for the game.
{
	glColor3f(0, 0, 0);
	drawText("1. Play", 10, height - 50);
	drawText("2. Pause", 10, height - 80);
	drawText("Q: Quit", 10, height - 110);
	if(isFullScreen)
		drawText("F: Exit fullscreen", 10, height - 140);
	else
	{
		drawText("F: Fullscreen", 10, height - 140);
	}
	if (!isRunning)
		drawText("R: Restart", 10, height - 170);
}

void init(void)
{
	glClearColor(0.000, 1.000, 1.000, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
}

void pause(void);

void display(void) //Display function.
{
	glClear(GL_COLOR_BUFFER_BIT);
	instruction();
	drawRoad();
	drawDivider();
	drawVehicle();
	drawOVehicle();

	moved -= 16;

	if (moved < -50)
		moved = 0;

	glColor3f(1, 1, 1);
	drawText("Score: ", divX + 110, height - 45);
	_itoa_s(score++, buffer, 10);
	drawNum(buffer, 6, divX+170, height - 45);
	glutSwapBuffers();

	if (collision == true)
	{
		isFinished = true;
		glColor3f(1, 0, 0);
		drawText("Game Over", 200, 250);
		glutSwapBuffers();
		pause();
		//getchar();
	}

	Sleep(200);
}

void play(void)
{
	if (!isRunning && !isFinished)
	{
		isRunning = true;
		glutIdleFunc(display);
	}
}

void pause(void)
{
	if (isRunning)
	{
		isRunning = false;
		glutPostRedisplay();
		glutIdleFunc(NULL);
	}
}

void restart(void)
{
	if (!isRunning)
	{
		collision = false;
		isFinished = false;
		oVehiclePos();
		play();
	}
}

void specialKey(int key, int x, int y) //Allow navigation key.
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (isRunning)
		{
			for (int i = 0; i < 4; i++)
			{
				oVehicleY[i] -= 10;
			}
			moved -= 20;
		}
		break;
	case GLUT_KEY_DOWN:
		if (isRunning)
		{
			for (int i = 0; i < 4; i++)
			{
				oVehicleY[i] += 10;
			}
			moved += 8;
		}
		break;
	case GLUT_KEY_LEFT:
		if (isRunning)
			vehicleX = divX-50;
		break;
	case GLUT_KEY_RIGHT:
		if (isRunning)
			vehicleX = divX+50;
		break;
	default:
		break;
	}
	//glutPostRedisplay();
}

void normalKey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		play();
		break;
	case 13:
		play();
		break;
	case '2':
		pause();
		break;
	case 'r':
		restart();
		break;
	case 'f':
		if(!isFullScreen)
		{
			glutFullScreen();
			isFullScreen = true;
		}
		else
		{
			glutReshapeWindow(width, height);
			glutPositionWindow(100,100);
			isFullScreen = false;
		}
		break;
	case 'q':
		exit(0);
		break;
	case 27:
		pause();
	default:
		break;
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("13-24281-2");
	oVehiclePos();
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specialKey);
	glutKeyboardFunc(normalKey);
	glutMainLoop();
}

