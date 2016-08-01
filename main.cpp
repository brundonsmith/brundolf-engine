
// external
#include <iostream>
#include "sdl/SDL.h"

// framework
#include "core/game.hpp"
#include "core/components/transform.hpp"
#include "graphics_sdl/components/sdl_renderer.hpp"

using namespace std;
using namespace brundolfEngine::core;
using namespace brundolfEngine::core::components;
using namespace brundolfEngine::graphicsSdl::components;

int main(int argc, char* args[]) {

  Game myGame;
  Scene scene1;
  Entity bob;
  Transform component1;
  SdlRenderer component2;

  bob.addComponent(&component1);
  bob.addComponent(&component2);

  scene1.addEntity(bob);

  myGame.addScene(scene1);

  myGame.start();
  return 0;
}
