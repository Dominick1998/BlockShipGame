#include <iostream>
#include "Ship.h"

using namespace std;

Ship::Ship(Sprite sprite, int health)
    : sprite(sprite), health(health), maxHealth(health) {
}

bool Ship::update(Command command) {
    switch (command) {
    case Command::Left:
        sprite.position.x -= speed;
        if (sprite.position.x < 0)
            sprite.position.x = 0;
        break;
    case Command::Right:
        sprite.position.x += speed;
        if (sprite.position.x + sprite.dimensions.width > screenWidth)
            sprite.position.x = screenWidth - sprite.dimensions.width;
        break;
    }
    return health > 0;
}

void Ship::takeDamage(int damage) {
    health -= damage;
    colorize();
    cout << health << endl;
}

RGB Ship::getColor() const {
    return sprite.color;
}

Vector2D Ship::getPosition() const {
    return sprite.position;
}

Dimensions Ship::getDimensions() const {
    return sprite.dimensions;
}

void Ship::heal(int healing) {
    if (health + healing < maxHealth)
        health += healing;
    else
        health = maxHealth;
    colorize();
    cout << health << endl;
}

void Ship::colorize() {
    sprite.color.G = static_cast<int>((static_cast<float>(health) / maxHealth) * maxColors);
    sprite.color.B = static_cast<int>((static_cast<float>(health) / maxHealth) * maxColors);
}
