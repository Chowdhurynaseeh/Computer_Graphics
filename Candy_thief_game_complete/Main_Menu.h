static void Start_Screen()
{
    /// -------------------------- Start Screen of Game --------------------------
    string text;
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.000, 0.855, 0.725, 0.0);
	glColor3f (0.0, 0.0, 0.0);
    GameLogo();

    ///---------------------------- Display Menu Blocks -----------------------------

    glColor3ub(205, 92, 92);
	glRecti(256, 257, 768, 322);
	glRecti(256, 192, 768, 242);
	glRecti(256, 127, 768, 177);
	glRecti(256, 62, 768, 112);

    ///--------------------------------- Menu Lists --------------------------------

    glColor3b(0, 0, 0);
    text = "Play"; glRectf(-0.75f,0.75f, 0.75f, -0.75f);
    DrawText(text.data(), text.size(), 480, 282);
    text = "Press H For Help";
    DrawText(text.data(), text.size(), 430, 209);
    text = "Press C For Credits";
    DrawText(text.data(), text.size(), 417, 150);
    text = "Exit";
    DrawText(text.data(), text.size(), 480, 81);
    glFlush();
    glutSwapBuffers();
}
