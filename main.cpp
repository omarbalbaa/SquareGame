#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

#include <stdlib.h>


int phyWidth= 700;
int phyHeight= 700;
int logWidth=100;
int logHeight=100;
int centerX=logWidth/2;
int centerY=logHeight/2;
int sqWid = 20;
int alphaX = 0;
int alphaY = 0;
int monsterX1=0, monsterX2=0, monsterY1=0, monsterY2=0;

bool squareExist [5] = {true , true , true , true , true};
int score = 0;

void specialKeyboard (int key , int x , int y){
    if (key == GLUT_KEY_UP)
        alphaY +=5;
    if (key == GLUT_KEY_DOWN)
        alphaY -=5;
    if (key == GLUT_KEY_LEFT)
        alphaX -=5;
    if ( key == GLUT_KEY_RIGHT)
        alphaX +=5;
    glutPostRedisplay();

}
void Keyboard(unsigned char key , int x , int y){

    if (key == 'w')
        alphaY +=5;
    if (key == 's')
        alphaY -=5;
    if (key == 'a')
        alphaX -=5;
    if (key == 'd')
        alphaX +=5;
    glutPostRedisplay();
}

void init2D (float r, float g, float b){
    glClearColor(r,g,b,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D( 0.0, logWidth, 0.0, logHeight);
}
void printText(char *str,int x,int y) {
    glRasterPos2d(x,y);
    for (int i=0;i<strlen(str);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
    glFlush();
}
void scoreisplay(int posx, int posy, int space_char, int scorevar){
        int j=0,p,k;
        p = scorevar;
        j = 0;
        k = 0;
        while(p > 9)
        {
            k = p % 10;
            glRasterPos2f((posx-(j*space_char)),posy);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+k);
            j++;
            p /= 10;
        }
            glRasterPos2f ((posx-(j*space_char)), posy);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+p);

}

void drawSquare (int x , int y){
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+5,y);
    glVertex2f(x+5,y+5);
    glVertex2f(x,y+5);
    glEnd();
}

int generate_food(int x, int y)
{
        x = (rand() % (logWidth + 1));
        y = (rand() % (logHeight+ 1));

    drawSquare(x,y);
    return x, y;
}
void eatSquare0(){
        if ((20>=monsterX1 && 20<=monsterX2)&&(20>=monsterY1 && 20<=monsterY2)){
            if (squareExist[0])
                score ++ ;
            squareExist[0]=false;
    }
    if (!squareExist[0]){
            glColor3f(0.1,0.2,0.8); //background color
            drawSquare(20,20);
    }
}
 void eatSquare1(){
     if ((89>=monsterX1 && 89<=monsterX2)&&(70>=monsterY1 && 70<=monsterY2)){
            if (squareExist[1])
                score ++ ;
            squareExist[1]=false;
    }
    if (!squareExist[1]){
            glColor3f(0.1,0.2,0.8); //background color
            drawSquare(89,70);
    }
 }
 eatSquare2(){
     if ((70>=monsterX1 && 70<=monsterX2)&&(10>=monsterY1 && 10<=monsterY2)){
            if (squareExist[2])
                score ++ ;
            squareExist[2]=false;
    }
    if (!squareExist[2]){
            glColor3f(0.1,0.2,0.8); //background color
            drawSquare(70,10);
    }
 }
 eatSquare3(){
     if ((40>=monsterX1 && 40<=monsterX2)&&(85>=monsterY1 && 85<=monsterY2)){
            if (squareExist[3])
                score ++ ;
            squareExist[3]=false;
    }
    if (!squareExist[3]){
            glColor3f(0.1,0.2,0.8); //background color
            drawSquare(40,85);
    }
 }
eatSquare4(){
     if ((86>=monsterX1 && 86<=monsterX2)&&(43>=monsterY1 && 43<=monsterY2)){
            if (squareExist[4])
                score ++ ;
            squareExist[4]=false;
    }
    if (!squareExist[4]){
            glColor3f(0.1,0.2,0.8); //background color
            drawSquare(86,43);
    }
 }

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //square 0
    glColor3f(1,0.5,0.5);
    drawSquare(20,20);
    eatSquare0();
    //square 1
    glColor3f(1,0.5,0.5);
    drawSquare(89,70);
    eatSquare1();
    //square 2
    glColor3f(1,0.5,0.5);
    drawSquare(70,10);
    eatSquare2();
    //square 3
    glColor3f(1,0.5,0.5);
    drawSquare(40,85);
    eatSquare3();
    //square 4
    glColor3f(1,0.5,0.5);
    drawSquare(86,43);
    eatSquare4();

    glColor3f(1,1,1);
    printText("Score : ",3,95);
    scoreisplay(15,95,2,score);

    monsterX1=centerX-sqWid/2+alphaX ; monsterY1=centerY-sqWid/2+alphaY;
    monsterX2=centerX+sqWid/2+alphaX ; monsterY2=centerY+sqWid/2+alphaY;


    glColor3f(1,1,1);

    glBegin(GL_POLYGON);
    glVertex2f(monsterX1 , monsterY1);
    glVertex2f(monsterX2 , monsterY1);
    glVertex2f(monsterX2 , monsterY2);
    glVertex2f(monsterX1 , monsterY2);
    glEnd();


    if (score >=5){
        glColor3f(0,1,0);
        printText("WINNER WINNER WINNER WINNER WINNER",15,50);
        glColor3f(1,0,0);
        printText("WINNER WINNER WINNER WINNER WINNER",10,55);
        glColor3f(0,0,0);
        printText("WINNER WINNER WINNER WINNER WINNER",20,45);
    }

    glutSwapBuffers();
    glFlush();
}

int main(int argc, char*argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(phyWidth, phyHeight);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Square Game");
    init2D(0.1,0.2,0.8);
    glutDisplayFunc(display);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(specialKeyboard);
    glutMainLoop();
}
