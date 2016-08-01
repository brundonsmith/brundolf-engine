
// external
#include "sdl/SDL.h"

// internal
#include "core/Game.hpp"
#include "graphics_sdl/components/sdl_renderer.hpp"
#include "graphics_sdl/sdl_gfx_context.hpp"

using namespace brundolfEngine;

graphicsSdl::components::SdlRenderer::SdlRenderer() {
}
graphicsSdl::components::SdlRenderer::~SdlRenderer() {
}

void graphicsSdl::components::SdlRenderer::initialize() {

}
void graphicsSdl::components::SdlRenderer::update(int deltaTime, int currentTime) {

}
void graphicsSdl::components::SdlRenderer::draw() {
  core::GfxContext* gfxContext = core::Game::getInstance()->getGfxContext();
  if(dynamic_cast<const graphicsSdl::SdlGfxContext*>(gfxContext) != nullptr) {
    graphicsSdl::SdlGfxContext* sdlGfxContext = dynamic_cast<graphicsSdl::SdlGfxContext*>(gfxContext);
    SDL_FillRect( sdlGfxContext->getScreenSurface(), NULL, SDL_MapRGB( sdlGfxContext->getScreenSurface()->format, 0xFF, 0xFF, 0xFF ) );
  }
}
