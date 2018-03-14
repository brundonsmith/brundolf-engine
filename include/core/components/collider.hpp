#ifndef __collider_hpp__
#define __collider_hpp__

// external


// internal
#include "core/util/vector3.hpp"
#include "core/component.hpp"

namespace brundolfEngine {
  namespace core {
    namespace components {

      class Collider : public brundolfEngine::core::Component {
      public:
        Collider();
        virtual Collider* clone();
        virtual ~Collider() { };

        virtual bool intersectsWith(Collider* other);

        static bool areIntersecting(Collider* col1, Collider* col2);
      };

    }
  }
}

#endif
