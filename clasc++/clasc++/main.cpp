#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// declaration of varaiables
int startPoint_X, startPoint_Y, endPoint_X, endPoint_Y;

// request user to input the x and y coordinates of both the initial and final points on the line
void readUserInput(){
    cout << "Enter the starting X coordinate" << endl;
    cin >> startPoint_X;
    cout << "Enter the starting Y coordinate" << endl;
    cin >> startPoint_Y;
    cout << "Enter the final X coordinate" << endl;
    cin >> endPoint_X;
    cout << "Enter the final Y coordinate" << endl;
    cin >> endPoint_Y;
}

// sets the attributes of the window
void setAttributes(){
    glClearColor(1.0, 0.0, 0.0, 0.0); //the background color of the window
    gluOrtho2D(0.0, 50, 0.0, 50.0); // cartesian plane x and y scales only
}

// draws the line given coordinates
void drawLine(int point_x, int point_y){
    glBegin(GL_POINTS);
    glVertex2i(point_x, point_y); //start point
    glEnd();
    glFlush();
}

//Bresenham line algorithm
void bresenhamAlgorithm(GLint point_x, GLint point_y, GLint point_x1, GLint point_y1){
    float dx = (point_x1 - point_x); //calculates change in x
    float dy = (point_y1 - point_y); //calculates change in y
    float gradient = dy / dx; //calculates change in gradient
    float _2dx = 2 * dx; //calculates 2 times change in x
    float _2dy = 2 * dy; //calculates 2 times change in y
    int P; //declartaion decision variable P
    GLfloat x = point_x, y = point_y;
    int n = 0; //declaration of counter
    if (gradient < 1 && gradient > 0){ //if gradient is between 0 and 1
        P = _2dy - dx; //calculates initial value of P
        while (n < dx){ //repeat change in x times
            float diff_2dy_2dx = _2dy - _2dx; //calculate difference in 2 times change in y and 2 times change in x
            if (P < 0){ //increment x but not y
                P = P + _2dy; //calculate new value of P
                x = x++;
                y = y;
                drawLine(x, y); //plot point
            }
            else if (P > 0) { //increment both x and y
                P = P + diff_2dy_2dx; //calculate new value of P
                x = x++;
                y = y++;
                drawLine(x, y); //plot point
            }
            n++; //increment counter
        }
    }
    else if (gradient > 1) { //if gradient is greater than one
        P = _2dx - dy; //calculate the initial value of P
        while (n < dy){ //loop change in y times
            float diff_2dx_2dy = _2dx - _2dy;
            if (P > 0){ //increment both x and y
                P = P + diff_2dx_2dy; //calculate new value of P
                x = x++;
                y = y++;
                drawLine(x, y); //plot point
            }
            else if (P < 0){ //increment only y
                P = P + _2dx; //calculate new value of P
                x = x;
                y = y++;
                drawLine(x, y); //plot point
            }
            n++;
        }
    }
}

// used to call the draw line function
void displayLine(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(1.0, 1.0, 1.0); // color of the line
    glLineWidth(20.0); // line width
    glPointSize(10.0); // point size
    bresenhamAlgorithm(startPoint_X, startPoint_Y, endPoint_X, endPoint_Y);
}

// this function creates the window that displays the line
void makeWindow(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); //window size
    glutInitWindowPosition(50, 50); // window position
    glutCreateWindow("Bresenham Line Algorithm"); //window title
    setAttributes(); //calls setAttributes function
    glutDisplayFunc(displayLine); //generates the line by calling displayLine function
    glutMainLoop();
}

int main(int argc, char *argv[]){
    readUserInput(); //calls readUserInput function
    makeWindow(argc, argv); //calls makeWindow function
    return 0;
}


