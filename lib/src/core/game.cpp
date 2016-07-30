
// external
#include <iostream>

// internal
#include "core/game.hpp"

brundolfEngine::core::Game::Game() {
}
brundolfEngine::core::Game::~Game() {
}

void brundolfEngine::core::Game::load() {
  std::cout << "I loaded!\n";
}

void brundolfEngine::core::Game::start() {
  std::cout << "I started!\n";
}
