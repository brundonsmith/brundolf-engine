
// external
#include <iostream>
#include "sdl/SDL.h"

// internal
#include "core/game.hpp"
#include "graphics_sdl/sdl_gfx_context.hpp"

using namespace std;
using namespace brundolfEngine::core;
using namespace brundolfEngine::graphicsSdl;

SdlGfxContext::SdlGfxContext() {
}
SdlGfxContext::~SdlGfxContext() {
}

void SdlGfxContext::initialize() {
  GameOptions gameOptions = Game::getInstance()->getOptions();

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
  } else {
    //Create window
    this->window = SDL_CreateWindow(
        gameOptions.TITLE.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        gameOptions.RESOLUTION_X,
        gameOptions.RESOLUTION_Y,
        SDL_WINDOW_SHOWN
      );

    if( this->window == NULL ) {
      cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
    } else {
      screenSurface = SDL_GetWindowSurface( window );
    }
  }
}
void SdlGfxContext::refresh() {
  SDL_UpdateWindowSurface( this->window );
}
void SdlGfxContext::quit() {
  //Destroy window
  SDL_DestroyWindow( this->window );

  //Quit SDL subsystems
  SDL_Quit();
}

SDL_Window* SdlGfxContext::getWindow() {
  return this->window;
}
SDL_Surface* SdlGfxContext::getScreenSurface() {
  return this->screenSurface;
}
