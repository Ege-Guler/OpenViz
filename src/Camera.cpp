#include "Camera.h"
#include <cmath>
#include <iostream>

// Constructor
Camera::Camera(GLfloat d, GLfloat ax, GLfloat ay, GLfloat px, GLfloat py, GLfloat pz)
    :distance(d), angleX(ax), angleY(ay), posX(px), posY(py), posZ(pz) {}

// Apply camera view using gluLookAt
void Camera::applyView() {
    GLfloat radX = angleX * M_PI / 180.0f;
    GLfloat radY = angleY * M_PI / 180.0f;

    GLfloat camX = distance * cos(radY) * sin(radX);
    GLfloat camY = distance * sin(radY);
    GLfloat camZ = distance * cos(radY) * cos(radX);

    Camera::setPosition(camX, camY, camZ);

    gluLookAt(camX, camY, camZ, posX, posY, posZ, 0.0f, 1.0f, 0.0f);
}

void Camera::setDistance(GLfloat d) {
    
    if(d < 1.0f){
        d = 1.0f;
    }
    else if(d > 200.0f){

        d = 200.0f;
    }
    this->distance = d;

}

GLfloat Camera::getDistance() {
    return this->distance;
}

// Set camera position
void Camera::setPosition(GLfloat x, GLfloat y, GLfloat z) {
    this->camX = x;
    this->camY = y;
    this->camZ = z;
}

// Set rotation (yaw and pitch)
void Camera::setRotation(GLfloat ax, GLfloat ay) {
    this->angleX = ax;
    this->angleY = ay;
}

// Move camera forward along its view direction
void Camera::moveForward(GLfloat speed) {
    posX += speed * sin(angleX * M_PI / 180.0f);
    posZ += speed * cos(angleX * M_PI / 180.0f);
}

// Strafe (move sideways)
void Camera::moveRight(GLfloat speed) {
    posX += speed * cos(angleX * M_PI / 180.0f);
    posZ -= speed * sin(angleX * M_PI / 180.0f);
}

// Move up along Y-axis
void Camera::moveUp(GLfloat speed) {
    posY += speed;
}

// Draw Frustum (Field of View Visualization)
void Camera::drawFrustum(GLfloat nearDist, GLfloat farDist, GLfloat fov, GLfloat aspectRatio) {
    // GLfloat nearDist = 1.0f;  // Near plane distance
    // GLfloat farDist = 100.0f; // Far plane distance
    // GLfloat fov = 45.0f;      // Field of view

    // GLfloat aspectRatio = 16.0f / 9.0f;  // Common aspect ratio

    GLfloat tanFov = tan(fov * 0.5 * M_PI / 180.0f);

    // Calculate frustum plane dimensions
    GLfloat nearHeight = nearDist * tanFov;
    GLfloat nearWidth = nearHeight * aspectRatio;
    GLfloat farHeight = farDist * tanFov;
    GLfloat farWidth = farHeight * aspectRatio;

    glPushMatrix();
    glTranslatef(camX, camY, camZ);  // Position camera at its location
    glutSolidSphere(0.1, 10, 10);  // Draw a small sphere at camera position
    glRotatef(angleX, 0, 1, 0);
    glRotatef(-angleY, 1, 0, 0);

    // Draw frustum edges
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow for visibility
    glBegin(GL_LINES);
    // Near plane
    glVertex3f(-nearWidth, -nearHeight, -nearDist);
    glVertex3f(nearWidth, -nearHeight, -nearDist);
    
    glVertex3f(nearWidth, -nearHeight, -nearDist);
    glVertex3f(nearWidth, nearHeight, -nearDist);

    glVertex3f(nearWidth, nearHeight, -nearDist);
    glVertex3f(-nearWidth, nearHeight, -nearDist);

    glVertex3f(-nearWidth, nearHeight, -nearDist);
    glVertex3f(-nearWidth, -nearHeight, -nearDist);

    // Far plane
    glVertex3f(-farWidth, -farHeight, -farDist);
    glVertex3f(farWidth, -farHeight, -farDist);

    glVertex3f(farWidth, -farHeight, -farDist);
    glVertex3f(farWidth, farHeight, -farDist);

    glVertex3f(farWidth, farHeight, -farDist);
    glVertex3f(-farWidth, farHeight, -farDist);

    glVertex3f(-farWidth, farHeight, -farDist);
    glVertex3f(-farWidth, -farHeight, -farDist);

    // Connect near and far planes
    glVertex3f(-nearWidth, -nearHeight, -nearDist);
    glVertex3f(-farWidth, -farHeight, -farDist);

    glVertex3f(nearWidth, -nearHeight, -nearDist);
    glVertex3f(farWidth, -farHeight, -farDist);

    glVertex3f(nearWidth, nearHeight, -nearDist);
    glVertex3f(farWidth, farHeight, -farDist);

    glVertex3f(-nearWidth, nearHeight, -nearDist);
    glVertex3f(-farWidth, farHeight, -farDist);
    glEnd();

    glPopMatrix();
}

// Draw a line to show view direction
void Camera::drawViewDirection() {
    glPushMatrix();
    glTranslatef(posX, posY, posZ);  // Camera position

    // Calculate view direction vector
    GLfloat dx = sin(angleX * M_PI / 180.0f);
    GLfloat dz = cos(angleX * M_PI / 180.0f);

    glColor3f(0.0f, 1.0f, 0.0f);  // Green for direction line
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);  // Start from camera position
    glVertex3f(dx * 10, 0, dz * 10);  // Extend the line forward
    glEnd();

    glPopMatrix();
}
