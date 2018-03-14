
// external
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

// internal
#include "core/game.hpp"
#include "core/gfx_context.hpp"
#include "graphics_sdl/sdl_gfx_context.hpp"

using namespace std;
using namespace std::chrono;
using namespace brundolfEngine::core;
using namespace brundolfEngine::graphicsSdl;


// Singleton
Game* Game::instance = NULL;
Game* Game::getInstance() {
  return Game::instance;
}



Game::Game() {
  if(!Game::instance) {
    Game::instance = this;
  }

  this->currentSceneIndex = 0;
  this->timeLastUpdated = 0;
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

  this->timeLastUpdated = duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();

  // FOR TESTING: run for a limited amount of time
  int lifetimeInSeconds = 4;
  for(int creationTime = this->timeLastUpdated; this->timeLastUpdated - creationTime < lifetimeInSeconds * 1000;) {
  //while(true) {
    int currentTime =
        duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();

    draw();
    update(currentTime - this->timeLastUpdated);

    this->timeLastUpdated = currentTime;

    if(this->options.FPS > 0) {
      int millisecondsPerFrame = (int)(1000 * 1/((float)this->options.FPS) );
      this_thread::sleep_for(milliseconds(millisecondsPerFrame));
    }
  }

}
void Game::addScene(Scene scene) {
  this->scenes.push_back(scene);
}
void Game::goToScene(int sceneIndex) {
  this->currentSceneIndex = max(min(sceneIndex, (int)this->scenes.size()), 0);

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
    this->gfxContext = new SdlGfxContext();
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
