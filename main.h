#ifndef MAIN_H_
#define MAIN_H_

#include <GL/glut.h>

GLfloat cameraDistance = 5.0f;
GLfloat cameraAngleX = 0.0f;
GLfloat cameraAngleY = 0.0f;

struct Cam
{
    GLfloat cameraDistance;
    GLfloat cameraAngleX;
    GLfloat cameraAngleY;
};

// Last mouse pos
struct Mouse
{
    GLuint mouseX;
    GLuint mouseY;
};

Mouse mouse;
Cam cam = {5.0f, 0.0f, 0.0f};

void display();
void reshape(int width, int height);

void mouseMotion(int x, int y);
void mouseButton(int button, int state, int x, int y);

bool isDragging = false;

#endif // MAIN_H_