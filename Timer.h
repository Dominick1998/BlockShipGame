#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

class Timer {
private:
    // Timer start clock time
    int startTicks;

    // Ticks stored when timer was paused
    int pausedTicks;

    // Timer status
    bool paused;
    bool started;

public:
    // Initializes variables
    Timer();

    // Clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    // Timer time
    int get_ticks();

    // Check timer status
    bool is_started();
    bool is_paused();
};

#endif // TIMER_H
