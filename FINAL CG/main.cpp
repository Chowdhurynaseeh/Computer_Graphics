
#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include <ctime>
#include<string.h>
//#include <stdio.h>
//#include<stdlib.h>
#include <mmsystem.h>
//#define FPS 7
#define ROWS 60.0
#define COLUMNS 60.0
#define UP 1
#define RIGHT 2
#define DOWN -1
#define LEFT -2

int FPS = 7;
int score;
int sound = 0;
float x_bf = 20.30f, y_bf = 20.30f;

using namespace std;
int sd = RIGHT;
int rows = 0, columns = 00;
int posx[55] = { 20, 20, 20, 20 }, posy[55] = { 20, 19, 18, 17 };
bool over = false;
bool fod = false;
int fdx, fdy;
int length = 4;;
bool pause = false;


//initializing
string num_to_str(int num);
void drawStrokeText(char*string, int x, int y, int z);
int random(int, int);
void input(int, int, int);
void InitialExel(int x, int y);
void Exel(int x, int y);

void RESTART() {

	FPS = 7;
	score = 0;
	sd = RIGHT;
	over = false;
	fod = false;
	pause = false;
	length = 4;
	posx[0] = 20;
	posx[1] = 20;
	posx[2] = 20;
	posx[3] = 20;
	posy[0] = 20;
	posy[1] = 19;
	posy[2] = 18;
	posy[3] = 17;
}




void start(){
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(1.0,0.0,0.0,0.0);
	//glClearColor(0.000, 0.545, 0.545,0.0);
	glClearColor(0.941, 0.902, 0.549, 0.0);

	//glClearColor(0.000, 1.000, 1.00,0.0);


	InitialExel(COLUMNS, ROWS);

}




//game part


void InitialExel(int x, int y){
	columns = x;
	rows = y;


}
void DrawExel(){

	for (int i = 0; i<columns; i++)
	{
		for (int j = 0; j<rows; j++)
		{
			Exel(i, j);
		}
	}
}


void snake(){

	for (int i = length - 1; i>0; i--)
	{
		if (!over && !pause) posx[i] = posx[i - 1];
		if (!over && !pause) posy[i] = posy[i - 1];
	}
	for (int i = 0; i<length; i++)
	{
		//glColor3f(0.0,1.0,0.0);
		glColor3f(0.235, 0.702, 0.443
			);
		if (i == 0)
		{
			//glColor3f(0.0,0.0,1.0);
			glColor3f(0.545, 0.000, 0.000);


			switch (sd)
			{
			case UP:
				if (!over && !pause) posy[i]++;
				break;
			case DOWN:
				if (!over && !pause) posy[i]--;
				break;
			case RIGHT:
				if (!over && !pause) posx[i]++;
				break;
			case LEFT:
				if (!over && !pause) posx[i]--;
				break;
			}
			if (posx[i] == 11 || posx[i] == columns - 12 || posy[i] == 11 || posy[i] == rows - 11)
				over = true;
			else if (posx[i] == fdx && posy[i] == fdy)
			{
				fod = false;
				score++;
				length++;
				PlaySound(TEXT("hiss"), NULL, SND_ASYNC | SND_FILENAME);

			}
			for (int j = 1; j<length; j++)
			{
				if (posx[j] == posx[0] && posy[j] == posy[0])
					over = true;
			}
		}
		glBegin(GL_QUADS);
		glVertex2d(posx[i], posy[i]); glVertex2d(posx[i] + 1, posy[i]); glVertex2d(posx[i] + 1, posy[i] + 1); glVertex2d(posx[i], posy[i] + 1);
		glEnd();
	}

}



