
// external
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

// internal
#include "core/game.hpp"
#include "core/gfx_context.hpp"
#include "graphics_sdl/sdl_gfx_context.hpp"

using namespace brundolfEngine::core;


// Singleton
Game* Game::instance = NULL;
Game* Game::getInstance() {
  return Game::instance;
}



Game::Game() {
  if(!Game::instance) {
    Game::instance = this;
  }
}
Game::Game(GameOptions options) {
  if(!Game::instance) {
    Game::instance = this;
  }

  this->options = options;
}
Game::~Game() {
  this->gfxContext->quit();
  delete this->gfxContext;
}

void Game::start() {

  this->initialize();

  this->loadAssets();

  //while(true) {
    int currentTime =
        std::chrono::duration_cast< std::chrono::milliseconds >(
          std::chrono::system_clock::now().time_since_epoch()).count();

    update(currentTime - this->timeLastUpdated);
    draw();

    this->timeLastUpdated = currentTime;

    if(this->options.FPS > 0) {
      int millisecondsPerFrame = (int)(1000 * 1/((float)this->options.FPS) );
      std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerFrame));
    }
  //}

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

GameOptions Game::getOptions() {
  return this->options;
}
GfxContext* Game::getGfxContext() {
  return this->gfxContext;
}

void Game::initialize() {
  if("sdl" == this->options.GFX_MODULE) {
    this->gfxContext = new brundolfEngine::graphicsSdl::SdlGfxContext();
  }

  this->gfxContext->initialize();
}
void Game::loadAssets() {
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
  this->getGfxContext()->refresh();
}
