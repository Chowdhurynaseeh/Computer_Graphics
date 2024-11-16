
#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;
float _move = 0.0;
int  d, x, y;
float w1posx = -250, w2posx = 0, w3posx = 0;
float c1posy = 0, c2posy = 0, c3posy = 0;
float bposx = 0;
int sky_color_day[] = {52, 196, 225};
int sky_color_night[] = {51, 60, 79};
int factory1_color[] = {168, 182, 55};
int factory2_color[] = {158, 135, 92};
int water_color_day[] = {118, 246, 224};
int water_color_night[] = {97, 150, 214};
int soil_color_day[] = {124, 94, 34};
int soil_color_night[] = {151, 105, 13};
int chimney_color_top[] = {203, 190, 161};
int chimney_color_body[] = {214, 165, 55};
int chimney_color_border[] = {24, 16, 2};
int sun_color[] = {243, 94, 29  };
int moon_color[] = {239, 228, 223};
int factory_glass_color[] = {253, 238, 238};
int tree_leaf_color[] = {70, 211, 39};
int tree_root_color[] = {81, 36, 19};
int pipe1_fill_color[] = {133, 133, 102};
int pipe2_fill_color[] = {133, 133, 102};
int pipe1_border_color[] = {80, 80, 70};
int pipe2_border_color[] = {80, 80, 70};
int pipe_pollution1_color[] = {178, 199, 85};
int pipe_pollution2_color[] = {108, 159, 107};
int water_pollution_color[] = {56, 61, 51};
int chimney_gas_color[] = {157, 148, 147};
int day_night_check = 1;
int run = 1;


void draw_circle(int xC, int yC, int Radius)
{
    d = 1 - Radius;
    x = 0;
    y = Radius;

    while (y > x)
    {
        if (d < 0)
        {
            d = d + 2 * x + 3;
            x++;
        }
        else
        {
            d = d + 2 * (x - y) + 5;
            x++;
            y--;
        }
        glVertex2i(xC + x, yC + y);
        glVertex2i(xC + x, yC - y);
        glVertex2i(xC - x, yC + y);
        glVertex2i(xC - x, yC - y);
        glVertex2i(xC + y, yC + x);
        glVertex2i(xC - y, yC + x);
        glVertex2i(xC + y, yC - x);
        glVertex2i(xC - y, yC - x);
    }
}

void water_pollution(int key)
{
    glPushMatrix();
    if(key == 0)
        glTranslatef(w1posx, 0.0, 0.0);
    else
    {
        if(w1posx == 900)
            w1posx = -250;

        glTranslatef(w1posx = w1posx + .5, 0, 0.0);
        //glTranslatef(500, 0, 0.0);
    }
    //water pollution 1
    glColor3ub(water_pollution_color[0], water_pollution_color[1], water_pollution_color[2]);//water pollution color
    glBegin(GL_LINE_STRIP);
    draw_circle(150, 60, 30);
    draw_circle(170, 80, 30);
    draw_circle(200, 90, 30);
    draw_circle(210, 50, 30);
    draw_circle(180, 40, 30);
    glEnd();
    glutPostRedisplay();
    glPopMatrix();

    glPushMatrix();
    if(key == 0)
        glTranslatef(w2posx, 0.0, 0.0);
    else
    {
        if(w2posx == -250)
            w2posx = 900;

        glTranslatef(w2posx = w2posx - 1, 0, 0.0);
    }
    glBegin(GL_POLYGON);
    glVertex2i(100, 150);
    glVertex2i(130, 150);
    glVertex2i(140, 160);
    glVertex2i(130, 170);
    glVertex2i(100, 170);
    glVertex2i(90, 160);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    if(key == 0)
        glTranslatef(w3posx, 0.0, 0.0);
    else
    {
        if(w3posx == 100)
            w3posx = -480;

        glTranslatef(w3posx = w3posx + 1, 0, 0.0);
    }
    glBegin(GL_POLYGON);
    glVertex2i(900, 320);
    glVertex2i(930, 320);
    glVertex2i(940, 330);
    glVertex2i(930, 340);
    glVertex2i(900, 340);
    glVertex2i(890, 330);
    glEnd();
    glPopMatrix();
}

