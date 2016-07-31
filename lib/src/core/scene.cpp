
// external


// internal
#include "core/scene.hpp"

using namespace brundolfEngine::core;

void Scene::update(int deltaTime) {
  this->time += deltaTime;

  for(int i = 0; i < this->entities.size(); i++) {
    this->entities[i].update(deltaTime, this->time);
  }
}
void Scene::draw() {
  for(int i = 0; i < this->entities.size(); i++) {
    this->entities[i].draw();
  }
}
