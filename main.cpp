#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
GLfloat V0[3];
GLfloat V1[3];
GLfloat V2[3];
GLfloat V0n[3], V1n[3], V2n[3];


void shearing(){
    //vertex 0
    V0n[0] = V0[0];
    V1n[0] = V1[0]+(2*V0[0]);
    V2n[0] = V2[0]+(3*V0[0]);
    //vertex 1
    V0n[1] = V0[1]+(2*V1[1]);
    V1n[1] = V1[1];
    V2n[1] = V2[1]+(3*V1[1]);
    //vertex 2
    V0n[2] = V0[2]+(2*V2[2]);
    V1n[2] = V1[2]+(2*V2[2]);
    V2n[2] = V2[2];
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(10,0,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,10,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,0,10);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(V0[0], V0[1], V0[2]);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(V1[0], V1[1], V1[2]);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(V2[0], V2[1], V2[2]);
    glEnd();
  //reflection
    shearing();
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(V0n[0], V0n[1], V0n[2]);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(V1n[0], V1n[1], V1n[2]);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(V2n[0], V2n[1], V2n[2]);
    glEnd();


    glFlush();
}




int main(int argc, char** argv) {

    cout<<"Enter vertex 0: ";
    cin>>V0[0]>>V0[1]>>V0[2];
    cout<<"Enter vertex 1: ";
    cin>>V1[0]>>V1[1]>>V1[2];
    cout<<"Enter vertex 2: ";
    cin>>V2[0]>>V2[1]>>V2[2];

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500, 500);
    glutCreateWindow("shearing of a Triangle");
    glOrtho(-10.0f, 10.0f,-10.0f, 10.0f,-10.0f, 10.0f);
    glRotatef(-225, 0.0, 1.0, 0.0); // rotate around y axis
    glRotatef(-16, 0.0, 0.0, 1.0); // rotate around z axis
    glRotatef(16, 1.0, 0.0, 0.0);
    glutDisplayFunc(display);

    glutMainLoop();
}
