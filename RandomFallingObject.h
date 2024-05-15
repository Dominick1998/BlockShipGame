#ifndef RANDOMFALLINGOBJECT_H
#define RANDOMFALLINGOBJECT_H

#include <random>
#include "Object.h"

class RandomFallingObject {
public:
    RandomFallingObject();
    Vector2D getVelocity() const;

protected:
    bool collides(const Ship& player);
    // void colorize() override;

    Vector2D velocity{ 0,0 };
};

#endif // RANDOMFALLINGOBJECT_H
