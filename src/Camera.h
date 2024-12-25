#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>

class Camera {
public:
    GLfloat camX, camY, camZ;
    GLfloat distance;
    GLfloat angleX;
    GLfloat angleY;
    GLfloat posX;
    GLfloat posY;
    GLfloat posZ;

    Camera(GLfloat d, GLfloat ax, GLfloat ay, GLfloat px, GLfloat py, GLfloat pz);

    void applyView();
    void setPosition(GLfloat x, GLfloat y, GLfloat z);
    void setRotation(GLfloat ax, GLfloat ay);
    void setDistance(GLfloat d);
    GLfloat getDistance();
    void moveForward(GLfloat speed);
    void moveRight(GLfloat speed);
    void moveUp(GLfloat speed);
    void drawFrustum(GLfloat nearDist, GLfloat farDist, GLfloat fov, GLfloat aspectRatio);
    void drawViewDirection();
};

#endif // CAMERA_H
