
// external
#include <iostream>
#include "sdl/SDL.h"

// internal
#include "core/Game.hpp"
#include "graphics_sdl/components/sdl_renderer.hpp"
#include "graphics_sdl/sdl_gfx_context.hpp"

using namespace std;
using namespace brundolfEngine::core;
using namespace brundolfEngine::graphicsSdl;
using namespace brundolfEngine::graphicsSdl::components;

SdlRenderer::SdlRenderer() {
}
SdlRenderer* SdlRenderer::clone() {
  return new SdlRenderer(*this);
}
SdlRenderer::~SdlRenderer() {
}

void SdlRenderer::initialize() {

}
void SdlRenderer::update(int deltaTime, int currentTime) {

}
void SdlRenderer::draw() {
  GfxContext* gfxContext = Game::getInstance()->getGfxContext();
  if(dynamic_cast<const SdlGfxContext*>(gfxContext) != nullptr) {
    SdlGfxContext* sdlGfxContext = dynamic_cast<SdlGfxContext*>(gfxContext);
    SDL_FillRect( sdlGfxContext->getScreenSurface(), NULL, SDL_MapRGB( sdlGfxContext->getScreenSurface()->format, 0xFF, 0xFF, 0xFF ) );
  }
}
