void BackgroundCharacter(int x, int y)
{
    /// -------------------------- Function For Displaying Background Characters --------------------------
    ///-------------------- Character Top Val, @X = 0 - 80 + X, @Y = Depends on Parameter --------------
    glPushMatrix();
    glRotated(7,0,0,100);
    glColor3f(0,0,0); glRecti(5+x, 30+y, 70+x, 35+y);glRecti(5+x, 35+y, 10+x, 45+y);
    glColor3f(0,0,1);glRecti(10+x, 35+y, 40+x, 45+y);
    glColor3f(0,0,0);glRecti(40+x, 35+y, 45+x, 45+y);
    glColor3f(0,0,1);glRecti(45+x, 35+y, 65+x, 45+y);
    glColor3f(0,0,0);glRecti(65+x, 35+y, 70+x, 45+y);glRecti(5+x, 45+y, 10+x, 50+y);
    glColor3f(0,0,1);glRecti(10+x, 45+y, 40+x, 50+y);
    glColor3f(0,0,0);glRecti(40+x, 45+y, 45+x, 50+y);
    glColor3f(0,0,1);glRecti(45+x, 45+y, 65+x, 50+y);
    glColor3f(0,0,0);glRecti(65+x, 45+y, 70+x, 50+y);
    glColor3f(0,0,0); glRecti(5+x, 50+y, 70+x, 55+y);glRecti(5+x, 55+y, 10+x, 60+y);
    glColor3f(1,0,0); glRecti(10+x, 55+y, 65+x, 60+y);
    glColor3f(0,0,0); glRecti(65+x, 55+y, 60+x, 60+y);glRecti(5+x, 60+y, 10+x, 65+y);
    glColor3f(1,0,0); glRecti(10+x, 60+y, 55+x, 65+y);
    glColor3f(0,0,0); glRecti(55+x, 60+y, 60+x, 65+y);glRecti(10+x, 65+y, 20+x, 70+y);
    glColor3f(1,0,0); glRecti(20+x, 65+y, 45+x, 70+y);
    glColor3f(0,0,0); glRecti(45+x, 65+y, 70+x, 70+y);
    glColor3f(0,0,0);glRecti(10+x, 70+y, 15+x, 75+y);glRecti(20+x, 70+y, 25+x, 75+y);glRecti(40+x, 70+y, 45+x, 75+y);glRecti(65+x, 70+y, 70+x, 75+y);
    glColor3f(1,0,0); glRecti(15+x, 70+y, 20+x, 75+y);glRecti(25+x, 70+y, 40+x, 75+y);
    glColor3f(1,1,1); glRecti(45+x, 70+y, 65+x, 75+y);
    glColor3f(0,0,0);glRecti(10+x, 80+y, 15+x, 75+y);glRecti(25+x, 80+y, 30+x, 75+y);glRecti(35+x, 80+y, 40+x, 75+y);glRecti(55+x, 80+y, 60+x, 75+y);glRecti(70+x, 80+y, 75+x, 75+y);
    glColor3f(1,0,0); glRecti(15+x, 80+y, 25+x, 75+y);glRecti(30+x, 80+y, 35+x, 75+y);
    glColor3f(1,1,1); glRecti(40+x, 80+y, 55+x, 75+y);glRecti(60+x, 80+y, 70+x, 75+y);
    glColor3f(0,0,0);glRecti(10+x, 80+y, 15+x, 85+y);glRecti(35+x, 80+y, 40+x, 85+y);glRecti(70+x, 80+y, 75+x, 85+y);
    glColor3f(1,0,0);glRecti(15+x, 80+y, 35+x, 85+y);
    glColor3f(1,1,1);glRecti(40+x, 80+y, 70+x, 85+y);
    glColor3f(0,0,0);glRecti(10+x, 90+y, 15+x, 85+y);glRecti(30+x, 85+y, 35+x, 90+y);glRecti(75+x, 85+y, 80+x, 90+y);
    glColor3f(1,0,0);glRecti(15+x, 85+y, 30+x, 90+y);
    glColor3f(1,1,1); glRecti(35+x, 85+y, 75+x, 90+y);
    glColor3f(0,0,0);glRecti(10+x, 90+y, 35+x, 95+y);glRecti(75+x, 90+y, 80+x, 95+y);
    glColor3f(1,1,1);glRecti(35+x, 90+y, 75+x, 95+y);
    glColor3f(0,0,0);glRecti(10+x, 95+y, 15+x, 100+y);glRecti(30+x, 95+y, 35+x, 100+y);glRecti(45+x, 95+y, 55+x, 100+y);glRecti(60+x, 95+y, 70+x, 100+y);glRecti(75+x, 95+y, 80+x, 100+y);
    glColor3f(1,1,0); glRecti(15+x, 95+y, 30+x, 100+y);
    glColor3f(1,1,1); glRecti(35+x, 95+y, 45+x, 100+y);glRecti(55+x, 95+y, 60+x, 100+y);glRecti(70+x, 95+y, 75+x, 100+y);
    glColor3f(0,0,0);glRecti(10+x, 105+y, 15+x, 100+y);glRecti(30+x, 105+y, 35+x, 100+y);glRecti(45+x, 105+y, 55+x, 100+y);glRecti(60+x, 105+y, 70+x, 100+y);glRecti(75+x, 105+y, 80+x, 100+y);
    glColor3f(1,1,0); glRecti(15+x, 105+y, 30+x, 100+y);
    glColor3f(1,1,1); glRecti(35+x, 105+y, 45+x, 100+y);glRecti(55+x, 105+y, 60+x, 100+y);glRecti(70+x, 105+y, 75+x, 100+y);
    glColor3f(0,0,0);glRecti(10+x, 105+y, 35+x, 110+y);glRecti(45+x, 105+y, 55+x, 110+y);glRecti(60+x, 105+y, 70+x, 110+y);glRecti(75+x, 105+y, 80+x, 110+y);
    glColor3f(1,1,1);glRecti(35+x, 105+y, 45+x, 110+y);glRecti(55+x, 105+y, 60+x, 110+y);glRecti(70+x, 105+y, 75+x, 110+y);
    glColor3f(0,0,0);glRecti(5+x, 115+y, 10+x, 110+y);glRecti(35+x, 115+y, 40+x, 110+y);glRecti(70+x, 115+y, 75+x, 110+y);
    glColor3f(1,0,0); glRecti(10+x, 115+y, 35+x, 110+y);
    glColor3f(1,1,1); glRecti(40+x, 115+y, 70+x, 110+y);
    glColor3f(0,0,0);glRecti(0+x, 115+y, 5+x, 120+y);glRecti(35+x, 115+y, 40+x, 120+y);glRecti(70+x, 115+y, 75+x, 120+y);
    glColor3f(1,0,0); glRecti(5+x, 115+y, 35+x, 120+y);
    glColor3f(1,1,1); glRecti(40+x, 115+y, 70+x, 120+y);
    glColor3f(0,0,0);glRecti(5+x, 125+y, 15+x, 120+y);glRecti(40+x, 125+y, 45+x, 120+y);glRecti(70+x, 125+y, 65+x, 120+y);
    glColor3f(1,0,0); glRecti(15+x, 125+y, 40+x, 120+y);
    glColor3f(1,1,1); glRecti(45+x, 125+y, 65+x, 120+y);
    glColor3f(0,0,0);glRecti(15+x, 125+y, 65+x, 130+y);
    glPopMatrix();
}

