
// external
#include <iostream>
#include "sdl/SDL.h"

// framework
#include "core/game.hpp"

using namespace brundolfEngine::core;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {

  Game myGame;
  myGame.start();

  return 0;
}
