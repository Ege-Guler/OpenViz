#include <GL/glut.h>
#include "Sierpinski3D.h"
#include "main.h"
#include <cmath>

Sierpinski3D sierpinski3D;


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("OpenViz");

    glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);


    glutMainLoop();
}

// Mouse button callback
void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDragging = true;
            mouse.mouseX = x;
            mouse.mouseY = y;
        } else {
            isDragging = false;
        }
    }
}

// Mouse motion callback
void mouseMotion(int x, int y) {
    if (isDragging) {
        // Calculate the difference in mouse movement
        int dx = x - mouse.mouseX;
        int dy = y - mouse.mouseY;

        // Adjust the camera angles based on mouse movement
        cam.cameraAngleX += dx * 0.5f;
        cam.cameraAngleY += dy * 0.5f;

        // Limit the vertical angle to prevent flipping
        if (cam.cameraAngleY > 89.0f) cam.cameraAngleY = 89.0f;
        if (cam.cameraAngleY < -89.0f) cam.cameraAngleY = -89.0f;

        mouse.mouseX = x;
        mouse.mouseY = y;

        glutPostRedisplay();  
    }
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    GLfloat radX = cam.cameraAngleX * M_PI / 180.0f;
    GLfloat radY = cam.cameraAngleY * M_PI / 180.0f;
    GLfloat camX = cam.cameraDistance * cos(radY) * sin(radX);
    GLfloat camY = cam.cameraDistance * sin(radY);
    GLfloat camZ = cam.cameraDistance * cos(radY) * cos(radX);

    gluLookAt(camX, camY, camZ,   // Camera position
              0.0f, 0.0f, 0.0f,   // Look-at point (origin)
              0.0f, 1.0f, 0.0f);  // Up vector

    sierpinski3D.drawSierpinskiObject(0.0f, 0.0f, -2.0f, 30.0f, 1.5f);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
