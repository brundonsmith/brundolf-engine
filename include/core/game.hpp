#ifndef __game_hpp__
#define __game_hpp__

// external
#include <string>
#include <vector>

// internal
#include "scene.hpp"

namespace brundolfEngine {
  namespace core {

    class Game {

    public:
      Game();
      //Game(string manifestPath);
      ~Game();
      void load();
      void start();

      void addScene(Scene scene);
      void goToScene(int sceneIndex);
      Scene* getCurrentScene();

    private:
      void initialize();
      void loadAssets();

      void update(int deltaTime);
      void draw();


      std::string title;
      std::vector<Scene> scenes;
      int currentSceneIndex;

      int frameRate;
      int timeLastUpdated;

    };

  }
}

#endif