void BackgroundTower(int x, int y)
{
    /// ------------------------- Function For Displaying Background Towers ----------------------------
    ///------------------------ Tower, Val = @X = 0 - 70 + X, @Y = 0 - 120 + Y ---------------------------

    glColor3f(1,0,0);glRecti(0+x,0+y,70+x,5+y); glRecti(5+x,5+y,20+x,10+y);glRecti(30+x,5+y,40+x,10+y);glRecti(50+x,5+y,65+x,10+y);
    glColor3f(1,.714,.757);glRecti(20+x,5+y,30+x,10+y);glRecti(40+x,5+y,50+x,10+y);
    glColor3f(1,0,0);glRecti(10+x,15+y,20+x,10+y);glRecti(30+x,15+y,40+x,10+y);glRecti(50+x,15+y,60+x,10+y);
    glColor3f(.412,.412,.412);glRecti(20+x,15+y,30+x,10+y);glRecti(40+x,15+y,50+x,10+y);
    glColor3f(1,0,0);glRecti(15+x,15+y,20+x,20+y);glRecti(30+x,15+y,40+x,20+y);glRecti(50+x,15+y,55+x,20+y);
    glColor3f(.412,.412,.412);glRecti(20+x,15+y,30+x,20+y);glRecti(45+x,15+y,50+x,20+y);
    glColor3f(1,1,1); glRecti(25+x,15+y,30+x,20+y);glRecti(40+x,15+y,45+x,20+y);
    glColor3f(1,0,0);glRecti(15+x,20+y,55+x,45+y);
    glColor3f(.863,.863,.863);glRecti(10+x,45+y,60+x,50+y); glRecti(5+x,50+y,10+x,60+y);glRecti(60+x,50+y,65+x,60+y);glRecti(0+x,60+y,5+x,80+y);glRecti(65+x,60+y,70+x,80+y);glRecti(5+x,80+y,10+x,90+y);glRecti(65+x,80+y,60+x,90+y);
    glColor3f(1,0,0);glRecti(5+x,90+y,65+x,95+y);glRecti(10+x,95+y,60+x,100+y);glRecti(15+x,100+y,55+x,105+y);glRecti(20+x,105+y,50+x,110+y);glRecti(30+x,110+y,40+x,120+y);
    glColor3f(1,1,1);glRecti(5+x,65+y,10+x,80+y);glRecti(10+x,65+y,15+x,90+y);glRecti(25+x,65+y,30+x,70+y);glRecti(35+x,65+y,60+x,70+y);glRecti(60+x,70+y,65+x,80+y);glRecti(10+x,70+y,60+x,90+y);
    glColor3f(0,1,0);glRecti(20+x,50+y,30+x,55+y);glRecti(20+x,60+y,25+x,65+y);glRecti(30+x,60+y,35+x,65+y);glRecti(55+x,55+y,60+x,60+y);
    glColor3f(0.541, 0.169, 0.886);glRecti(10+x,50+y,15+x,60+y);glRecti(15+x,50+y,20+x,55+y);glRecti(20+x,55+y,25+x,60+y);glRecti(30+x,50+y,40+x,55+y);
    glColor3f(0,1,1);glRecti(15+x,55+y,20+x,60+y);glRecti(40+x,50+y,45+x,55+y);glRecti(50+x,50+y,60+x,55+y);glRecti(50+x,55+y,55+x,60+y);glRecti(25+x,55+y,40+x,60+y);
    glColor3f(1,0,1);glRecti(15+x,65+y,25+x,70+y);glRecti(30+x,65+y,35+x,70+y);glRecti(60+x,65+y,65+x,70+y);glRecti(5+x,60+y,20+x,65+y);glRecti(25+x,60+y,30+x,65+y);glRecti(35+x,60+y,65+x,65+y);glRecti(40+x,55+y,50+x,60+y);glRecti(45+x,50+y,50+x,55+y);
}
