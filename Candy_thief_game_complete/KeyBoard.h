void keyboard(unsigned char key, int x, int y)
{
    /// ---------------------------------- Main Keyboard Function For Normal Keyboard Inputs -------------------------

    if(s==1)
    {
        switch (key)
        {
            case 'Q':
            case 'q':
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
