
// external
#include <iostream>

// internal
#include "core/components/transform.hpp"
#include "core/components/collider.hpp"
#include "core/components/sphereCollider.hpp"

using namespace brundolfEngine::core::components;
using namespace brundolfEngine::core::util;

bool Collider::areIntersecting(Collider* col1, Collider* col2) {

  if(dynamic_cast<SphereCollider*>(col1) != NULL && dynamic_cast<SphereCollider*>(col2) != NULL) {
    SphereCollider* sphere1 = dynamic_cast<SphereCollider*>(col1);
    SphereCollider* sphere2 = dynamic_cast<SphereCollider*>(col2);
    Transform* transform1 = sphere1->getComponent<Transform>();
    Transform* transform2 = sphere2->getComponent<Transform>();
    Vector3 center1 = transform1->position + sphere1->offset;
    Vector3 center2 = transform2->position + sphere2->offset;

    return center1.getDistanceTo(center2) < sphere1->radius + sphere2->radius;
  } else {
    return false;
  }

}
