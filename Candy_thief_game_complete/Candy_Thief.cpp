
#include <iostream>
#include <string>
#include <cmath>
#include <GL/glut.h>
#include <sstream>
#include <fstream>

#include "DrawText.h"
#include "Game_Logo.h"
#include "BackCharacters.h"
#include "MenuPages.h"
#include "Pointer.h"
#include "Green_Field.h"
#include "Main_Menu.h"

using namespace std;

/// ------------------------------ Global Variables ----------------------------

int s = 1;                         /// Initialized Game On Start Display Screen
int mouseX = 0, mouseY = 0;        /// Takes Mouse Coordinates
int lifeGone = 1;                  /// Fill Players HP @100%
int score = 0;                     /// Initialize Player Score @0 (Zero)
int levelstate = 50;               /// Control Different Level State
int high_score;                    /// For Displaying High Score

class Candy
{
    /// --------------------------- Candy Object Class ------------------------

    public:
        int posX;
        int posY;
        float movedPos;
        int colorcandy;
        bool visibility;
        Candy()
        {
            visibility = false;	movedPos = 0;
        }
};

/// -------------------------- Creating Candy Object ----------------------------

Candy r[2][3];

void DrawCandy(int X, int Y, int color)
{
    /// --------------------------------- Function For Draw Candy on Game Display ------------------------

	X += 600;
	Y += 300;

	glBegin(GL_POLYGON);

	if(color == 1)
        glColor3ub(255, 89, 255);
	else if(color == 2)
        glColor3f(0,1,0);

	glVertex2f(X + 12, Y + 5);
	glVertex2f(X + 17, Y);
	glVertex2f(X + 32, Y);
	glVertex2f(X + 37, Y + 5);
	glVertex2f(X + 37, Y + 20);
	glVertex2f(X + 22, Y + 25);
	glVertex2f(X + 17, Y + 25);
	glVertex2f(X + 12, Y + 20);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(X + 16, Y + 18);
	glVertex2f(X + 19, Y + 15);
	glVertex2f(X + 31, Y + 15);
	glVertex2f(X + 34, Y + 18);
	glVertex2f(X + 34, Y + 23);
	glVertex2f(X + 31, Y + 26);
	glVertex2f(X + 19, Y + 26);
	glVertex2f(X + 16, Y + 23);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(X + 16, Y -1);
	glVertex2f(X + 19, Y -1);
	glVertex2f(X + 31, Y -1);
	glVertex2f(X + 34, Y + 3);
	glVertex2f(X + 34, Y + 3);
	glVertex2f(X + 31, Y + 4);
	glVertex2f(X + 19, Y + 4);
	glVertex2f(X + 16, Y + 3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(X + 23, Y + 0);
	glVertex2f(X + 25, Y + 0);
	glVertex2f(X + 25, Y - 30);
	glVertex2f(X + 23, Y - 30);
	glEnd();
}

void MoveCandy()
{
    /// -------------------------- Function For Moving Candy on Game Display --------------------------------

	int a = 200;
	float sp = 3;
	for (int i = 0; i < 3; i++)
	{
        /// ------------------------- Pink Candy Score @1 -----------------------------

		sp=sp<2.5?3.5:sp;
		r[0][i].movedPos -= sp;
		if (r[0][i].movedPos <= -550)
        {
			r[0][i].movedPos = 0;
			r[0][i].visibility = true;
		}
		r[0][i].colorcandy = 1;
		if (r[0][i].visibility == true)	DrawCandy((int)r[0][i].movedPos, a, r[0][i].colorcandy);
		r[0][i].posX = (int)r[0][i].movedPos + 600;

		///-------------------------- Green Candy Score @2 -----------------------------

		r[1][i].movedPos -= sp;
		if (r[1][i].movedPos <= -550) {
			r[1][i].movedPos = 0;
			r[1][i].visibility = true;
		}
		r[1][i].colorcandy = 2;
		if (r[1][i].visibility)	DrawCandy((int)r[1][i].movedPos, a, r[1][i].colorcandy);
		r[1][i].posX = (int)r[1][i].movedPos + 600;

		a -= 210;
		sp --;
	}
}

bool ShootCandy(int x)
{
    /// -------------------------- Function For Steal Candy & Score --------------------------------

	for (int i = 0; i<2; i++) {                         /// Right Area              ///Left Area Adjustment
		if (r[i][x].visibility == true && r[i][x].posX  <= mouseX+15 && r[i][x].posX >= mouseX -57) {

			if(r[i][x].colorcandy == 1)
                score++;
            else
                score+=2;
            r[i][x].visibility = false;
			return true;
		}
	}
	return false;
}

void reshape(int window_width, int window_height)
{
    ///---------------------------- Default Reshape Function ------------------------------

    glutReshapeWindow(800, 600);
}

void myInit(void)
{
    /// ------------------------- Function For Initialize Glut Window Properties --------------------

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1366.0, 0.0, 768.0);
}

