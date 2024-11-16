
#include<windows.h>
#include <stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<sstream>
#include<time.h>

using namespace std;

//  Functions Initialization

void myinit();
string convertInt(int number);
string convertHealth(int number);
string convertBullets(int number);
void showstars();
void FireBulletsIfShot();
void drawship();
void drawlife();
void move(int x, int y);
void drawbullet();
void drawrefill();
void drawenemy();
void collisionship();
void collisionlife();
void collisionrefill();
void BulletsVsEnemyCollisionTest();
void rendertext(float x,float y, string strings);
void gameOver();
void display();
void Reinitialization();
void keyboard(unsigned char key, int x, int y);
void keyboard(int button, int x, int y);
void loop();
void gameMenu();


class myship            //class for spaceship
{
	public:

		double x;       //x and y coordinates
		double y;
		int shoot;
		int alive;    // checks player life Status
		double x1;
		double y1;
		double w1;
		double h1;

		myship()         //constructor
		{
			x=250;       //initial x and y position
			y=10;
			shoot=0;
			alive=1;      //alive or not
		}

		void information_for_collision()   // info about collision
        {
            x1=x-10;
            y1=0;
            w1=70;
            h1=y;
		}

		void move_left(int offset)     //moves the object left
		{
			x=x-offset;
		}

		void move_right(int offset)    //moves the object right
		{
			x=x+offset;
		}

		void move_up(int offset)    //moves the object up
		{
			y=y+offset;
		}

		void move_down(int offset)    //moves the object down
		{
			y=y-offset;
		}

		void displayShip()   //draws the ship
		{

            glColor3f(1,.498,0);
            glColor3f(.698,.698,.698);
			glBegin(GL_QUADS);
            glVertex2f(x-5,y-3);
            glVertex2f(x+35,y-3);
            glVertex2f(x+25,y+55);  //body
            glVertex2f(x+5,y+55);
            glEnd();


        //red box

            glColor3f(.89, 0.18, 0.06);
            glBegin(GL_POLYGON);
            glVertex2i(x*1,y+1);
            glVertex2i(x+31,y+1);
            glVertex2i(x+22,y+45);
            glVertex2i(x+8,y+45);
            glEnd();

        //left wing
            glColor3f(.698,.698,.698);
           glBegin(GL_QUAD_STRIP);
           glVertex2i(x,y+10);
           glVertex2i(x,y+30);
           glVertex2i(x-20,y+20);
           glVertex2i(x-20,y+12);
           glEnd();
        //right wing
            glColor3f(.698,.698,.698);
           glBegin(GL_QUAD_STRIP);
           glVertex2i(x+30,y+10);
           glVertex2i(x+30,y+30);
           glVertex2i(x+50,y+20);
           glVertex2i(x+50,y+12);
           glEnd();



        }

        void Constructor() //resets the ship object
        {
        	x=300;
			y=40;
			shoot=0;
			alive=1;
        }

};


#define n 600

myship ship;
int screenX = 600;      //screen size initialization
int screenY = 600;
int enemyX[581];        //Generates Random X positions for X
int lifeX[581];
int NOB;                //Number of Bullets
int NOF=4;              //Number of enemies per frame
static int sco=0;
static int temp=0;
float bulletspeed=.1;  //this value will be added to the y of bullet
static float enemyspeed=.1;   // speed at which enemy will fall
int counter=0;
int gamestate=0;
static int Health=100;
int c=0;
int lifec[10];
int NOL=4;
double lifes=.1;// speed of health and fire refill object
int bullets=11;

class bullet
{
	public:

		double x;
		double y;
		double x2;
		double y2;
		int firing;
		double x3;
		double y3;
		double w3;
		double h3;

		bullet()
		{
			firing=0;
		}

		void getPosition(myship ship)   // takes the position of ship
		{
			x=ship.x+2;
			y=ship.y+40;
			x2=ship.x+20;
			y2=ship.y+40;
		}

        void fire()
		{
           firing=1;
		}

		void draw()             //draws the bullet
		{
			glColor3f(1,0,0);
			glLineWidth(3);
			glBegin(GL_LINES);
            glVertex2f(x+8,y);
            glVertex2f(x+8,y+10);
			glEnd();

			glColor3f(1,0,0);
			glLineWidth(3);
			glBegin(GL_LINES);
            glVertex2f(x2,y2);
            glVertex2f(x2,y2+10);
			glEnd();
		}

		void move(float offset)   //ascends the bullet
		{
			y=y+offset;
			y2=y2+offset;
		}

		void reinit()         //initialize
		{
			firing=0;
		}

};


class enemy             //enemy class
{
	public:

