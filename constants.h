#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>

const int maxColors{ 255 };
const int colorJump{ 10 };

// GUI Constants
const int screenWidth{ 20 * 30 };
const int screenHeight{ int(floor((float(2) / 3) * screenWidth)) };

// Structs
struct Vector2D {
    int x;
    int y;
};

struct Dimensions {
    int width;
    int height;
    int radius;
};

struct RGB {
    int R;
    int G;
    int B;
};

struct Sprite {
    Vector2D position;
    Dimensions dimensions;
    RGB color;
};

#endif // CONSTANTS_H
