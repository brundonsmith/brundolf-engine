
// external
#include <iostream>

// internal
#include "core/components/transform.hpp"

using namespace std;
using namespace brundolfEngine::core::util;
using namespace brundolfEngine::core::components;

Transform::Transform() {
  this->position = Vector3(0, 0, 0);
  this->scale = Vector3(1, 1, 1);
  // rotation
}
Transform* Transform::clone() {
  return new Transform(*this);
}