        double x;           //initial position of x coordinate of enemy ship
        double y;           // initial position of y  coordinate of enemy spaceship
        int alive;          // enemy life status boolean value
        double x2;          //this the same x2 coordinate as we have declared earlier but this one will be retrieved for collision detection
        double y2;          //same as the above x2 t
        double w2;          //width of the object
        double h2;          //height of the object

        enemy()             // constructor for enemy
        {
            alive=1;        // enemy life status
        }

        void getcollsioninformation()  // this function send information about current position
        {

            x2=x-10;
            w2=40;
            y2=y+40;
            h2=y-10;

        }

        void init()
        {
            x=enemyX[rand()%screenX-19];
            y=screenY;
            alive=1;
        }
        void reinit()
        {
            x=enemyX[rand()%screenX-19];
            y=screenY;
            alive=0;
        }


        void draw()              //this draws the enemy
        {    glColor3f(.6,.23,.02);
            glBegin(GL_POLYGON);
            glVertex2i(x,y);
            glVertex2i(x+20,y+15);
            glVertex2i(x+10,y+35);
            glVertex2i(x-20,y+35);
            glVertex2i(x-20,y+15);
            glEnd();

            /*
             glColor3f(.6,.23,.02);
            glBegin(GL_POLYGON);
            glVertex2i(x,y);
            glVertex2i(x+20,y+15);
            glVertex2i(x+10,y+35);
            glVertex2i(x-20,y+35);
            glVertex2i(x-20,y+15);
            glEnd();
            glEnd();

          glColor3f(.6,.23,.02);
            glBegin(GL_QUADS);
            glVertex2f(x,y);   //BODY
            glVertex2f(x+20,y);
            glVertex2f(x+20,y+40);
            glVertex2f(x,y+40);
            glEnd();
             */
        }

        void move(float offset) //this function will be descend the enemy according a give speed which is offset in this case
        {
            y=y-offset;
        }

};

class life                      //health object
{
	public:

		double x;                //x and y coordinates of health object
		double y;
        double w2;
		double h2;
		double x2;
		int alive;                 //health state status
		void move(double offset)              // since stars will be falling y has to be decreased
		{
			y-=offset;
		}
		life()
		{
			x= rand()%screenX-19;
            y=screenY;
            alive=0;
		}
		void draw()     // draws the start
		{
		    //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0,1,0);
			glLineWidth(10);
			glBegin(GL_LINES);
            glVertex2f(x,y);
            glVertex2f(x,y+10);
			glEnd();
			//glFlush();
		}
		void getcollsioninformation()  // this function send information about current position
        {

            w2=14;
            x2=x-2;
            h2=y;

        }
        void drop()
		{
           alive=1;
		}
		void reinit()         //initialize
		{
			x= rand()%screenX-19;
            y=screenY;
            alive=0;
		}


};

class refillBullets                      //enemy refill bullet object
{
	public:

		double x;                //x and y coordinates of start
		double y;
        double w2;                //x and y coordinates of start
		double h2;
		double x2;
		int alive;
		void move(double offset)              // since stars will be falling y has to be decreased
		{
			y-=offset;
		}
		refillBullets()
		{
			x= rand()%screenX-19;
            y=screenY;
            alive=0;
		}
		void draw()     // draws the start
		{
		    //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0,0,1);
			glLineWidth(10);
			glBegin(GL_LINES);
            glVertex2f(x,y);
            glVertex2f(x,y+10);
			glEnd();
			//glFlush();
		}
		void getcollsioninformation()  // this function send information about current position
        {

            w2=14;
            x2=x-2;
            h2=y;

        }
        void drop()
		{
           alive=1;
		}
		void reinit()         //initialize
		{
			x= rand()%screenX-19;
            y=screenY;
            alive=0;
		}


};


bullet b[n];        //instance of bullet object
enemy e[4];         //enemy object
life l;             // life object
refillBullets r;    //Refill bullet object
int on=0;

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(screenX,screenY);
	glutInitWindowPosition(500,100);
	glutCreateWindow("Space Invaders Reloaded");
    glutDisplayFunc(loop);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard);
	myinit();
	glutMainLoop();
}

//start screen , play screen & game-over screen
void loop()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	switch(gamestate)
	{
		case 0: gameMenu();
            break;
        case 1: display();
            break;
		case 2: gameOver();
            break;
    }
}

