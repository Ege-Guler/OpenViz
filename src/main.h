#ifndef MAIN_H_
#define MAIN_H_

#include <GL/glut.h>
#include <cmath>
#include "imgui.h"
#include "imgui_impl_glut.h"
#include "imgui_impl_opengl2.h"
#include <iostream>
#include "helper.h"
#include "Axes.h"

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

struct Rotation {
    float angleX = 0.0f;
    float angleY = 0.0f;
    float angleZ = 0.0f;
    float speedX = 0.0f;
    float speedY = 0.0f;
    float speedZ = 0.0f;
} rotation;



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