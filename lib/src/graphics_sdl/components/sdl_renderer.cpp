
// external
#include <iostream>
#include <cmath>
#include "sdl/SDL.h"

// internal
#include "core/components/transform.hpp"
#include "core/Game.hpp"
#include "graphics_sdl/components/sdl_renderer.hpp"
#include "graphics_sdl/sdl_gfx_context.hpp"

using namespace std;
using namespace brundolfEngine::core;
using namespace brundolfEngine::core::components;
using namespace brundolfEngine::core::util;
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
  Transform* transform = this->entity->getComponent<Transform>();
  transform->position += Vector3(0, 10, 0) * ((float)deltaTime / 1000.0f);
}
void SdlRenderer::draw() {
  GfxContext* gfxContext = Game::getInstance()->getGfxContext();
  Transform* transform = this->entity->getComponent<Transform>();
  Vector3 position = transform->position;
  Vector3 size = Vector3(100,100,100) * transform->scale;

  SDL_Rect drawRect = { (int)round(position.x), (int)round(position.y), (int)round(size.x), (int)round(size.y) };

  if(dynamic_cast<const SdlGfxContext*>(gfxContext) != nullptr) {
    SdlGfxContext* sdlGfxContext = dynamic_cast<SdlGfxContext*>(gfxContext);
    SDL_FillRect(
      sdlGfxContext->getScreenSurface(),
      &drawRect,
      SDL_MapRGB( sdlGfxContext->getScreenSurface()->format, 0xFF, 0x00, 0x00 )
    );
  }
}
