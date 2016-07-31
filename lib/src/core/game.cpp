
// external
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

// internal
#include "core/game.hpp"

using namespace brundolfEngine::core;

Game::Game() {
  this->frameRate = 1;
}
Game::~Game() {
}

void Game::load() {
  std::cout << "I loaded!\n";
}
void Game::start() {

  while(true) {
    int millisecondsPerFrame = (int)(1000 * 1/((float)this->frameRate) );
    int currentTime =
        std::chrono::duration_cast< std::chrono::milliseconds >(
          std::chrono::system_clock::now().time_since_epoch()).count();

    update(currentTime - this->timeLastUpdated);
    draw();

    this->timeLastUpdated = currentTime;
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerFrame));
  }

}
void Game::addScene(Scene scene) {
  this->scenes.push_back(scene);
}
void Game::goToScene(int sceneIndex) {
  this->currentSceneIndex = std::max(std::min(sceneIndex, (int)this->scenes.size()), 0);

  if(this->getCurrentScene() && !this->getCurrentScene()->getIsLoaded()) {
    this->getCurrentScene()->load();
  }
}
Scene* Game::getCurrentScene() {
  if(!this->scenes.empty()) {
    return &(this->scenes[this->currentSceneIndex]);
  } else {
    return NULL;
  }
}

void Game::update(int deltaTime) {
  Scene* currentScene = this->getCurrentScene();
  if(currentScene) {
    currentScene->update(deltaTime);
  }
}
void Game::draw() {
  Scene* currentScene = this->getCurrentScene();
  if(currentScene) {
    currentScene->draw();
  }
}
