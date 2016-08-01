#ifndef __transform_hpp__
#define __transform_hpp__

// external


// internal
#include "core/util/vector3.hpp"
#include "core/component.hpp"

namespace brundolfEngine {
  namespace core {
    namespace components {

      class Transform : public brundolfEngine::core::Component {
      public:
        Transform();

      private:
        brundolfEngine::core::util::Vector3 position;
        brundolfEngine::core::util::Vector3 scale;
        // quaternion
      };

    }
  }
}

#endif
