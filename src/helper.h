#ifndef HELPER_H_
#define HELPER_H_

#include "main.h"

struct Viewport;

void updateCamera();
void updateFreeCamera();
bool insideViewport(int x, int y, const Viewport& vp);
bool isMouseInViewport(int x, int y);

#endif // HELPER_H_