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
#include "Camera.h"
#include "Console.h"


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
    float angleX;
    float angleY;
    float angleZ;
    float speedX;
    float speedY;
    float speedZ;
};

struct FreeCamera {
    GLfloat posX, posY, posZ;     // Position
    GLfloat dirX, dirY, dirZ;     // Direction
    GLfloat upX, upY, upZ;        // Up vector
    GLfloat speed;                // Movement speed
    GLfloat sensitivity;          // Mouse sensitivity
};


extern bool keyStates[256];  // Track key states

extern Viewport viewport;
extern Mouse mouse;
extern Rotation rotation;
extern Camera cameras[4];
extern int currentCameraIndex;  // Selected camera
extern bool isDragging;
extern FreeCamera freeCamera;
extern bool freeRoam;
extern GLfloat farPlane;
extern GLfloat nearPlane;
extern Console console;
extern GLfloat fov;
extern bool showFrustrum[4];

void renderGUI();
void display();
void reshape(int width, int height);
void updateViewPort();
void mouseMotion(int x, int y);
void mouseButton(int button, int state, int x, int y);
void RenderMainControls();

#endif // MAIN_H_