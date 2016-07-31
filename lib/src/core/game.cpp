
// external
#include <iostream>
#include <chrono>
#include <thread>

// internal
#include "core/game.hpp"

brundolfEngine::core::Game::Game() {
  this->frameRate = 1;
}
brundolfEngine::core::Game::~Game() {
}

void brundolfEngine::core::Game::load() {
  std::cout << "I loaded!\n";
}
void brundolfEngine::core::Game::start() {

  while(true) {
    int millisecondsPerFrame = (int)(1000 * 1/((float)this->frameRate) );
    float currentTime = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    update(currentTime - this->timeLastUpdated);
    draw();

    this->timeLastUpdated = currentTime;
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerFrame));
  }

}
void brundolfEngine::core::Game::getCurrentScene() {
  return &(this->scenes[this->currentSceneIndex]);
}

void brundolfEngine::core::Game::update() {
  this->getCurrentScene()->update();
}
void brundolfEngine::core::Game::draw() {
  this->getCurrentScene()->draw();
}
