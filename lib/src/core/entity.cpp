
// external
#include <iostream>
#include <map>

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
  for (map<const char*, Component*>::const_iterator it = src.components.begin(); it != src.components.end(); it++) {
    this->components[it->first] = it->second->clone();
  }

  return *this;
}
Entity::~Entity() {
  for (map<const char*, Component*>::iterator it = this->components.begin(); it != this->components.end(); it++) {
    delete it->second;
  }
}

void Entity::addComponent(Component* component) {
  if(this->components.find(typeid(*component).name()) != this->components.end()) {
    this->components[typeid(*component).name()]->setEntity(NULL);
  }

  component->setEntity(this);
  this->components[typeid(*component).name()] = component->clone();
}

void Entity::update(int deltaTime, int currentTime) {
  for (map<const char*, Component*>::iterator it = this->components.begin(); it != this->components.end(); it++) {
    it->second->update(deltaTime, currentTime);
  }
}
void Entity::draw() {
  for (map<const char*, Component*>::iterator it = this->components.begin(); it != this->components.end(); it++) {
    it->second->draw();
  }
}
