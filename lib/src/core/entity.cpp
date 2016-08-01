
// external
#include <iostream>

// internal
#include "core/entity.hpp"

using namespace std;
using namespace brundolfEngine::core;

Entity::Entity() {
}
Entity::Entity(const Entity& src) {
  *this = src;
}
Entity& Entity::operator=(const Entity& src) {
  this->name = src.name;
  for(int i = 0; i < src.components.size(); i++) {
    this->components.push_back(src.components[i]->clone());
  }

  return *this;
}
Entity::~Entity() {
  for(int i = 0; i < this->components.size(); i++) {
    delete this->components[i];
  }
}

void Entity::addComponent(Component* component) {
  this->components.push_back(component->clone());
}

void Entity::update(int deltaTime, int currentTime) {
  for(int i = 0; i < this->components.size(); i++) {
    this->components[i]->update(deltaTime, currentTime);
  }
}
void Entity::draw() {
  for(int i = 0; i < this->components.size(); i++) {
    this->components[i]->draw();
  }
}
