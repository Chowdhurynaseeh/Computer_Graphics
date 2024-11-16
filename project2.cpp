



#include<bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
using namespace std;
#define GLUT_BITMAP_HELVETICA_20	((void*)12)
vector<pair<int,int> > grid; // pair of cordinates of nodes stored in grid
vector<int> Graph[100]; // graph stored in Graph
vector<pair<int,int> > Edges; // pair of nodes of edges stored in Edges
vector<int> cost[100];   // cost of edges stored in cost
vector<pair<float,float> > curvepoints[200]; // store every points of  curves in curvePoints to redraw during simulation
vector<pair<int, int> > midPoint[200];
map<pair<int, int>, int> EdgeIndex; //map the indexes of edges
map<pair<int,int>, int> edgeCost; // map cost of edges
map<pair<int,int> ,int> nodeRegion; // map nodes with it's quadrant Region
int graphMatrix[100][100];
int next_node[100][100];
int flag[200];
vector<int>path;
//graph variable
int node,edge,m,g,gu,ndst = 700,cellunit = 35,startNode,endNode,ind2=1,ind3=-1,nn1,nn2;
float kk1,kk2,kk3,kk4;
// table Cordinates
int nr, xst, xed, yst, yed, xst1,xed1, yst1, yed1,gk = 800, gp = 100;
float cl1 = 0.0,cl2 = 1.0,cl3 = 0.0;
string ToString(int n) { string s; stringstream convert; convert << n; s = convert.str(); return s; }

//-----------------------------------------------------------------------------------------------------------------

void init()
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(i == j)
            {
                graphMatrix[i][j] = 0;
            }
            else
            {
                graphMatrix[i][j] = 10000;
            }
        }
    }
}


//-----------------------------------------------------------------------------------------------------------------
void colorCell(int p, int q)
{
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2i(p,q);
    glVertex2i(p,q-cellunit);
    glVertex2i(p+cellunit,q-cellunit);
    glVertex2i(p+cellunit,q);
    glEnd();
    glFlush();

}

//-----------------------------------------------------------------------------------------------------------------
void PrintText(int x, int y, int n, int f)
{
    if(f == 1)
    {
        glColor3f(.3, 1.0, .6);
    }
    else if(f == 2)
    {
        glColor3f(1.0, 0.0, 1.0);
        cout << "cost: " << x << " " << y << " " << n << endl;
    }
    else if(f == 3)
    {
        glColor3f(0.0, 0.0, 1.0);
        cout << "cost: " << x << " " << y << " " << n << endl;
    }
    else
    {
        glColor3f(0.0, 0.0, 1.0);
    }

    //cout << "flag color: " << f << endl;

    string S;
    int I, len;

	if(n != -1)
    {
        S = ToString(n);
    }

    string temp = ToString(n);
    len = S.length(); 			// See how many characters are in text string.

    glRasterPos2f( x, y);

    if(f == 0 || f == 1)
    {
        for(I = 0; I < len; I++) 			// Loop until i is greater then l
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, S[I]);
        }
    }
    else
    {
        for(I = 0; I < len; I++) 			// Loop until i is greater then l
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, S[I]);
        }
    }

}

//-----------------------------------------------------------------------------------------------------------------------------

void printString(int x, int y, string str, int f)
{
    int len = str.length(); 			// See how many characters are in text string.


    if(f == 0)
    {
        glColor3f(0.0, 0.0, 1.0);
    }
    else
    {
        glColor3f(cl1,cl2,cl3);
    }

    glRasterPos2f( x, y);   // Location to start printing text

    if(f == 0)
    {
        for(int i = 0; i < len; i++) 			// Loop until i is greater then l
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
        }
    }
    else
    {
        for(int i = 0; i < len; i++) 			// Loop until i is greater then l
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
        }
    }

}

//-----------------------------------------------------------------------------------------------------------------------------

void printStringHeading(int x, int y, string str)
{
    int len = str.length(); 			// See how many characters are in text string.


    glColor3f(0.0, 0.0, 1.0);

    glRasterPos2f( x, y); 		// Location to start printing text
    for(int i = 0; i < len; i++) 			// Loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
    }
}

