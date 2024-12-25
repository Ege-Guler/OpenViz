#ifndef AXES_H_
#define AXES_H_

void drawAxes(float length);
void drawAxesAt(float x, float y, float z, float length);
void drawSphere(float x, float y, float z, float radius, float r, float g, float b);  // Sphere prototype

extern bool showOriginAxes;  // Toggle for showing origin axes
extern bool showObjectAxes;  // Toggle for showing object-local axes

#endif  // AXES_H_
