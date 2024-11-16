#include <string>
using namespace std;

static void Credits()
{
    /// -------------------------- Function For Display Game Makers Name ----------------------

    string text;
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor(1.000, 0.855, 0.725, 0.0);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(4.0);
	glColor3b(0, 0, 0);

    text = "Design & Programming: ";
    DrawText(text.data(), text.size(),30, 540);
    glBegin(GL_POLYGON);
    glVertex2i(30, 535);
    glVertex2i(30, 532);
    glVertex2i(270, 532);
    glVertex2i(270, 535);
    glEnd();

    text = "1. Kamal, Md. Nashid";
    DrawText(text.data(), text.size(), 30, 500);
    text = "Student ID: 15-29224-1";
    DrawName(text.data(), text.size(), 30, 470);
    text = "B.Sc. in Computer Science & Engineering";
    DrawName(text.data(), text.size(), 30, 440);
    text = "American International University-Bangladesh";
    DrawName(text.data(), text.size(), 30, 410);

    text = "2. Shuvo, Mehedi Hasan";
    DrawText(text.data(), text.size(), 420, 500);
    text = "Student ID: 15-29216-1";
    DrawName(text.data(), text.size(), 420, 470);
    text = "B.Sc. in Computer Science & Engineering";
    DrawName(text.data(), text.size(), 420, 440);
    text = "American International University-Bangladesh";
    DrawName(text.data(), text.size(), 420, 410);

    text = "3. Haque, Md. Ehsanul";
    DrawText(text.data(), text.size(), 30, 300);
    text = "Student ID: 15-28705-1";
    DrawName(text.data(), text.size(), 30, 270);
    text = "B.Sc. in Computer Science & Software Engineering";
    DrawName(text.data(), text.size(), 30, 240);
    text = "American International University-Bangladesh";
    DrawName(text.data(), text.size(), 30, 210);

    text = "4. Mazumder, Robi Ratno";
    DrawText(text.data(), text.size(), 420, 300);
    text = "Student ID: 14-26567-2";
    DrawName(text.data(), text.size(), 420, 270);
    text = "B.Sc. in Computer Science & Software Engineering";
    DrawName(text.data(), text.size(), 420, 240);
    text = "American International University-Bangladesh";
    DrawName(text.data(), text.size(), 420, 210);

    glColor3ub(205, 92, 92);
    glRecti(250, 40, 550, 95);
    glColor3b(0, 0, 0);
    text = "Press B For Main Menu";
    DrawText(text.data(), text.size(), 280, 60);

    glFlush();
    glutSwapBuffers();
}

static void Help()
{
    /// -------------------------------- Function For Displaying Help Menu ------------------------------

    string text;
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor(1.000, 0.855, 0.725, 0.0);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(4.0);
	glColor3b(0, 0, 0);

    text = "Instructions: ";
    DrawText(text.data(), text.size(), 70, 540);
    glBegin(GL_POLYGON);
    glVertex2i(70, 538);
    glVertex2i(70, 535);
    glVertex2i(200, 535);
    glVertex2i(200, 538);
    glEnd();

    text = "Keyboard Controls: ";
    DrawText(text.data(), text.size(), 100, 510);
    glBegin(GL_POLYGON);
    glVertex2i(100, 508);
    glVertex2i(100, 505);
    glVertex2i(290, 505);
    glVertex2i(290, 508);
    glEnd();

    text = "P -> Play Game";
    DrawName(text.data(), text.size(), 150, 480);
    text = "H or F1 -> Help";
    DrawName(text.data(), text.size(), 150, 450);
    text = "C -> Credits";
    DrawName(text.data(), text.size(), 150, 420);
    text = "B -> Back to Main Menu";
    DrawName(text.data(), text.size(), 150, 390);
    text = "Q or Esc -> Exit";
    DrawName(text.data(), text.size(), 150, 360);

    text = "Mouse Controls: ";
    DrawText(text.data(), text.size(), 100, 330);
    glBegin(GL_POLYGON);
    glVertex2i(100, 325);
    glVertex2i(100, 322);
    glVertex2i(267, 322);
    glVertex2i(267, 325);
    glEnd();

    text = "Left Click -> Select Play or Exit or Steal Candy";
    DrawName(text.data(), text.size(), 150, 300);

    glColor3ub(205, 92, 92);
    glRecti(250, 40, 550, 95);
    glColor3b(0, 0, 0);
    text = "Press B For Main Menu";
    DrawText(text.data(), text.size(), 280, 60);

    glFlush();
    glutSwapBuffers();
}
