#include <random>
#include <iostream>
#include "Block.h"
#include "Ship.h"

using namespace std;

// Initialize the random device and engine for Block
random_device Block::seed;
default_random_engine Block::blockEngine(Block::seed());

// Default constructor for Block
Block::Block() {
    // Initialize block dimensions with random width and height
    uniform_int_distribution<int> sideLength(5, 20);
    sprite.dimensions.width = sideLength(blockEngine);
    sprite.dimensions.height = sideLength(blockEngine);

    // Set the initial position of the block within screen boundaries
    uniform_int_distribution<int> initialPosition(0, screenWidth - sprite.dimensions.width);
    sprite.position.x = initialPosition(blockEngine);

    // Calculate the velocity based on the area of the block
    velocity.y = sprite.dimensions.width * sprite.dimensions.height / 10.0;

    // Set random color for the block
    uniform_int_distribution<int> randomColor(0, maxColors);
    sprite.color.R = randomColor(blockEngine);
    sprite.color.G = randomColor(blockEngine);
    sprite.color.B = randomColor(blockEngine);
}

// Update the block position and check for collisions
bool Block::update(Ship& player) {
    // Move the block down the screen
    sprite.position.y += velocity.y;

    // Check if the block has reached the bottom of the screen
    if (sprite.position.y >= screenHeight) {
        if (collides(player)) {
            // If it collides with the player, inflict damage
            player.takeDamage(sprite.dimensions.width * sprite.dimensions.height / 10.0f);
        }
        return false;
    } else {
        // Otherwise, change the color of the block
        colorize();
        return true;
    }
}

// Get the current color of the block
RGB Block::getColor() const {
    return sprite.color;
}

// Get the current velocity of the block
Vector2D Block::getVelocity() const {
    return velocity;
}

// Get the current position of the block
Vector2D Block::getPosition() const {
    return sprite.position;
}

// Get the dimensions of the block
Dimensions Block::getDimensions() const {
    return sprite.dimensions;
}

// Randomly change the color of the block
void Block::colorize() {
    normal_distribution<double> colorChange(0.0, 10.0);

    sprite.color.R += colorChange(blockEngine);
    sprite.color.G += colorChange(blockEngine);
    sprite.color.B += colorChange(blockEngine);
}

// Check if the block collides with the player ship
bool Block::collides(const Ship & player) {
    bool leftInColumn = (sprite.position.x >= player.getPosition().x && sprite.position.x <= player.getPosition().x + player.getDimensions().width);
    bool rightInColumn = (sprite.position.x + getDimensions().width >= player.getPosition().x && sprite.position.x + getDimensions().width <= player.getPosition().x + player.getDimensions().width);

    bool sameColumn = leftInColumn || rightInColumn;

    return (sprite.position.y > screenHeight - 20 && sameColumn);
}