//-----------------------------------------------------------------------------------------------------------------

void test()
{
    glColor3f(cl1,cl2,cl3);
    string str = "Hello";
    int len  = str.size();
    glRasterPos2f( gk, gp);   // Location to start printing text
    for(int i = 0; i < len; i++) 			// Loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
    }
}

//------------------------------------------------------------------------------------------------------------------------------

pair<float, float> midlePointSet(pair<int, int> pr)
{
    float tp1,tp2;
    float p, q, r, s, t, u, v, w, x, y, tx1, ty1, tx2, ty2, t1, t2;

    int ni = EdgeIndex[make_pair(pr.first, pr.second)];
    p = grid[pr.first-1].first;
    q = grid[pr.first-1].second;

    r = grid[pr.second-1].first;
    s = grid[pr.second-1].second;

    v = nodeRegion[make_pair(p,q)];
    w = nodeRegion[make_pair(r,s)];

    if(p == r)
    {
        u = (q+s)/2;
        if(flag[ni] == 0)
        {
            t = p - 100;
            flag[ni] = 1;
            flag[EdgeIndex[make_pair(pr.second,pr.first)]]=1;
        }
        else
        {
            t = p + 100;
        }
    }
    else if(q == s)
    {
        t = (p+q)/2;
        if(flag[ni] == 0)
        {
            u = q + 100;

            flag[ni] = 1;
            flag[EdgeIndex[make_pair(pr.second,pr.first)]]=1;
        }
        else
        {
            u = q - 100;
        }
    }
    else
    {
        if(v == 1 && w == 1 && flag[ni] == 0)
        {
            t = max(p,r);
            u = max(q,s);
            flag[ni] = 1;
            flag[EdgeIndex[make_pair(pr.second,pr.first)]]=1;
            //cout<<v<<" paici na "<<w<<endl;
        }
        else if(v == 1 && w == 1 && flag[ni])
        {
            t = min(p,r);
            u = min(q,s);
            //cout<<v<<" paici na "<<w<<endl;

        }
        else if(v == 3 && w == 3 && flag[ni] == 0)
        {
            t = max(p,r);
            u = max(q,s);
            flag[ni] = 1;
            flag[EdgeIndex[make_pair(pr.second,pr.first)]]=1;
            //cout<<v<<" paici na "<<w<<endl;
        }

        else if(v == 3 && w == 3 && flag[ni])
        {
            t = min(p,r);
            u = min(q,s);
            //cout<<v<<" paici na "<<w<<endl;
        }

        else if(v == 2 && w == 2 && flag[ni] == 0)
        {
            t = min(p,r);
            u = max(q,s);
            flag[ni] = 1;
            flag[EdgeIndex[make_pair(pr.second,pr.first)]]=1;
            //cout<<v<<" paici na "<<w<<endl;
        }

        else if(v == 2 && w == 2 && flag[ni])
        {
            t = max(p,r);
            u = min(q,s);
            //cout<<v<<" paici na "<<w<<endl;
        }

        else if (v == 4 && w == 4 && flag[ni] == 0)
        {
            t = min(p,r);
            u = max(q,s);
            flag[ni] = 1;
            flag[EdgeIndex[make_pair(pr.second,pr.first)]]=1;
            //cout<<v<<" paici "<<w<<" "<<ni<<" "<<flag[ni]<<endl;
        }

        else if (v == 4 && w == 4 && flag[ni])
        {
            t = max(p,r);
            u = min(q,s);
            //cout<<v<<" paici na "<<w<<" "<<ni<<" "<<flag[ni]<<endl;
        }

        else if((v == 3 && w == 2) || (v == 4 && w == 2) || (v == 4 && w == 3))
        {
            t = max(p,r);
            u = max(q,s);
            //cout<<v<<" paici na "<<w<<endl;
        }

        else if((v == 2 && w == 3) || (v == 2 && w == 4) || (v == 3 && w == 4))
        {
            //cout<<v<<" paici "<<w<<endl;
            t = min(p,r);
            u = min(q,s);
        }

        else if((v == 1 && w == 2) || (v == 1 && w == 3) || (v == 1 && w == 4))
        {
            t = min(p,r);
            u = max(q,s);
            //cout<<v<<" paici na "<<w<<endl;
        }

        else if((v == 2 && w == 1) || (v == 3 && w == 1) || (v == 4 && w == 1))
        {
            t = max(p,r);
            u = min(q,s);
            //cout<<v<<" paici na "<<w<<endl;
        }
    }

    midPoint[ni].push_back(make_pair(t,u));
    return make_pair(t,u);
}