void factory_pipe()
{
    //factory 1 pipe
    glColor3ub(pipe1_border_color[0], pipe1_border_color[1], pipe1_border_color[2]); //factory 1 color
    glBegin(GL_POINTS);
    draw_circle(450, 420, 40);
    glEnd();


    glColor3ub(pipe1_fill_color[0], pipe1_fill_color[1], pipe1_fill_color[2]); //factory 1 color
    glBegin(GL_LINE_STRIP);
    draw_circle(450, 420, 36);
    glEnd();

    //factory 2 pipe
    glColor3ub(pipe2_border_color[0], pipe2_border_color[1], pipe2_border_color[2]); //factory 2 color
    glBegin(GL_POINTS);
    draw_circle(600, 440, 40);
    glEnd();

    glColor3ub(pipe2_fill_color[0], pipe2_fill_color[1], pipe2_fill_color[2]); //factory 1 color
    glBegin(GL_LINE_STRIP);
    draw_circle(600, 440, 36);
    glEnd();
}

void factory()
{
    //factory 1 fill
    glColor3ub(factory1_color[0], factory1_color[1], factory1_color[2]); //factory 1 color
    glBegin(GL_POLYGON);
    glVertex2i(0, 700);
    glVertex2i(100, 750);
    glVertex2i(130, 700);
    glVertex2i(130, 535);
    glVertex2i(0, 520);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(130, 700);
    glVertex2i(300, 800);
    glVertex2i(330, 750);
    glVertex2i(330, 560);
    glVertex2i(130, 535);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(330, 750);
    glVertex2i(450, 830);
    glVertex2i(470, 790);
    glVertex2i(470, 580);
    glVertex2i(330, 560);
    glEnd();

    //factory 2 fill
    glColor3ub(factory2_color[0], factory2_color[1], factory2_color[2]); //factory 2 color
    glBegin(GL_POLYGON);
    glVertex2i(470, 600);
    glVertex2i(870, 660);
    glVertex2i(870, 890);
    glVertex2i(850, 930);
    glVertex2i(730, 850);
    glVertex2i(700, 900);
    glVertex2i(530, 800);
    glVertex2i(500, 850);
    glVertex2i(450, 830);
    glEnd();
}

void factory_chimney()
{
    //factory 1 chimney 1 border
    glColor3ub(chimney_color_border[0], chimney_color_border[1], chimney_color_border[2]);
    glBegin(GL_LINE_STRIP);
    glVertex2i(135, 705);
    glVertex2i(135, 805);
    glVertex2i(145, 815);
    glVertex2i(180, 815);
    glVertex2i(190, 805);
    glVertex2i(190, 735);
    glVertex2i(135, 705);
    glEnd();

    //factory 1 chimney 1 body fill
    glColor3ub(chimney_color_body[0], chimney_color_body[1], chimney_color_body[2]);
    glBegin(GL_POLYGON);
    glVertex2i(135, 705);
    glVertex2i(135, 805);
    glVertex2i(190, 805);
    glVertex2i(190, 735);
    glEnd();

    //factory 1 chimney 1 top fill
    glColor3ub(chimney_color_top[0], chimney_color_top[1], chimney_color_top[2]);
    glBegin(GL_POLYGON);
    glVertex2i(135, 805);
    glVertex2i(145, 815);
    glVertex2i(180, 815);
    glVertex2i(190, 805);
    glEnd();

    //factory 1 chimney 2 border
    glColor3ub(chimney_color_border[0], chimney_color_border[1], chimney_color_border[2]);
    glBegin(GL_LINE_STRIP);
    glVertex2i(335, 755);
    glVertex2i(335, 905);
    glVertex2i(345, 915);
    glVertex2i(380, 915);
    glVertex2i(390, 905);
    glVertex2i(390, 790);
    glVertex2i(335, 755);
    glEnd();

    //factory 1 chimney 2 body fill
    glColor3ub(chimney_color_body[0], chimney_color_body[1], chimney_color_body[2]);
    glBegin(GL_POLYGON);
    glVertex2i(335, 755);
    glVertex2i(335, 905);
    glVertex2i(390, 905);
    glVertex2i(390, 790);
    glEnd();

    //factory 1 chimney 2 top fill
    glColor3ub(chimney_color_top[0], chimney_color_top[1], chimney_color_top[2]);
    glBegin(GL_POLYGON);
    glVertex2i(345, 915);
    glVertex2i(380, 915);
    glVertex2i(390, 905);
    glVertex2i(335, 905);
    glEnd();

    //factory 2 chimney 1 border
    glColor3ub(chimney_color_border[0], chimney_color_border[1], chimney_color_border[2]);
    glBegin(GL_LINE_STRIP);
    glVertex2i(575, 825);
    glVertex2i(575, 905);
    glVertex2i(585, 915);
    glVertex2i(620, 915);
    glVertex2i(630, 905);
    glVertex2i(630, 860);
    glVertex2i(575, 825);
    glEnd();

    //factory 2 chimney 1 body fill
    glColor3ub(chimney_color_body[0], chimney_color_body[1], chimney_color_body[2]);
    glBegin(GL_POLYGON);
    glVertex2i(575, 905);
    glVertex2i(575, 825);
    glVertex2i(630, 860);
    glVertex2i(630, 905);
    glEnd();

    //factory 2 chimney 1 top fill
    glColor3ub(chimney_color_top[0], chimney_color_top[1], chimney_color_top[2] );
    glBegin(GL_POLYGON);
    glVertex2i(585, 915);
    glVertex2i(620, 915);
    glVertex2i(630, 905);
    glVertex2i(575, 905);
    glEnd();
}

