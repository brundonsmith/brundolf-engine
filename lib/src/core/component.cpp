
// external
#include <iostream>

// internal
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

void Component::initialize() {
}
void Component::update(int deltaTime, int currentTime) {
}
void Component::draw() {
}
