#include "helper.h"


bool insideViewport(int x, int y, int viewportX, int viewportY, int viewportWidth, int viewportHeight) {
    return (x >= viewportX && x <= viewportX + viewportWidth &&
            y >= viewportY && y <= viewportY + viewportHeight);
}
