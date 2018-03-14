
// external
#include <iostream>

// internal
#include "core/entity.hpp"
#include "core/component.hpp"

using namespace std;
using namespace brundolfEngine::core;

Component::Component() {
}
Component* Component::clone() {
  return new Component(*this);
}
Component::~Component() {
}

void Component::setEntity(Entity* entity) {
  this->entity = entity;
}

template<class C>
C* Component::getComponent() {
 if(this->entity != NULL) {
   return this->entity->getComponent<C>();
 } else {
   return NULL;
 }
}

void Component::initialize() {
}
void Component::update(int deltaTime, int currentTime) {
}
void Component::draw() {
}
