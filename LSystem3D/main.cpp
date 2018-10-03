// draw 3D
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include "LSys.h"
#include <cmath>
using namespace std;
using namespace zero;

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 0.4;
LSys l('X');
float h = 2;
Color32 fruitC(0, 255, 0, 255);
Color32 treeC(255, 0, 0, 255);
float R = 60;
float eyeY = 20;
float nearZ = 1;
float farZ = 130;
int n = 6;
float eyeX = R;
float eyeZ = R;
float deltaAlpha = 0.01;
float delta = 0.1;
float Aplha = 3.14f / 4;
int sign = 1;

void ReShape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)width / (float)height;
    gluPerspective(45.0, ratio, nearZ, farZ);
    // glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawCordinate()
{
    glBegin(GL_LINES); //OX
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINES); //OY
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glEnd();

    glBegin(GL_LINES); //OZ
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 10.0);
    glEnd();
}
void RenderScene()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0);
    glPushMatrix();
    drawCordinate();
    glPopMatrix();
    glTranslatef(0, 0, 20);
    glRotatef(-90, 1.0, 0, 0);
    l.turle3D();
    glFlush();
}
void Init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);
    // glEnable(GL_DEPTH_TEST);

    // GLfloat light_pos[] = {eyeX, eyeY, eyeZ, 0.0};
    // glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    // // mau
    // GLfloat ambient[] = {1, 1, 0, 1.0};
    // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

    // GLfloat diff_use[] = {0.0, 1, 0.0, 1.0};
    // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

    // GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

    // GLfloat shininess = 1.0f;
    // glMateriali(GL_FRONT, GL_SHININESS, shininess);
}

void MouseFunc(int button, int state, int x, int y)
{
}
void KeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'e':
        exit(-1);
        //terminate the program
    default:
        break;
        // do nothing
    }
}

void idle()
{
    // Aplha += deltaAlpha;
    if (eyeX >= R && sign == 1)
    {
        sign = -1;
    }
    else if (eyeX <= -R && sign == -1)
    {
        sign = 1;
    }

    eyeX += sign * delta;

    // eyeX += delta;
    eyeZ = sqrt(R * R - eyeX * eyeX);
    RenderScene();
}
int main(int argc, char **argv)
{
    for (int i = 1; i <= n; ++i)
    {
        l.generate();
    }

    //
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Opengl Study");

    Init();
    glutMouseFunc(MouseFunc);
    glutKeyboardFunc(KeyboardFunc);
    glutReshapeFunc(ReShape);

    glutDisplayFunc(RenderScene);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
