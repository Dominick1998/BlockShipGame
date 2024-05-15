#include <iostream>
#include <fstream>
#include <string>
#include "GUI.h"
#include "constants.h"

using namespace std;

GUI::GUI() {
    // Initialize the window
    window = nullptr;

    // Initialize the renderer

    // Start-up the GUI
    initGUI();
    frame = new Timer();
}

GUI::~GUI() {
    cleanUp();
}

void GUI::startTimer() {
    frame->start(); // Start the timer
}

void GUI::delay() {
    if (frame->get_ticks() < frameDelay) {
        SDL_Delay(frameDelay - frame->get_ticks());
    }
}

void GUI::initGUI() {
    // Initialize all SDL subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        exit(1);
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        exit(1);
    }
    normalFont = TTF_OpenFont("./Assets/Fonts/impact.ttf", 48);
    if (normalFont == nullptr) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
    }

    // Construct and check window construction
    window = SDL_CreateWindow("CPSC 2376 Quests",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Construct and check renderer construction
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    event = new SDL_Event();
}

void GUI::cleanUp() {
    // Free the window
    SDL_DestroyWindow(window);
    window = NULL;

    // Free the renderer
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    // Free font structures
    TTF_CloseFont(normalFont);

    // Quit SDL Subsystems
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void GUI::displayGame(const vector<PowerUp>& powerUps, const vector<Block>& blocks, const Ship& player) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw blocks
    for (const auto& block : blocks) {
        SDL_Rect blockDraw{ block.getPosition().x, block.getPosition().y, block.getDimensions().width, block.getDimensions().height };
        Uint8 red = block.getColor().R;
        Uint8 green = block.getColor().G;
        Uint8 blue = block.getColor().B;

        SDL_SetRenderDrawColor(renderer, red, green, blue, 0);
        SDL_RenderFillRect(renderer, &blockDraw);
    }

    // Draw player
    filledTrigonRGBA(
        renderer,
        player.getPosition().x + player.getDimensions().width / 2,
        player.getPosition().y,
        player.getPosition().x,
        player.getPosition().y + player.getDimensions().height,
        player.getPosition().x + player.getDimensions().width,
        player.getPosition().y + player.getDimensions().height,
        player.getColor().R, player.getColor().G, player.getColor().B, 255
    );

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // Update the visible screen
    SDL_RenderPresent(renderer);
}

Ship::Command GUI::getCommand() {
    SDL_PollEvent(event);

    switch (event->type) {
    case SDL_KEYDOWN:
        switch (event->key.keysym.sym) {
        case SDLK_LEFT:
            return Ship::Command::Left;
        case SDLK_RIGHT:
            return Ship::Command::Right;
        default:
            return Ship::Command::NA;
        }
    default:
        return Ship::Command::NA;
    }
}
