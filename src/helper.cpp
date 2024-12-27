#include "helper.h"


bool insideViewport(int x, int y, const Viewport& vp) {
    return (x >= vp.viewportX && x <= vp.viewportX + vp.viewportWidth &&
            y >= vp.viewportY && y <= vp.viewportY + vp.viewportHeight);
}

bool isMouseInViewport(int x, int y) {
    return insideViewport(x, y, viewport);
}


// void updateCamera() {
//     Camera& cam = cameras[currentCameraIndex];

//     GLfloat radX = cam.angleX * M_PI / 180.0f;
//     GLfloat radY = cam.angleY * M_PI / 180.0f;

//     GLfloat camX = cam.distance * cos(radY) * sin(radX);
//     GLfloat camY = cam.distance * sin(radY);
//     GLfloat camZ = cam.distance * cos(radY) * cos(radX);

//     gluLookAt(camX, camY, camZ,  // Camera position
//               cam.posX, cam.posY, cam.posZ,  // Look-at point
//               0.0f, 1.0f, 0.0f);  // Up vector
// }


bool keyStates[256];  // Track key states

void updateFreeCamera() {
    GLfloat forwardX = freeCamera.dirX;
    GLfloat forwardZ = freeCamera.dirZ;

    GLfloat rightX = -forwardZ; 
    GLfloat rightZ = forwardX;

    GLfloat length = sqrt(forwardX * forwardX + forwardZ * forwardZ);
    forwardX /= length;
    forwardZ /= length;
    rightX /= length;
    rightZ /= length;

    // WASD Movement
    if (keyStates['w']) {
        freeCamera.posX += forwardX * freeCamera.speed;
        freeCamera.posZ += forwardZ * freeCamera.speed;
    }
    if (keyStates['s']) {
        freeCamera.posX -= forwardX * freeCamera.speed;
        freeCamera.posZ -= forwardZ * freeCamera.speed;
    }
    if (keyStates['a']) {
        freeCamera.posX -= rightX * freeCamera.speed;
        freeCamera.posZ -= rightZ * freeCamera.speed;
    }
    if (keyStates['d']) {
        freeCamera.posX += rightX * freeCamera.speed;
        freeCamera.posZ += rightZ * freeCamera.speed;
    }

    // Vertical Movement
    if (keyStates[' ']) freeCamera.posY += freeCamera.speed;  // Space - up
    if (keyStates['c']) freeCamera.posY -= freeCamera.speed;  // Ctrl - down

    // Apply gluLookAt with the new camera position
    gluLookAt(freeCamera.posX, freeCamera.posY, freeCamera.posZ,  // Eye position
              freeCamera.posX + freeCamera.dirX, freeCamera.posY + freeCamera.dirY, freeCamera.posZ + freeCamera.dirZ,  // Look-at point
              freeCamera.upX, freeCamera.upY, freeCamera.upZ);   // Up vector
}