// game start display
void display()
{
    start:
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //draw all the things
    drawship();
    drawlife();
	drawenemy();
	drawbullet();
	drawrefill();
    ship.information_for_collision();
    BulletsVsEnemyCollisionTest();
    collisionship();
    collisionlife();
    collisionrefill();

    //char score[10]={0};
    string sf="Score :"+ convertInt(sco);
    string ss="Health :"+ convertInt(Health);
    string sb="Bullets :"+ convertInt(bullets);
    rendertext(10,screenY-20,ss);
    rendertext(10,screenY-40,sf);
    rendertext(10,screenY-60,sb);

    if(Health<=0)
    {
        ship.alive=0;
        gamestate=2;
    }
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

// game over display
void gameOver()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	string txtGameover="GAME OVER";
	string txtTotalScore="Total Score : ";
	string txtRestart="Press r to restart";

	string temp=convertInt(sco);

	glColor3f(.26,.32,.77);
	glRasterPos2f(250,400);
	int i;
	for(i=0;i<=txtGameover.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtGameover[i]);

	}
	glRasterPos2f(250,350);;

	for(i=0;i<=txtTotalScore.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtTotalScore[i]);
	}

	for(i=0;i<=temp.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)temp[i]);
	}
	glRasterPos2f(250,300);

	for(i=0;i<=txtRestart.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtRestart[i]);
	}
    glFlush();
    glutSwapBuffers();

}
//
void gameMenu()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	string txtGameName="Space Invader Reloaded";
	string txtRules="Rules:";
	string txtStart="Press S to Start";
	string  txtRule1="Get Small Blue Boxes To reload Your Missiles";
	string  txtRule2="Get Small Green Boxes To Increase Your Life";
	string  txtRule3="Game Play Speed Will Increase Upon Your Score";

	string temp=convertInt(sco);

	glColor3f(.96,.75,.23);
	glRasterPos2f(250,500);
	int i;
	for(i=0;i<=txtGameName.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtGameName[i]);

	}

	glRasterPos2f(250,450);

	for(i=0;i<=txtStart.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtStart[i]);
	}

	glRasterPos2f(0,300);;

	for(i=0;i<=txtRules.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtRules[i]);
	}



	glRasterPos2f(20,250);

	for(i=0;i<=txtRule1.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtRule1[i]);
	}

	glRasterPos2f(20,200);

	for(i=0;i<=txtRule2.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtRule2[i]);
	}

	glRasterPos2f(20,150);

	for(i=0;i<=txtRule3.length();i++)
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)txtRule3[i]);
	}
    glFlush();
    glutSwapBuffers();

}

void drawship()       //renders the ship object
{

	if(ship.alive) //as long as the ship is alive
	{
		ship.displayShip(); //it will render the ship object
    }

	FireBulletsIfShot(); //if ship.shot is 1 it sets the bullet ready to shot

}

void FireBulletsIfShot()
{
    if(ship.shoot)                 //when ship.ship=1
	{
		b[NOB-1].fire();       //sets firing of bullet into 1
        b[NOB-1].getPosition(ship); //collects the current x position of ship
		ship.shoot=0;         //sets the shoot variable of ship into 0
	}
}

void drawbullet()    //renders bullet
{

int i;
        for(i=0;i<NOB;i++)
        {
            if(b[i].firing)
            {
                b[i].draw(); //renders
                b[i].move(bulletspeed); //move
            }
            if(b[i].y > screenX)
            {
                b[i].reinit();  //resets the bullet object when it goes beyond the screen

            }
        }


}

void drawenemy()
{

	int i;
	for(i=0;i<NOF;i++)
	{
	    if(sco>=20 && sco<30)
        {
            enemyspeed=.2;
        }
        if(sco>=30 && sco<40)
        {
            enemyspeed=.3;
        }
        if(sco>=40 && sco<50)
        {
            enemyspeed=.4;
        }

		if(e[i].alive)  //as long as the enemy is alive  it will be rendered
		{
			e[i].draw();             //render the each enemy
			e[i].move(enemyspeed);  //enemies will fall at this speed
			if(e[i].y -10 < -10)  //when the y coordinate of y will be 0 new enemies will be initialized
			{
				e[i].init();  //initialize
			}
		}
		if(e[i].alive==0) //if the current enemy is dead it will also be initialized
		{
            e[i].init();
		}
	}

}

void drawlife()
{


	    if(sco==temp+2)
       {
            if(Health<50)
                l.drop();
            temp=sco;
        }

        if(sco==15&&Health!=100)
            l.drop();

        if(sco==25&&Health!=100)
            l.drop();

        if(sco==35&&Health!=100)
            l.drop();



		if(l.alive)  //as long as the health is alive  it will be rendered
		{
			l.draw();             //render the each enemy
			l.move(lifes);  //health will fall at this speed
			if(l.y -5 < -10)  //when the y coordinate of y will be 0 new health will be initialized
			{
				l.reinit();  //initialize
			}
		}
}

