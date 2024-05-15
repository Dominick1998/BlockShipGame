# Block Ship Game

## Overview
This project is a C++ game where blocks fall from the top of the screen and a player-controlled ship must avoid them. The game uses the SDL library for rendering.

## Features
- Randomly generated falling blocks with varying dimensions and colors.
- Player-controlled ship that can move left and right.
- Collision detection between blocks and the ship.
- Dynamic color changes for blocks as they fall.

## Files
- `Block.cpp`, `Block.h`: Implementation of the `Block` class.
- `constants.h`: Constants used throughout the game.
- `GUI.cpp`, `GUI.h`: Implementation of the graphical user interface using SDL.
- `Object.cpp`, `Object.h`: Base class for objects in the game.
- `PowerUp.cpp`, `PowerUp.h`: Implementation of power-ups in the game.
- `quest5.cpp`: Main file to run the game.
- `RandomFallingObject.cpp`, `RandomFallingObject.h`: Base class for random falling objects.
- `Ship.cpp`, `Ship.h`: Implementation of the player's ship.
- `Timer.cpp`, `Timer.h`: Implementation of the timer class using SDL.

## How to Run
1. Ensure you have a C++ compiler and SDL library installed.
2. Compile the code using the following command:
   ```sh
   g++ Block.cpp GUI.cpp Object.cpp PowerUp.cpp quest5.cpp RandomFallingObject.cpp Ship.cpp Timer.cpp -o BlockShipGame -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx
   ```
3. Run the game using the following command:
   ```sh
   ./BlockShipGame
   ```

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Author
**Dominick Ferro**
