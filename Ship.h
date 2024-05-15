#ifndef SHIP_H
#define SHIP_H

#include "constants.h"

class Ship {
public:
    Ship(Sprite sprite, int health);
    enum class Command { Left, Right, NA };
    bool update(Command command);

    void takeDamage(int damage);
    RGB getColor() const;
    Vector2D getPosition() const;
    Dimensions getDimensions() const;
    void heal(int healing);

private:
    Sprite sprite{ { 0,0 },{ 0,0 },{ 0,0,0 } };
    void colorize();
    int health{ 0 };
    const int maxHealth{ 0 };
    static const int speed{ 5 };
};

#endif // SHIP_H
