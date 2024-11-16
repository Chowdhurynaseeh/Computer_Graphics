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