void drawrefill()
{

	    if(bullets==10)
        {
            r.drop();
        }

         if(bullets==0)
        {
            r.drop();
        }

		if(r.alive)  //as long as the bullet refill is alive  it will be rendered
		{
			r.draw();             //render the each bullet-refill
			r.move(lifes);  //bullet-refill will fall at this speed
			if(r.y -10 < -10)  //when the y coordinate of y will be 0 new bullet-refill will be initialized
			{
				r.reinit();  //initialize
			}
		}
}


 // Collision detection of enemy with space ship
void collisionship()
{

    for(int i=0;i<NOF;i++)
    {

        e[i].getcollsioninformation();
        ship.information_for_collision();

        if((ship.x1<(e[i].x2+e[i].w2)) &&(e[i].x2<ship.x1+ship.w1))
        {
            if(ship.y<=e[i].h2+5 && ship.y>=e[i].h2-5)
            {

                Health=Health-10;
                e[i].reinit();
            }
        }

    }

}

// Collision detection for health object
void collisionlife()
{


        l.getcollsioninformation();
        ship.information_for_collision();


        if((ship.x1<(l.x2+l.w2)) &&(l.x2<ship.x1+ship.w1))
        {
            if(ship.y<=l.h2+5 && ship.y>=l.h2-5)
            {

                Health=Health+10;
                l.reinit();
            }
        }


}
// Collision detection for bullet refill object
void collisionrefill()
{


        r.getcollsioninformation();
        ship.information_for_collision();


        if((ship.x1<(r.x2+r.w2)) &&(r.x2<ship.x1+ship.w1))
        {
            if(ship.y<=r.h2+5 && ship.y>=r.h2-5)
            {


                bullets=bullets+10;
                r.reinit();
            }
        }


}


// Collision detection for bullet and enemy
void BulletsVsEnemyCollisionTest()
{
    int i;
	int j;
	for(i=0;i<NOB;i++)
	{
        for(j=0;j<NOF;j++)
        {
            e[j].getcollsioninformation();
            if(e[j].x2<=b[i].x && b[i].x <= (e[j].x2+e[j].w2) && e[j].alive)
            {
                if(b[i].y<=e[j].h2+5 && b[i].y>=e[j].h2-5)
                {
                    e[j].alive=0;
                    b[i].firing=0;
                    b[i].x=0;
                    b[i].y=0;
                    sco +=1;
                }


            }
            else if(e[j].x2<=b[i].x2 && b[i].x2 <= (e[j].x2+e[j].w2) && e[j].alive)
            {
				if(b[i].y2<=e[j].h2+5 && b[i].y2>=e[j].h2-5)
                {
                    e[j].alive=0;
                    b[i].firing=0;
                    b[i].x2=0;
                    b[i].y2=0;
                    sco +=1;
                }

            }
        }
    }

}


// render text  and show it
void rendertext(float x,float y, string strings)
{

    glColor3f(.26,.32,.77);

    glRasterPos2d(x,y);
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    for(int i=0;i<=strings.length();i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)strings[i]);
    }
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);

}

string convertInt(int number)
{
    stringstream ss;

    ss << number;
    return ss.str();
}

string convertHealth(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

string convertBullets(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}


//keyboard input for fire
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	    //case 32:
		case 32:
		    if(ship.alive)
            {
                if(bullets>0)
                {
                    ship.shoot=1;
                    NOB++;
                    bullets--;
                }
            }
		break;

		case 'R':
		case 'r':
		    if(ship.alive==0)
			{
                Reinitialization();
                gamestate=1;
			}
			break;
        case 'S':
        case 's':
            gamestate=1;
            break;

    }
	glutPostRedisplay();
}

//keyboard inputs for movement
void keyboard(int button, int x, int y)
{
    if (button == GLUT_KEY_RIGHT)
    {
        if(ship.x<=screenX-60)
            ship.x=ship.x+10;

    }
    else if (button == GLUT_KEY_LEFT)
    {
        if(ship.x>=30)
            ship.x=ship.x-10;
    }
    else if (button == GLUT_KEY_DOWN)
    {
        if(ship.y>=20)
            ship.y=ship.y-10;
    }
    else if (button == GLUT_KEY_UP)
    {
        if(ship.y<=screenY-60)
            ship.y=ship.y+10;
    }
    //update display
    glutPostRedisplay();
}

// Reset  All the functions
void Reinitialization()
{

	ship.Constructor();
    Health=100;
    enemyspeed=.1;
    bullets=11;
	sco=0;
	int i;
	NOF=4;

	for(i=0;i<NOF;i++)
	{
		e[i].init();
	}

	return;
}


void myinit()
{
    int i;
	int inc=10;
	for(i=0;i<screenX-19;i++)
	{
		enemyX[i]=inc;
		inc++;
	}

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, screenX, 0.0, screenY);

}













