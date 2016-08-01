#ifndef __sdl_gfx_context_hpp__
#define __sdl_gfx_context_hpp__

// external
#include "sdl/SDL.h"

// internal
#include "core/gfx_context.hpp"

namespace brundolfEngine {
  namespace graphicsSdl {

    class SdlGfxContext : public brundolfEngine::core::GfxContext {
    public:
      SdlGfxContext();
      ~SdlGfxContext();

      // hooks
      void initialize();
      void refresh();
      void quit();

      // specific to this gfx context
      SDL_Window* getWindow();
      SDL_Surface* getScreenSurface();

    private:
      SDL_Window* window;
      SDL_Surface* screenSurface;

    };

  }
}

#endif
