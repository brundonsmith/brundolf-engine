#ifndef __sphere_collider_hpp__
#define __sphere_collider_hpp__

// external


// internal
#include "core/util/vector3.hpp"
#include "core/components/collider.hpp"

namespace brundolfEngine {
  namespace core {
    namespace components {

      class SphereCollider : public brundolfEngine::core::components::Collider {
      public:
        SphereCollider();
        SphereCollider* clone();
        ~SphereCollider();

        bool intersectsWith(Collider* other);

        util::Vector3 offset;
        float radius;

      private:

      };
    }
  }
}

#endif
