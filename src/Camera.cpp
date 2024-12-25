#include "Camera.h"
#include <cmath>

// Constructor to initialize the camera
Camera::Camera(GLfloat d, GLfloat ax, GLfloat ay, GLfloat px, GLfloat py, GLfloat pz)
    : distance(d), angleX(ax), angleY(ay), posX(px), posY(py), posZ(pz) {}

// Apply gluLookAt to position the camera
void Camera::applyView() {
    GLfloat radX = angleX * M_PI / 180.0f;
    GLfloat radY = angleY * M_PI / 180.0f;

    GLfloat camX = distance * cos(radY) * sin(radX);
    GLfloat camY = distance * sin(radY);
    GLfloat camZ = distance * cos(radY) * cos(radX);

    gluLookAt(camX, camY, camZ, posX, posY, posZ, 0.0f, 1.0f, 0.0f);
}

// Set new camera position
void Camera::setPosition(GLfloat x, GLfloat y, GLfloat z) {
    posX = x;
    posY = y;
    posZ = z;
}

// Set camera rotation angles
void Camera::setRotation(GLfloat ax, GLfloat ay) {
    angleX = ax;
    angleY = ay;
}

// Move forward along the view direction
void Camera::moveForward(GLfloat speed) {
    posX += speed * sin(angleX * M_PI / 180.0f);
    posZ += speed * cos(angleX * M_PI / 180.0f);
}

// Move right perpendicular to forward direction
void Camera::moveRight(GLfloat speed) {
    posX += speed * cos(angleX * M_PI / 180.0f);
    posZ -= speed * sin(angleX * M_PI / 180.0f);
}

// Move up and down along the Y-axis
void Camera::moveUp(GLfloat speed) {
    posY += speed;
}