//----------------------------------------------------------------------------------------------------------------
void find_path(int n,int m)
{
    int p = n;
    path.push_back(n);
    while(n!=m)
    {
        n=next_node[n][m];
        path.push_back(n);
        cout<<n<<" ";
    }
    //cout<<"node number print"<<endl;
}



void floyed_hoirshal()
{
    nr = node+1;
    xst = ndst+50;
    xed = xst+(nr*cellunit);
    yst=1100;
    yed = yst - (nr*cellunit);

    for(int i=1;i<=node;i++)
    {

        for(int j=1;j<=node;j++)
        {
            next_node[i][j]=j;
        }
    }
    for (int k = 1; k <= node; k++)
    {
        for(int i = 1; i <= node; i++)
        {
            for(int j = 1; j <= node; j++)
            {
                if(graphMatrix[i][j] > graphMatrix[i][k] + graphMatrix[k][j])
               {
                   graphMatrix[i][j] = graphMatrix[i][k] + graphMatrix[k][j];
                   //PrintText(xst+(j*cellunit)+1,yst-(i*cellunit)-25,graphMatrix[i][j],1);
                   colorCell(xst+(j*cellunit),yst-(i*cellunit));
                   next_node[i][j]=next_node[i][k];
               }
            }
        }
    }
}


//------------------------------------------------------------------------------------------------------------------------------

