#ifndef __transform_hpp__
#define __transform_hpp__

// external


// internal
#include "core/util/vector3.hpp"
#include "core/component.hpp"

using namespace brundolfEngine::core;

namespace brundolfEngine {
  namespace core {
    namespace components {

      class Transform : public Component {
      public:
        Transform();

      private:
        util::Vector3 position;
        util::Vector3 scale;
        // quaternion
      };

    }
  }
}

#endif