void background()
{
    /// ----------------------------- Function For Display Game Background ----------------------------
    ///---------------------------------Background field-------------------------------------

    greenfield();

    /// -------------------------------------Yellow Background -----------------------------------

    glColor3f(1,1,0);glRecti(0,0,800,32);glRecti(0,570,800,650);glRecti(755,0,800,650);

    /// --------------------------------- Game Screen Scores Display -----------------------------

    glColor3ub(0,0,0);
    string text;
    text = "HP Meter";
    DrawText(text.data(), text.size(), 610 , 10);
    text = "Score: ";
    DrawText(text.data(), text.size(), 10, 580);
    int num = score;

    stringstream ss;
    ss << num<< endl;

    string newstring = ss.str();
    DrawText(newstring.data(), newstring.size(), 80, 580);
    text = "Missed Candy: ";
    DrawText(text.data(), text.size(), 120, 580);

    int num1 = lifeGone-1;
    stringstream ss1;
    ss1<<num1<<endl;

    string newstring1 = ss1.str();
    DrawText(newstring1.data(), newstring1.size(), 270, 580);

    /// -------------------------------- Background Candy Tray ------------------------------------------

    glColor3ub(0,0,0);
    glRecti(85, 32, 675, 125);
    glRecti(85, 240, 675, 334);
    glRecti(85, 447, 675, 543);

    glColor3f(0, 0, 1);
    glRecti(85, 125, 675, 150);
    glRecti(85, 215, 675, 240);
    glRecti(85, 334, 675, 359);
    glRecti(85, 422, 675, 447);

    /// --------------------------------- Background Tower & Character Display ----------------------------

    BackgroundCharacter(10,10);
    BackgroundCharacter(35,210);
    BackgroundCharacter(60,410);

    glPushMatrix();
    glRotated(1,0,1,5000000);
    BackgroundTower(680,32);
    BackgroundTower(685,240);
    BackgroundTower(690,430);
    glPopMatrix();
}

void update(int value)
{
    /// ---------------------------- Function For Controlling Candy Speed Based on Score --------------------

    if(score < 10)
        levelstate = 50;
    else if(score >=10 && score < 20)
        levelstate = 40;
    else if(score >= 21 && score < 30)
        levelstate = 25;
    else if(score >= 30 && score < 50)
        levelstate = 20;
    else if(score >= 50 && score <80)
        levelstate = 16;
    else if(score >= 80 && score <100)
        levelstate = 13;
    else if(score >= 100)
        levelstate = 10;

	MoveCandy();
	glutPostRedisplay();
	glutTimerFunc(levelstate, update, 0);
}

void lifeBar()
{
    /// ------------------------------ Function For Display Life Indicator -------------------------

	if(lifeGone == 1 || lifeGone == 2)
        glColor3f(0, .5, 0);
    else if(lifeGone == 3 || lifeGone == 4)
        glColor3f(0, .8, 0);
    else if(lifeGone == 5 || lifeGone == 6)
        glColor3f(0, 1, 0);
    else if(lifeGone == 7 || lifeGone == 8)
        glColor3f(.6, 0, 0);
    else if(lifeGone == 9 || lifeGone == 10)
        glColor3f(1, 0, 0);

	if (lifeGone<11) {
		glBegin(GL_QUADS);
		glVertex2f(595, 5);
		glVertex2f(595, 30);
		glVertex2f(5 + (50 * lifeGone), 30);
		glVertex2f(5 + (50 * lifeGone), 5);
		glEnd();
	}
}

void gameOver()
{
    /// ------------------------ Final Screen After Game Finished -------------------

    string text;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0.0, 0.749, 1.0, 0.0);
    GameOverLogo(167,250,125);

    glColor3f(0,0,0);
    text = "Final Score: ";
    DrawText(text.data(), text.size(), 340, 250);
    int num = score;

    stringstream ss;
    ss << num<< endl;

    string newstring = ss.str();
    DrawText(newstring.data(), newstring.size(), 470, 250);
    text = "High Score: ";
    DrawText(text.data(), text.size(), 340, 220);

    stringstream sp;
    sp << high_score <<endl;

    string newstring1 = sp.str();
    DrawText(newstring1.data(), newstring1.size(), 470, 220);
}

static void Play()
{
    /// ---------------------------------- Main Game Display Function -------------------------------------

    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.000, 0.980, 0.804, 0.0);
    POINT mpos;
	ShowCursor(false);
	GetCursorPos(&mpos);
    background();
    if (lifeGone <= 10)
        {
            glPointSize(2);
            MoveCandy();
            lifeBar();

            glLoadIdentity();
            glTranslatef(mpos.x - 6, 637 - mpos.y, 0);
            Draw_pointer(0, 0, 7, 10);
            Second_Draw_Pointer(0,0,12,10);
            glLoadIdentity();

            if(score > high_score)
            {
                high_score = score;

                ofstream h;
                h.open("Game Data.class");

                h<<high_score;
                h.close();
            }        }
    else
        gameOver();

    glFlush();
}

