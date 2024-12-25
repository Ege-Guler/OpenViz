#include <GL/glut.h>
#include "Axes.h"

// Default toggles to show/hide the axes
bool showOriginAxes = true;
bool showObjectAxes = true;

// Function to draw axes at the origin (default)
void drawAxes(float length) {
    glLineWidth(2.0f);  // Thicker lines for better visibility

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
    glLineWidth(1.0f);  // Reset line width
}

// Function to draw axes at any given position (x, y, z)
void drawAxesAt(float x, float y, float z, float length) {
    glPushMatrix();  // Save current transformation state

    // Translate to the specified position
    glTranslatef(x, y, z);

    // Draw axes at the translated position
    drawAxes(length);

    glPopMatrix();  // Restore previous transformation state
}

void drawSphere(float x, float y, float z, float radius, float r, float g, float b) {
    glPushMatrix();  // Save current transformation state

    glColor3f(r, g, b);  // Set sphere color
    glTranslatef(x, y, z);  // Move sphere to specified location
    glutSolidSphere(radius, 16, 16);  // Draw sphere (radius, slices, stacks)

    glPopMatrix();  // Restore transformation state
}

