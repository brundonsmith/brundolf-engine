#ifndef __sdl_renderer_hpp__
#define __sdl_renderer_hpp__

// external


// internal
#include "core/util/vector3.hpp"
#include "core/component.hpp"

namespace brundolfEngine {
  namespace graphicsSdl {
    namespace components {

      class SdlRenderer : public brundolfEngine::core::Component {
      public:
        SdlRenderer();
        SdlRenderer* clone();
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