void river_border()
{
    //border fill
    glColor3ub(75, 33, 2); //border color
    glBegin(GL_POLYGON);
    glVertex2i(0, 400);
    glVertex2i(400, 450);
    glVertex2i(630, 480);
    glVertex2i(1000, 530);
    glVertex2i(1000, 400);
    glVertex2i(0, 300);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(400, 450);
    glVertex2i(360, 460);
    glVertex2i(660, 500);
    glVertex2i(630, 480);
    glEnd();
}

void sky(int key)
{
    if(key == 1)
        glColor3ub(sky_color_day[0], sky_color_day[1], sky_color_day[2]); //sky color day
    else
        glColor3ub(sky_color_night[0], sky_color_night[1], sky_color_night[2]); //sky color night

    glBegin(GL_POLYGON);
    glVertex2i(0, 1000);
    glVertex2i(1000, 1000);
    glVertex2i(1000, 700);
    glVertex2i(0, 700);
    glEnd();
}

void water(int key)
{
    if(key == 1)
        glColor3ub(water_color_day[0], water_color_day[1], water_color_day[2]); //water color day
    else
        glColor3ub(water_color_night[0], water_color_night[1], water_color_night[2]); //water color night

    glBegin(GL_POLYGON);
    glVertex2i(0, 300);
    glVertex2i(1000, 440);
    glVertex2i(1000, 0);
    glVertex2i(0, 0);
    glEnd();
}

void soil(int key)
{
    if(key == 1)
        glColor3ub(soil_color_day[0], soil_color_day[1], soil_color_day[2]); //soil color day
    else
        glColor3ub(soil_color_night[0], soil_color_night[1], soil_color_night[2]); //soil color night

    glBegin(GL_POLYGON);
    glVertex2i(0, 700);
    glVertex2i(1000, 700);
    glVertex2i(1000, 350);
    glVertex2i(0, 350);
    glEnd();
}

void pipe_pollution1()
{
    //circle
    glColor3ub(pipe_pollution1_color[0], pipe_pollution1_color[1], pipe_pollution1_color[2]);
    glBegin(GL_LINES);
    draw_circle(440, 340, 30);
    draw_circle(455, 330, 30);
    draw_circle(490, 310, 30);
    draw_circle(515, 300, 30);
    draw_circle(550, 290, 30);
    draw_circle(580, 290, 30);
    draw_circle(600, 290, 30);
    draw_circle(610, 300, 30);
    draw_circle(620, 320, 30);
    draw_circle(625, 340, 30);
    draw_circle(635, 350, 30);
    draw_circle(645, 360, 30);
    draw_circle(655, 370, 30);
    glEnd();
}

