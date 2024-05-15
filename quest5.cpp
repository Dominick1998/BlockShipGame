#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "GUI.h"
#include "constants.h"
#include "Block.h"
#include "Ship.h"
#include "PowerUp.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Construct GUI
    GUI gui;

    // Create block vector
    vector<Block> blocks;
    vector<PowerUp> powerUps;

    // Create player with initial values. White, bottom, centered
    Ship player(
        { {screenWidth / 2 - 10, screenHeight - 25},{20,20,0},{maxColors, maxColors, maxColors} },
        100
    );

    // For storing latest command
    Ship::Command command = Ship::Command::NA;

    // Player's update returns true if the player has not died, otherwise false
    while (player.update(command)) {
        // My timer
        gui.startTimer();

        // Random block creation
        static bernoulli_distribution createPowerUp(.01);
        /*
        if (createPowerUp(Object::objectEngine))
        {
            powerUps.push_back(PowerUp());
        }

        static bernoulli_distribution createBlock(0.2);
        if (createBlock(Object::objectEngine))
        {
            blocks.push_back(Block());
        }
        */

        // Run Block's update. Delete any blocks that reach the bottom of the screen
        for (auto blockIter = blocks.begin(); blockIter != blocks.end();) {
            if (!(*blockIter).update(player)) {
                blockIter = blocks.erase(blockIter);
            } else {
                blockIter++;
            }
        }

        /*
        for (auto powerUpIter = powerUps.begin(); powerUpIter != powerUps.end();) {
            if (!(*powerUpIter).update(player)) {
                powerUpIter = powerUps.erase(powerUpIter);
            } else {
                powerUpIter++;
            }
        }
        */

        // Get the latest command
        command = gui.getCommand();
        // GUI displays updated scene
        gui.displayGame(powerUps, blocks, player);

        // Pause game to regulate frame rate
        gui.delay();
    }

    return 0;
}
