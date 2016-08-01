#ifndef __sdl_renderer_hpp__
#define __sdl_renderer_hpp__

// external


// internal
#include "core/util/vector3.hpp"
#include "core/component.hpp"

using namespace brundolfEngine;

namespace brundolfEngine {
  namespace graphicsSdl {
    namespace components {

      class SdlRenderer : public core::Component {
      public:
        SdlRenderer();
        ~SdlRenderer();

        // hooks
        void initialize();
        void update(int deltaTime, int currentTime);
        void draw();

      private:


      };

    }
  }
}

#endif
