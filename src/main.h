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

struct Viewport
{
    int viewportWidth;
    int viewportHeight;
    int viewportX;
    int viewportY;
};


Viewport viewport = {1280, 720, 1920 -1280, 1080 - 720};
Mouse mouse;
Cam cam = {5.0f, 0.0f, 0.0f};

void renderGUI();
void display();
void reshape(int width, int height);
void updateViewPort();
void mouseMotion(int x, int y);
void mouseButton(int button, int state, int x, int y);

bool isDragging = false;

#endif // MAIN_H_