void food(){

	if (!fod)
	{
		fdx = random(12, columns - 12);
		fdy = random(12, rows - 12);
		//std::cout<<foodx<<foody<<std::endl;
		fod = true;
	}
	//glColor3f(0.6,0.6,0.9);
	//glColor3f(1.6,0.0,0.0);
	glColor3f(1.6, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(fdx, fdy); glVertex2d(fdx + 1, fdy); glVertex2d(fdx + 1, fdy + 1); glVertex2d(fdx, fdy + 1);
	glEnd();

	//glRectd(fdx, fdy, fdx + 1, fdy + 1);


}

void DRAW_TEXT() {
	x_bf = 0.046f, y_bf = 0.02f;
	glColor3f(0.0, 0.0, 1.0);
	string ttd = "";
	ttd = ttd + "Score: " + num_to_str(score);
	char *a;
	a = &ttd[0];
	drawStrokeText(a, 170 / 10, 450 / 10, 0);
}




void DRAW_E() {
	x_bf = 0.015f, y_bf = 0.015f;
	glColor3f(1.000, 0.000, 1.000);
	//glColor3f(1, 0, 0);
	string ttd = "";
	ttd = ttd + "PRESS ";
	string ttd1 = "";
	ttd1 = ttd1 + "E or e ";
	string ttd2 = "";
	ttd2 = ttd2 + " TO  ";
	string ttd3 = "";
	ttd3 = ttd3 + " EXIT ";
	char *a, *b, *c, *d;
	a = &ttd[0];
	b = &ttd1[0];
	c = &ttd2[0];
	d = &ttd3[0];
	drawStrokeText(a, 10 / 10, 320 / 10, 0);
	drawStrokeText(b, 10 / 10, 280 / 10, 0);
	drawStrokeText(c, 10 / 10, 240 / 10, 0);
	drawStrokeText(d, 10 / 10, 180 / 10, 0);

}

void DRAW_GAME_OVER() {
	x_bf = 0.046f, y_bf = 0.046f;
	glColor3f(1, 0, 0);
	string ttd = "";
	ttd = ttd + "GAME OVER";
	char *a;
	a = &ttd[0];
	drawStrokeText(a, 120 / 10, 220 / 10, 0);
}

void DRAW_PAUSE() {
	x_bf = 0.046f, y_bf = 0.046f;
	glColor3f(1, 0, 0);
	string ttd = "";
	ttd = ttd + "PAUSE";
	char *a;
	a = &ttd[0];
	drawStrokeText(a, 220 / 10, 220 / 10, 0);
}


void DRAW_R() {
	x_bf = 0.015f, y_bf = 0.015f;
	glColor3f(0.541, 0.169, 0.886);
	//glColor3f(1, 0, 0);
	string ttd = "";
	ttd = ttd + " FOR ";
	string ttd1 = "";
	ttd1 = ttd1 + " RESTART ";
	string ttd2 = "";
	ttd2 = ttd2 + " PRESS ";
	string ttd3 = "";
	ttd3 = ttd3 + "R or r ";
	char *a, *b, *c, *d;
	a = &ttd[0];
	b = &ttd1[0];
	c = &ttd2[0];
	d = &ttd3[0];
	drawStrokeText(a, 100 / 10, 5 / 10, 0);
	drawStrokeText(b, 180 / 10, 5 / 10, 0);
	drawStrokeText(c, 290 / 10, 5 / 10, 0);
	drawStrokeText(d, 410 / 10, 5 / 10, 0);

}





void DRAW_Speed() {
	x_bf = 0.01f, y_bf = 0.015f;
	glColor3f(0.000, 0.502, 0.502);
	//glColor3f(1, 0, 0);
	string ttd = "";
	ttd = ttd + " SPEEDUP= u ";
	string ttd1 = "";
	ttd1 = ttd1 + " SLOW= s ";
	string ttd2 = "";
	ttd2=ttd2+"PAUSE= p";
	//ttd2=ttd2+"PAUSE= p";


	char *a, *b,*c;
	a = &ttd[0];
	b = &ttd1[0];
	c=  &ttd2[0];

	drawStrokeText(a, 490 / 10, 310 / 10, 0);
	drawStrokeText(b, 490 / 10, 270 / 10, 0);
	drawStrokeText(c, 500 / 10, 220 / 10, 0);


}



int random(int _min, int _max){

	srand(time(NULL));
	return _min + rand() % (_max - _min);


}




void Exel(int x, int y){
	glLoadIdentity();
	if (x == 10 || x == columns - 11 || y == 10 || y == rows - 10)
	{
		glLineWidth(4.0);
		//glColor3f(1.0,0.0,0.0);
		glColor3f(1.741, 0.718, 0.420);
		glBegin(GL_LINES);
		glVertex2d(x, y); glVertex2d(x + 1, y);
		glVertex2d(x + 1, y); glVertex2d(x + 1, y + 1);
		glVertex2d(x + 1, y + 1); glVertex2d(x, y + 1);
		glVertex2d(x, y + 1); glVertex2d(x, y);


		glEnd();
	}
	else if (x<10 || x>columns - 11 || y<10 || y>rows - 10){


		glColor3f(1, 0.0, 0.0);


	}
	else
	{
		//glColor3f(1.0,1.0,1.0);
		// glColor3f(1.941, 0.902, 0.549);
		//glColor3f(0.565, 0.933, 0.565);
		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2d(x, y); glVertex2d(x + 1, y);
		glVertex2d(x + 1, y); glVertex2d(x + 1, y + 1);
		glVertex2d(x + 1, y + 1); glVertex2d(x, y + 1);
		glVertex2d(x, y + 1); glVertex2d(x, y);


		glEnd();
	}

	//glFlush();







}





void reshape(int x, int y){


	glViewport(0, 0, (GLsizei)x, (GLsizei)y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, columns, 0.0, rows, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);



}



//gamepart

//Display function
void display(){

	//glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.000, 1.000, 0.941);
	//
	//glColor3f(0.000, 0.545, 0.545);
	//glColor3f(0.902, 0.902, 0.980);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	DrawExel();
	snake();
	food();
	DRAW_E();
	//DRAW_some();
	DRAW_Speed();
	DRAW_TEXT();
	if (pause == true){
		DRAW_PAUSE();
	}
	if (over == true){

		DRAW_GAME_OVER();
		DRAW_R();
		//PlaySound(TEXT("hiss"), NULL, SND_ASYNC | SND_FILENAME);
	}

	//cout << FPS;
	glutSwapBuffers();


}










// for text drawing

void drawBitmapText(char *string, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawStrokeText(char*string, int x, int y, int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y + 8, z);
	glScalef(x_bf, y_bf, z);

	for (c = string; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}


//num to string

string num_to_str(int num) {
	string s = "";
	do {
		int mod = num % 10;
		if (mod == 1) {
			s = '1' + s;
		}
		else if (mod == 2) {
			s = '2' + s;
		}
		else if (mod == 3) {
			s = '3' + s;
		}
		else if (mod == 4) {
			s = '4' + s;
		}
		else if (mod == 5) {
			s = '5' + s;
		}
		else if (mod == 6) {
			s = '6' + s;
		}
		else if (mod == 7) {
			s = '7' + s;
		}
		else if (mod == 8) {
			s = '8' + s;
		}
		else if (mod == 9) {
			s = '9' + s;
		}
		else if (mod == 0) {
			s = '0' + s;
		}
		num = num / 10;
	} while (num != 0);
	return s;
}










void timer(int){

	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);


}




void input(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (sd != DOWN)
			sd = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sd != UP)
			sd = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sd != LEFT)
			sd = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (sd != RIGHT)
			sd = LEFT;
		break;
	}

}
void keyboard(unsigned char key, int x, int y) {
	if (key == 'r') {
		if (over) RESTART();
	}
	if (key == 'R') {
		if (over) RESTART();

	}
	if (key == 'p') {
		if (!over) pause = !pause;

	}
	if (key == 'P') {
		if (!over) pause = !pause;

	}
	if (key == 'E'){

		exit(0);


	}

	if (key == 'e'){

		exit(0);


	}



	if (key == 'u'){


		FPS = FPS + 1;

	}

	if (key == 's'){

if (FPS>2){
		FPS = FPS - 1;}
		else
            FPS=2;

	}


}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1800, 1800);
	glutCreateWindow("2-D SNAKE ");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);

	glutSpecialFunc(input);
	glutKeyboardFunc(keyboard);
	start();
	glutMainLoop();
	return 0;



}








