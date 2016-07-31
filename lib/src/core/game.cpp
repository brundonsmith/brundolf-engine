
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
    update();
    draw();

    int millisecondsPerFrame = (int)(1000 * 1/((float)this->frameRate) );
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerFrame));
  }
}

void brundolfEngine::core::Game::update() {
  std::cout << "I updated!\n";
}
void brundolfEngine::core::Game::draw() {
  std::cout << "I drew!\n";
}
