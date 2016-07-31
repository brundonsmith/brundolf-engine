
// external


// internal
#include "core/components/transform.hpp"

using namespace brundolfEngine::core;

components::Transform::Transform() {
  this->position = util::Vector3(0, 0, 0);
  this->scale = util::Vector3(1, 1, 1);
  // rotation
}
/*
void components::Transform::update(int deltaTime, int currentTime) {
}
void components::Transform::draw() {
}
*/
