#ifndef AXES_H_
#define AXES_H_

void drawAxes(float length);
void drawAxesAt(float x, float y, float z, float length);
void drawSphere(float x, float y, float z, float radius, float r, float g, float b);
void drawGrid(float size, int divisions, float y);  

extern bool showOriginAxes;
extern bool showObjectAxes;

#endif  // AXES_H_
