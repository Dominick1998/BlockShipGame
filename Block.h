#ifndef BLOCK_H
#define BLOCK_H

#include <random>
#include "constants.h"

class Ship;

class Block {
public:
    static std::random_device seed;
    static std::default_random_engine blockEngine;
    Block();

    bool update(Ship& player);

    RGB getColor() const;
    Vector2D getVelocity() const;
    Vector2D getPosition() const;
    Dimensions getDimensions() const;

private:
    void colorize();
    bool collides(const Ship& player);

    Sprite sprite{ {0,0}, {0,0}, {0,0,0} };
    Vector2D velocity{ 0,0 };
};

#endif // BLOCK_H
