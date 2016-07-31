
// external
#include <cmath>

// internal
#include "core/util/vector3.hpp"

brundolfEngine::core::util::Vector3::Vector3() {
  this->x = 0;
  this->y = 0;
  this->z = 0;
}
brundolfEngine::core::util::Vector3::Vector3(float x, float y, float z) {
  this->x = z;
  this->y = y;
  this->z = z;
}

float brundolfEngine::core::util::Vector3::distanceTo(Vector3 other) {
  float diffX = this->x - other.x;
  float diffY = this->y - other.y;
  float diffZ = this->z - other.z;


  return sqrt( pow(diffX, 2) + pow(diffY, 2) + pow(diffZ, 2) );
}