void Grid()
{
    //cin >> node;

    g = (node-2)/2+2;
    if(g%2 == 0) g++;
    else if(g*2 - 2 < node) g += 2;

    m = g/2+1;
    gu = ndst/g;
    int  p,q;
    for(int i = 0; i < m; i++){
        p = (m-i)*gu;
        q = (g-i)*gu;
        grid.push_back(make_pair(p,q));
        if(p >= m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 1;
        else if(p < m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 2;
        else if(p < m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 3;
        else if(p >= m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 4;
    }

    for(int i = m-2; i >= 0; i--){
        p = (m-i)*gu;
        q = (i+1)*gu;
        //cout << i << " if" << endl;
        grid.push_back(make_pair(p,q));
        if(p >= m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 1;
        else if(p < m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 2;
        else if(p < m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 3;
        else if(p >= m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 4;
    }

    for(int i = m+1; i <= g; i++){
        p = i*gu;
        q = (i-m+1)*gu;
        //cout << i << "  is" << endl;
        grid.push_back(make_pair(p,q));
        if(p >= m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 1;
        else if(p < m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 2;
        else if(p < m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 3;
        else if(p >= m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 4;
    }

    for(int i = 1; i < m; i++){
        p = (g-i)*gu;
        q = (m+i)*gu;
        //cout << i << " if" << endl;
        grid.push_back(make_pair(p,q));
        if(p >= m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 1;
        else if(p < m*gu && q >= m*gu) nodeRegion[make_pair(p,q)] = 2;
        else if(p < m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 3;
        else if(p >= m*gu && q < m*gu) nodeRegion[make_pair(p,q)] = 4;
    }
}


//------------------------------------------------------------------------------------------------------------------------------


void Graph_Input()
{
    cout << "Enter Number of node you want to input: ";
    cin >> node;
    cout << "Enter Number of edge you want to input: ";
    cin >> edge;
    cout << "Graph Input with cost: " << endl;

    Grid(); ///////// Create Grid according to Number of Node

    for(int i = 0; i < edge; i++)
    {
        int x,y,c;
        cin >> x >> y >> c;

        graphMatrix[x][y] = c;
        //store graph in matric with cost

        Graph[x].push_back(y);
        //Graph[y].push_back(x);

        cost[x].push_back(c);
        //cost[y].push_back(c);

        Edges.push_back(make_pair(x,y));

        EdgeIndex[make_pair(x,y)] = i+1;
        //EdgeIndex[make_pair(y,x)] = i+1;

        edgeCost[make_pair(x,y)] = c;
        //edgeCost[make_pair(y,x)] = c;

    }

    cout << "Start Node: ";
    cin >> startNode;
    cout << "End Node: ";
    cin >> endNode;
}


////----------------------------------------------------------------------------------------------------

void drawLine(pair<int,int> p1, pair<int,int> p2, pair<float, float> mp, int edi,int n1,int n2,int f)
{
    //Baizer curve algorithm
    if(f==2)
    {
        glColor3f(0,1,0);
    }
    else
    {
        glColor3f(0,0,1);
    }
    float tp1,tp2;
    float p = p1.first,q = p1.second,r = p2.first,s = p2.second,t,u,x,y,tx1,ty1,tx2,ty2,t1,t2;

    tx1 = max(p,r);
    ty1 = max(q,s);

    tx2 = min(p,r);
    ty2 = min(q,s);

    t = mp.first;
    u = mp.second;

    if(p == r)
    {
        //cout << p << " " << r << endl;
        tx1 = p;
        tx2 = t;
    }

    if(p == r)
    {


        if(flag[edi] != 2)
        {
            tx1 = p;
            tx2 = t;
            flag[edi] = 2;
            flag[EdgeIndex[make_pair(n2,n1)]]=2;
        }
        else
        {
            tx1 = t;
            tx2 = p;
        }
    }
    else if(q == s)
    {
        if(flag[edi] != 2)
        {
            ty1 = u;
            ty2 = q;
            flag[edi] = 2;
            flag[EdgeIndex[make_pair(n2,n1)]]=2;
        }
        else
        {
            ty1 = q;
            ty2 = u;
        }
    }

    //cout << "curbe: " <<" "<<n1<<" "<<n2<<" "<< p << " " << q << " " << r << " " << s << " " << t << " " << u << " " << tx1 << " " << tx2 << " " << ty1 << " " << ty2 << endl;
    int c1,c2;
    glPushMatrix(); //Save the current state of transformations

    glLineWidth(3);
    glBegin(GL_LINES);
    t1=p,t2=q;
    for(float i = .001; i < 10; i+=.005)
    {
        x = (1.0-i)*(1.0-i)*p + 2.0*(1.0-i)*i*t+(i*i)*r;
        y = (1.0-i)*(1.0-i)*q + 2.0*(1.0-i)*i*u+(i*i)*s;
        if(y>=ty2 && y <= ty1 && x >=  tx2 && x <= tx1)
        {
            glVertex3f(t1,t2,0);
            glVertex3f(x,y,0);

            t1 = x;
            t2 = y;
            curvepoints[edi].push_back(make_pair(x,y));
        }

    }
    glEnd();
    int pk = curvepoints[edi].size()/2;
    c1 = curvepoints[edi][pk].first;
    c2 = curvepoints[edi][pk].second;
    PrintText(c1,c2,edgeCost[make_pair(n1,n2)],2);
    glPopMatrix();

    glFlush();
}

//---------------------------------------------------------------------------------------------------------------------------

void animationinit(pair<int, int> p1)
{
    nn1=path[0];
    nn2=path[1];
    ind2=EdgeIndex[make_pair(nn1,nn2)];
    kk1=curvepoints[ind2][0].first;
    kk2=curvepoints[ind2][0].second;
    kk3=curvepoints[ind2][1].first;
    kk4=curvepoints[ind2][1].second;
}

//---------------------------------------------------------------------------------------------------------------------------------

void drawLineAnimation()
{
    int p1,p2,c1,c2,k1,k2;
    memset(flag,0,sizeof(flag));

    glLineWidth(3);
    glColor3f(0,0,1);
    //cout<<kk1<<" "<<kk2<<" "<<kk3<<" "<<kk4<<endl;
    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(kk1,kk2,0);
    glVertex3f(kk3,kk4,0);
    glEnd();
    glFlush();

}

//----------------------------------------------------------------------------------------------------------------------

void update(int value)
{
    if(ind3<path.size())
    {
        int p1=path[ind3];
        int p2=path[ind3+1];
        int ind =EdgeIndex[make_pair(p1,p2)];
        for(int j=1;j<curvepoints[ind].size();j++)
        {
            kk1=kk3;
            kk2=kk4;
            kk3=curvepoints[ind][j].first;
            kk4=curvepoints[ind][j].second;

            drawLineAnimation();
        }
        //ind3++;
        //glutTimerFunc(2035,update,0);
    }
}

//------------------------------------------------------------------------------------------------------------------------------

void TableCreationUpdateValue()
{
    nr = node+1;
    xst = ndst+50;
    xed = xst+(nr*cellunit);
    yst=1100;
    yed = yst - (nr*cellunit);
    glPushMatrix(); //Save the current state of transformations
    glColor3f(1,0,0);
    glLineWidth(1);

    printStringHeading(xst+50, yst+25, "Updated Matrix");
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    for(int  i = 0; i <= nr; i++)
    {
        glVertex2i(xst,yst-(i*cellunit));
        glVertex2i(xed,yst-(i*cellunit));
    }

    for(int  i = 0; i <= nr; i++)
    {
        glVertex2i(xst+(i*cellunit),yst);
        glVertex2i(xst+(i*cellunit),yed);
    }
    glEnd();

    printString(xst+2,yst-25,"Node", 0);

    for(int j = 1; j < nr; j++)
    {
        PrintText(xst+(j*cellunit)+5,yst-25,j,0);
    }

    for(int j = 1; j < nr; j++)
    {
        PrintText(xst+5,yst-(j*cellunit)-25,j,0);
    }

    // Updated value output

    for(int i = 1; i < nr; i++)
    {
        for(int j = 1; j < nr; j++)
        {
            PrintText(xst+(j*cellunit)+1,yst-(i*cellunit)-25,graphMatrix[i][j],0);
        }
    }

    glPopMatrix();
    glFlush();
}

//------------------------------------------------------------------------------------------------------------------------------

void TableCreation()
{
    nr = node+1;
    xst = 100;
    xed = xst+(nr*cellunit);
    yst=1100;
    yed = yst - (nr*cellunit);
    glPushMatrix(); //Save the current state of transformations
    glLineWidth(1);

    printStringHeading(xst+50, yst+25, "Initial Matrix");
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    for(int  i = 0; i <= nr; i++)
    {
        glVertex2i(xst,yst-(i*cellunit));
        glVertex2i(xed,yst-(i*cellunit));
    }

    for(int  i = 0; i <= nr; i++)
    {
        glVertex2i(xst+(i*cellunit),yst);
        glVertex2i(xst+(i*cellunit),yed);
    }
    glEnd();

    printString(xst+2,yst-25,"Node", 0);

    for(int j = 1; j < nr; j++)
    {
        PrintText(xst+(j*cellunit)+5,yst-25,j,0);
    }

    for(int j = 1; j < nr; j++)
    {
        PrintText(xst+5,yst-(j*cellunit)-25,j,0);
    }

    // Initial data output

    for(int i = 1; i < nr; i++)
    {
        for(int j = 1; j < nr; j++)
        {
            PrintText(xst+(j*cellunit)+1,yst-(i*cellunit)-25,graphMatrix[i][j],0);
        }
    }

    floyed_hoirshal();
    TableCreationUpdateValue();
    find_path(startNode,endNode);
    animationinit(make_pair(path[0],path[1]));
    drawLineAnimation();

    glPopMatrix();
    glFlush();

    cout << "ber hoe gesi" << endl;
}

//-------------------------------------------------------------------------------------------------------------------

void NodeConnector()
{
    int l = grid.size(),p,q,x,y,tmp;
    tmp = l-node;
    l = l-tmp;

    pair<int,int> pr;
    int b = 1;
    for(int j = 0; j < Edges.size(); j++)
    {
        pr = Edges[j];
        //cout << pr.first << " node number " << pr.second << endl;
        pair<float, float> mp;
        mp = midlePointSet(pr);

        p = grid[pr.first-1].first;
        q = grid[pr.first-1].second;

        x = grid[pr.second-1].first;
        y = grid[pr.second-1].second;

        drawLine(make_pair(p,q), make_pair(x,y), mp, j+1,pr.first,pr.second,2);

    }
    glFlush ();

}

//---------------------------------------------------------------------------------------------------------

void DrawNodes()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub(0,255,0);
    glPointSize(1.0);
    glLineWidth(10);

    int l = grid.size(),p,q,tmp;
    cout << l << endl;
    tmp = l-node;
    l = l-tmp;

    for(int j = 0; j < l; j++){
        p = grid[j].first;
        q = grid[j].second;

        //cout << p << " " << q << endl;

        glPushMatrix(); //Save the current state of transformations
        glTranslatef(p, q, 0.0); //Move to the center of the triangle
        //glRotatef(0.0, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        for(int i=0;i<100;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/100;
            float r=30;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix(); //Undo the move to the center of the triangle
        PrintText(p,q,j+1,3);
    }
    printString(400,1150, "Floyd Warshall Algorithm Simulation", 2);

    glFlush ();
}

//-----------------------------------------------------------------------------------------------------------------

void keyboard(unsigned char key, int x, int y)
{
    if(key == 'u')
    {
        cout<<"paici"<<endl;
        cl2 = 0.0;
        cl3 = 1.0;
        glutPostRedisplay();
        //TableCreationUpdateValue();
        //glutPostRedisplay();
    }
}


void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
            {
                //cl2 = 0.0;
                //cl3 = 1.0;
                //test();
                //glutPostRedisplay();
                ind3++;
                update(ind3);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)

            break;
        default:
        break;
    }
}

//-----------------------------------------------------------------------------------------------------------------

void myDisplay(void)
{
    //Graph_Input();
    //printString(500,1100, "Floyd Warshall Algorithm Simulation", 1);
    //glFlush();
    //test();
    DrawNodes();
    //test();
    NodeConnector();
    TableCreation();
    test();
    glFlush();

    //glutSwapBuffers();
    //glutSpecialFunc(keyboard);
}

//-----------------------------------------------------------------------------------------------------------------

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3ub(0,255,0);
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 1200.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 1200);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("my first attempt");
    init();
    Graph_Input();

    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    myInit();
    glutFullScreen();
    //glutTimerFunc(2035,update,0);
    glutMainLoop();
    //Graph_Input();

    return EXIT_SUCCESS;
}



/*
8
20
1 2 3
2 1 3
2 3 3
3 2 3
3 4 3
4 3 3
4 5 3
5 4 3
5 6 3
6 5 3
6 7 3
7 6 3
7 8 3
8 7 3
8 1 3
1 8 3
2 8 6
2 6 8
1 5 7
5 1 7
2
8




5
10
1 2 5
2 3 6
3 4 2
4 5 8
5 1 10
1 4 3
4 2 2
5 4 1
2 1 4
3 2 7
5
1






8
20
1 2 3
2 1 3
2 3 3
3 2 3
3 4 3
4 3 3
4 5 3
5 4 3
5 6 3
6 5 3
6 7 3
7 6 3
7 8 3
8 7 3
8 1 3
1 8 3
2 8 6
2 6 8
1 5 7
5 1 7
1
7



8
20
1 2 1
2 1 1
2 3 1
3 2 1
3 4 1
4 3 1
4 5 1
5 4 1
5 6 1
6 5 1
6 7 1
7 6 1
7 8 1
8 7 1
8 1 1
1 8 100
2 8 100
2 6 20
1 5 30
5 1 15
1
8


*/
