#ifndef __scene_hpp__
#define __scene_hpp__

// external
#include <string>
#include <vector>

// internal
#include "entity.hpp"

namespace brundolfEngine {
  namespace core {

    class Scene {

    public:
      Scene();
      //Scene(string manifestPath);
      void load();

      void addEntity(Entity entity);

      void update(int deltaTime);
      void draw();

      bool getIsLoaded();

    private:
      void initialize();
      void loadAssets();

      std::string name;
      bool isLoaded;
      int time;

      std::vector<Entity> entities;

    };

  }
}

#endif
