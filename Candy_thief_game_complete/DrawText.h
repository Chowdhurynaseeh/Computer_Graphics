void DrawText(const char *text, int length, int x, int y)
{
    /// ------------------ Text Display Function, Font: Times Roman, Size: 24 --------------------

    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[100];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    gluOrtho2D(0.0, 1366.0, 0.0, 768.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);

    for(int i=0; i<length; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}

void DrawName(const char *text, int length, int x, int y)
{
    /// ------------------ Text Display Function, Font: Bitmap, Size: 8/13 --------------------

    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[100];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    gluOrtho2D(0.0, 1366.0, 0.0, 768.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);

    for(int i=0; i<length; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int)text[i]);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}