void mouse1(int button, int state, int x, int y)
{
    /// --------------------------- Mouse Function For Game Display ----------------------

    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
            {
                bool clickColide;
                mouseX = x;
                mouseY = 600 - y;
                if (mouseY >= 490 && mouseY <= 525)
                    clickColide = ShootCandy(0);
                else if (mouseY >= 280 && mouseY <= 315)
                    clickColide = ShootCandy(1);
                else if (mouseY >= 70 && mouseY <= 105)
                    clickColide = ShootCandy(2);
                else clickColide = false;
                    if (!clickColide)
                        lifeGone++;
                glutPostRedisplay();
            }

            break;
    }
}

void windowposition1(int xp, int yp)
{
    /// ----------------------- Mouse Motion Function For Game Display -----------------------

    mouseX = xp;
    mouseY = yp;

    glutPostRedisplay();
}
void game_quit_keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'Q':
        case 'q':
        case 27:
            exit(0);
        break;
    }
}

void setCharPos()
{
    /// --------------------------Function For Moving Candy After Stealing --------------------

	for (int j = 0; j<3; j++) {
		r[1][j].movedPos = 310;
	}
}

void nnew(void)
{
    /// ---------------------------------- Game Display Function -----------------------------

    glutDestroyWindow(1);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Candy Thief");
    myInit();
    glutDisplayFunc(Play);
    glutReshapeFunc(reshape);
    glutTimerFunc(levelstate, update, 0);
    glutKeyboardFunc(game_quit_keyboard);
    glutMouseFunc(mouse1);
    glutMotionFunc(windowposition1);
    glutMainLoop();
}

void Selection(void)
{
    /// ------------------------ Function For Selecting Option in Start Screen -------------------------

    switch(s)
    {
        case 1:
            Start_Screen();
            break;
        case 2:
            Credits();
            break;
        case 3:
            Help();
            break;
        case 4:
            nnew();
            break;
        case 0:
            exit(0);

    }
}

void keyboard(unsigned char key, int x, int y)
{
    /// ---------------------------------- Main Keyboard Function For Normal Keyboard Inputs -------------------------

    if(s==1)
    {
        switch (key)
        {
            case 'Q':
            case 'q':
            case 27:
                s = 0;
                break;

            case 'H':
            case 'h':
                s = 3;
                break;

            case 'P':
            case 'p':
                s = 4;
                break;
            case 'C':
            case 'c':
                s = 2;
                break;

            glutPostRedisplay();
        }
    }
    else if(s == 2)
    {
        switch(key)
        {
            case 'B':
            case 'b':
                s = 1;
                break;
            case 'Q':
            case 'q':
                s = 0;;
                break;
        }
        glutPostRedisplay();
    }
    else if(s == 3)
    {
        if(key == 'B' || key == 'b')
            s = 1;
        else if(key == 'Q' || key == 'q')
            s = 0;
        glutPostRedisplay();
    }
    else if(s == 4)
    {
        if(key == 'B' || key == 'b')

            s = 1;
        else if(key == 'Q' || key == 'q')
            s = 0;
        glutPostRedisplay();
    }
}

void keyboard1(int key, int x, int y)
{
    /// ---------------------------------- Main Keyboard Function For Special Keyboard Inputs -------------------------

    if(s==1)
    {
        switch (key)
        {
            case GLUT_KEY_F1 :
                s = 3;
                break;
            glutPostRedisplay();
        }
    }
}

void mouse(int button, int state, int x, int y)
{
    /// --------------------- Mouse Function For Start Display Screen -----------------------

    mouseX = x;
    mouseY = y;
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
            {
                if(s == 1)
                {
                    if(mouseX >=256 && mouseX <= 768)
                            if(mouseY >= 288 && mouseY <= 350)
                            {
                                s = 4;
                                glutDisplayFunc(nnew);
                            }
                    else if(mouseX >=256 && mouseX <= 768)
                            if(mouseY >= 492 && mouseY <= 538)
                            {
                                s = 0;
                                glutIdleFunc(Selection);
                                glutPostRedisplay();
                            }
                }
            }

                break;

        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(NULL);
                break;

        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(NULL);
                break;
        default:
            break;
    }
}

void windowposition(int xp, int yp)
{
    /// --------------------- Mouse Motion Function For Start Display Screen -------------------
    mouseX = xp;
    mouseY = yp;

    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    /// ------------------------------ Main Function -----------------------------

    ifstream in;
    in.open("Game Data.class");
    in>>high_score;
    in.close();
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    setCharPos();
    glutCreateWindow("Candy Thief");
    myInit ();
    glutDisplayFunc(Selection);
    glutReshapeFunc(reshape);
    glutTimerFunc(levelstate, update, 0);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboard1);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(windowposition);

    glutMainLoop();

    return 0;
}
