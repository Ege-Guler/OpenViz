#include <GL/glut.h>
#include "Axes.h"

bool showOriginAxes = true;
bool showObjectAxes = true;

void drawAxes(float length) {
    glLineWidth(2.0f);  

    glBegin(GL_LINES);

    // X-Axis (Red)
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(length, 0.0f, 0.0f);

    // Y-Axis (Green)
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, length, 0.0f);

    // Z-Axis (Blue)
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, length);

    glEnd();
    glLineWidth(1.0f); 
}

void drawAxesAt(float x, float y, float z, float length) {
    glPushMatrix();  

    glTranslatef(x, y, z);

    drawAxes(length);

    glPopMatrix();  
}

void drawSphere(float x, float y, float z, float radius, float r, float g, float b) {
    glPushMatrix();  
    glColor3f(r, g, b); 
    glTranslatef(x, y, z); 
    glutSolidSphere(radius, 16, 16);  

    glPopMatrix(); 
}


#include <GL/glut.h>

void drawGrid(float size, int divisions, float y) {
    glLineWidth(1.0f); 
    glColor3f(0.5f, 0.5f, 0.5f);  

    glBegin(GL_LINES);

    float step = size / divisions;
    float halfSize = size / 2.0f;

    for (float i = -halfSize; i <= halfSize; i += step) {
        glVertex3f(-halfSize, y, i);  
        glVertex3f(halfSize, y, i);   
    }

    for (float i = -halfSize; i <= halfSize; i += step) {
        glVertex3f(i, y, -halfSize);  
        glVertex3f(i, y, halfSize);   
    }

    glEnd();
}

