
// external

// internal
#include "core/entity.hpp"

using namespace brundolfEngine::core;

Entity::Entity() {
}
Entity::~Entity() {
}

void Entity::update(int deltaTime, int currentTime) {
  for(int i = 0; i < this->components.size(); i++) {
    this->components[i].update(deltaTime, currentTime);
  }
}
void Entity::draw() {
  for(int i = 0; i < this->components.size(); i++) {
    this->components[i].draw();
  }
}
