#include "timer.h"

Timer::Timer() {
    // Initialize variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start() {
    // Start timer
    started = true;

    // Unpause timer
    paused = false;

    // Current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop() {
    // Stop timer
    started = false;

    // Unpause timer
    paused = false;
}

void Timer::pause() {
    // If the timer is running and isn't already paused
    if ((started == true) && (paused == false)) {
        // Pause timer
        paused = true;

        // Calculate paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause() {
    // If the timer is paused
    if (paused == true) {
        // Unpause timer
        paused = false;

        // Reset starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        // Reset paused ticks
        pausedTicks = 0;
    }
}

int Timer::get_ticks() {
    // If the timer running
    if (started == true) {
        // If the timer paused
        if (paused == true) {
            // Return the number of ticks when the timer was paused
            return pausedTicks;
        } else {
            // Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    // If the timer isn't running
    return 0;
}

bool Timer::is_started() {
    return started;
}

bool Timer::is_paused() {
    return paused;
}
