#ifndef GUI_H
#define GUI_H

#include <string>
#include <vector>

// GUI definitions
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL2_gfxPrimitives.h"
#include "Timer.h"

// User-defined tools
#include "constants.h"
#include "Block.h"
#include "Ship.h"
#include "PowerUp.h"

using namespace std;

class GUI {
public:
    GUI();
    ~GUI();
    void startTimer();
    void delay();
    void displayGame(const vector<PowerUp>& powerUps, const vector<Block>& blocks, const Ship& player);
    Ship::Command getCommand();
    const int FPS{ 30 };

private:
    const int frameDelay{ 1000 / FPS };

    // Private methods
    void initGUI();
    void cleanUp();

    // Private members
    SDL_Window* window{ nullptr };
    SDL_Renderer* renderer{ nullptr };
    TTF_Font* normalFont{ nullptr };
    SDL_Event* event{ nullptr };
    Timer* frame;
};

#endif // GUI_H
