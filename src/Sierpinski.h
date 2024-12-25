#ifndef SIERPINSKI3D_H
#define SIERPINSKI3D_H

class Sierpinski3D {
public:
    void draw(float x, float y, float z, float size, int depth);
    void drawSierpinskiObject(float translateX, float translateY, float translateZ, float rotationAngle, float scaleFactor);

};

#endif // SIERPINSKI3D_H