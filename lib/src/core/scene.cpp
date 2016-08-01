
// external
#include <iostream>

// internal
#include "core/scene.hpp"

using namespace std;
using namespace brundolfEngine::core;

Scene::Scene() {
  this->isLoaded = false;
}
void Scene::load() {
  this->isLoaded = true;
}

void Scene::addEntity(Entity entity) {
  this->entities.push_back(entity);
}

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

bool Scene::getIsLoaded() {
  return this->isLoaded;
}
