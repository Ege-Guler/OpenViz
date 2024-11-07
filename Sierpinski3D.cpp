#include <GL/glut.h>
#include "Sierpinski3D.h"

void drawTetrahedron(float x, float y, float z, float size) {
    glBegin(GL_TRIANGLES);
        
        // Four faces of a tetrahedron
        glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
        glVertex3f(x, y + size, z);
        glColor4f(.0f, .0f, 1.0f, 0.5f);
        glVertex3f(x - size, y - size, z - size);
        glColor4f(1.0f, .0f, 0.0f, 0.5f);
        glVertex3f(x + size, y - size, z - size);

        glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
        glVertex3f(x, y + size, z);
        glColor4f(.0f, .0f, 1.0f, 0.5f);
        glVertex3f(x + size, y - size, z - size);
        glColor4f(1.0f, .0f, 0.0f, .0f);
        glVertex3f(x, y - size, z + size);

        glColor4f(1.0f, .0f, 0.0f, 0.5f);
        glVertex3f(x, y + size, z);
        glColor4f(.0f, 1.0f, .0f, 0.5f);
        glVertex3f(x - size, y - size, z - size);
        glColor4f(.0f, .0f, 1.0f, 0.5f);
        glVertex3f(x, y - size, z + size);

        glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
        glVertex3f(x - size, y - size, z - size);
        glColor4f(.0f, .0f, 1.0f, 0.5f);
        glVertex3f(x + size, y - size, z - size);
        glColor4f(1.0f, .0f, .0f, 0.5f);
        glVertex3f(x, y - size, z + size);
    glEnd();
}

void Sierpinski3D::draw(float x, float y, float z, float size, int depth) {
    if (depth == 0) {
        drawTetrahedron(x, y, z, size);
    } else {
        float newSize = size / 2;
        draw(x, y + newSize, z, newSize, depth - 1);
        draw(x - newSize, y - newSize, z - newSize, newSize, depth - 1);
        draw(x + newSize, y - newSize, z - newSize, newSize, depth - 1);
        draw(x, y - newSize, z + newSize, newSize, depth - 1);
    }
}

void Sierpinski3D::drawSierpinskiObject(float translateX, float translateY, float translateZ, float rotationAngle, float scaleFactor) {
    glPushMatrix(); 

    glTranslatef(translateX, translateY, translateZ); 
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);      
    glScalef(scaleFactor, scaleFactor, scaleFactor); 

    // Draw the Sierpinski tetrahedron
    Sierpinski3D sierpinski;
    sierpinski.draw(0.0f, 0.0f, 0.0f, 1.0f, 4); 

    glPopMatrix(); 
}