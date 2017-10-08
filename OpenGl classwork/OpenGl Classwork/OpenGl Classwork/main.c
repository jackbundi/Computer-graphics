#include<GLUT/glut.h>
void myinit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void hut(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.4,0.2);
    
    glBegin(GL_POLYGON);            //main rectangle
    glVertex2d (0.1, 0.1);
    glVertex2d (0.4, 0.1);
    glVertex2d (0.4, 0.5);
    glVertex2d (0.1, 0.5);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    
    glBegin(GL_POLYGON);        //door
    glVertex2d(0.3, 0.1);
    glVertex2d(0.2, 0.1);
    glVertex2d(0.2, 0.3);
    glVertex2d(0.3, 0.3);
    glEnd();
    

    glBegin(GL_POLYGON);
    glVertex3f (0.10, 0.5, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    
    glBegin(GL_POLYGON);
    glVertex3f (0.4, 0.1, 0.0);
    glVertex3f (0.8, 0.4, 0.0);
    glVertex3f (0.8, 0.75, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glEnd();
    glColor3f(0.4,0.0,0.4);
    
    glBegin(GL_POLYGON);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.8, 0.75, 0.0);
    glVertex3f (0.62, 0.93, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("House");
    myinit();
    glutDisplayFunc(hut);
    glutMainLoop();
}