void pipe_pollution2()
{
    glColor3ub(pipe_pollution2_color[0], pipe_pollution2_color[1], pipe_pollution2_color[2]);
    glBegin(GL_POLYGON);
    glVertex2i(410, 358);
    glVertex2i(660, 393);
    glVertex2i(550, 260);
    glEnd();
}

void sun_moon(int key)
{
    if(key == 1)
        glColor3ub(sun_color[0], sun_color[1], sun_color[2]); //sun color
    else
        glColor3ub(moon_color[0], moon_color[1], moon_color[2]); //moon color

    glBegin(GL_LINE_STRIP);
    draw_circle(480, 950, 40);
    glEnd();
}

void factory_glass()
{
    glColor3ub(factory_glass_color[0], factory_glass_color[1], factory_glass_color[2]); //factory glass color
    //factory 1 glass 1
    glBegin(GL_QUADS);
    glVertex2i(100, 660);
    glVertex2i(100, 700);
    glVertex2i(70, 700);
    glVertex2i(70, 660);
    glEnd();

    //factory 1 glass 2
    glPushMatrix();
    glTranslatef(180, 40, 0);
    glBegin(GL_QUADS);
    glVertex2i(100, 660);
    glVertex2i(100, 700);
    glVertex2i(70, 700);
    glVertex2i(70, 660);
    glEnd();
    glPopMatrix();

    //factory 1 glass 3
    glPushMatrix();
    glTranslatef(340, 80, 0);
    glBegin(GL_QUADS);
    glVertex2i(100, 660);
    glVertex2i(100, 700);
    glVertex2i(70, 700);
    glVertex2i(70, 660);
    glEnd();
    glPopMatrix();

    //factory 2 glass 1
    glPushMatrix();
    glTranslatef(420, 100, 0);
    glBegin(GL_QUADS);
    glVertex2i(100, 660);
    glVertex2i(100, 700);
    glVertex2i(70, 700);
    glVertex2i(70, 660);
    glEnd();
    glPopMatrix();

    //factory 2 glass 2
    glPushMatrix();
    glTranslatef(570, 130, 0);
    glBegin(GL_QUADS);
    glVertex2i(100, 660);
    glVertex2i(100, 700);
    glVertex2i(70, 700);
    glVertex2i(70, 660);
    glEnd();
    glPopMatrix();

    //factory 2 glass 3
    glPushMatrix();
    glTranslatef(750, 160, 0);
    glTranslatef(.5, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(100, 660);
    glVertex2i(100, 700);
    glVertex2i(70, 700);
    glVertex2i(70, 660);
    glEnd();
    glPopMatrix();
}

void tree()
{
    glPushMatrix();
    glTranslatef(500, 100, 0);
    //tree 1 leaf
    glColor3ub(tree_leaf_color[0], tree_leaf_color[1], tree_leaf_color[2]); //tree leaf color
    glBegin(GL_LINE_STRIP);
    draw_circle(105, 550, 25);
    draw_circle(80, 520, 25);
    draw_circle(120, 520, 25);
    glEnd();

    //tree 1 root
    glColor3ub(tree_root_color[0], tree_root_color[1], tree_root_color[2]); //tree root color
    glBegin(GL_QUADS);
    glVertex2i(120, 430);
    glVertex2i(130, 500);
    glVertex2i(70, 500);
    glVertex2i(90, 430);
    glEnd();
    glPopMatrix();
}

void chimney_gas()
{
    glColor3ub(chimney_gas_color[0], chimney_gas_color[1], chimney_gas_color[2]); //gas color
    //factory 1 chimney 1 gas
    glPushMatrix();
    if(run == 0)
        glTranslatef(0, c1posy, 0);
    else
    {
        if(c1posy == 200)
            c1posy = 0;

        glTranslatef(0, c1posy = c1posy + .5, 0);
    }
    glBegin(GL_LINE_STRIP);
    draw_circle(150, 850, 20);
    draw_circle(150, 880, 20);
    draw_circle(170, 890, 20);
    draw_circle(180, 880, 20);
    draw_circle(190, 860, 20);
    draw_circle(160, 850, 20);
    glEnd();
    glutPostRedisplay();
    glPopMatrix();

    //factory 1 chimney 2 gas
    glPushMatrix();
    if(run == 0)
        glTranslatef(0, c2posy, 0);
    else
    {
        if(c2posy == 250)
            c2posy = 0;

        glTranslatef(0, c2posy = c2posy + .5, 0);
    }
    glBegin(GL_LINE_STRIP);
    draw_circle(350, 950, 20);
    draw_circle(370, 960, 20);
    draw_circle(370, 930, 20);
    glEnd();
    glutPostRedisplay();
    glPopMatrix();

    //factory 2 chimney 1 gas
    glPushMatrix();
    if(run == 0)
        glTranslatef(0, c3posy, 0);
    else
    {
        if(c3posy == 100)
            c3posy = 0;

        glTranslatef(0, c3posy = c3posy + .5, 0);
    }
    glBegin(GL_LINE_STRIP);
    draw_circle(600, 930, 20);
    draw_circle(620, 920, 20);
    draw_circle(620, 950, 20);
    glEnd();
    glutPostRedisplay();
    glPopMatrix();
}

void boat(int key)
{
    glPushMatrix();
    if(key == 0)
        glTranslatef(bposx, 0.0, 0.0);
    else
    {
        if(bposx == 900)
            bposx = -480;

        glTranslatef(bposx = bposx + .5, 0, 0.0);
    }
    //boat body
    glColor3ub(137, 40, 233);
    glBegin(GL_POLYGON);
    glVertex2i(200, 150);
    glVertex2i(300, 150);
    glVertex2i(320, 120);
    glVertex2i(180, 120);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(160, 180);
    glVertex2i(200, 150);
    glVertex2i(180, 120);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(300, 150);
    glVertex2i(340, 180);
    glVertex2i(320, 120);
    glEnd();

    //boat top left
    glColor3ub(40, 75, 233);
    glBegin(GL_POLYGON);
    glVertex2i(200, 150);
    glVertex2i(220, 180);
    glVertex2i(240, 150);
    glEnd();

    //boat top right
    glColor3ub(162, 173, 73);
    glBegin(GL_POLYGON);
    glVertex2i(220, 180);
    glVertex2i(280, 180);
    glVertex2i(300, 150);
    glVertex2i(240, 150);
    glEnd();
    glPopMatrix();
}

void car(int key)
{
    glPushMatrix();
    if(key == 0)
        glTranslatef(bposx, 0.0, 0.0);
    else
    {
        if(bposx == 900)
            bposx = -480;

        glTranslatef(bposx = bposx + .5, 0, 0.0);
    }
 glColor3f(256, 256, 256); //border color
    glBegin(GL_POLYGON);
    glVertex2i(400, 450);
    glVertex2i(400, 550);
    glVertex2i(300, 550);
    glVertex2i(300, 450);
    glEnd();
 glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    draw_circle(380, 440, 15);
    glEnd();
    glBegin(GL_LINE_STRIP);
    draw_circle(310, 440, 15);
    glEnd();

    glPopMatrix();
}
//------car 02-----


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    factory_pipe();
    river_border();
    car(run);
    tree();
    factory_glass();
    factory();
    factory_chimney();
    sun_moon(day_night_check);
    boat(run);

    water_pollution(run);
    pipe_pollution1();
    pipe_pollution2();
    chimney_gas();
    water(day_night_check);
    sky(day_night_check);
    soil(day_night_check);

    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'b':
        day_night_check = 1;
        glutPostRedisplay();
        break;
    case 'n':
        day_night_check = 0;
        glutPostRedisplay();
        break;
    case 's':
        run = 1;
        glutPostRedisplay();
        break;
    case 'd':
        run = 0;
        glutPostRedisplay();
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void ninit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
    glPointSize(4.0);
    glLineWidth(2.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1350, 700);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 900) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - 700) / 2);
    glutCreateWindow("Water Pollution");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    ninit();
    PlaySound(TEXT("sound.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutMainLoop();
    return 0;
}
