#ifndef __game_hpp__
#define __game_hpp__

// external
#include <string>
#include <vector>

// internal
#include "util/color.hpp"
#include "scene.hpp"
#include "gfx_context.hpp"

namespace brundolfEngine {
  namespace core {

    struct GameOptions {
      int RESOLUTION_X;
      int RESOLUTION_Y;
      int FPS;
      std::string TITLE;
      std::string GFX_MODULE;
      brundolfEngine::core::util::Color CLEAR_COLOR;

      GameOptions() {
        RESOLUTION_X = 640;
        RESOLUTION_Y = 480;
        FPS = 60;
        TITLE = "My Game";
        GFX_MODULE = "sdl";
        CLEAR_COLOR = brundolfEngine::core::util::Color();
      }
    };

    class Game {

      // Singleton
      public: static Game* getInstance();
      private: static Game* instance;


    public:
      Game();
      Game(GameOptions options);
      ~Game();
      void start();

      void addScene(Scene scene);
      void goToScene(int sceneIndex);
      Scene* getCurrentScene();

      GameOptions getOptions();
      GfxContext* getGfxContext();

    private:
      void initialize();
      void loadAssets();

      void update(int deltaTime);
      void draw();

      std::vector<Scene> scenes;
      int currentSceneIndex;
      int timeLastUpdated;

      GameOptions options;
      GfxContext* gfxContext;
    };

  }
}

#endif
