#ifndef __scene_hpp__
#define __scene_hpp__

// external
#include <string>

// internal
#include "entity.hpp"

namespace brundolfEngine {
  namespace core {

    class Scene {

    public:
      Scene();
      //Scene(string manifestPath);
      void load();
      void play();
      void pause();

      bool getIsLoaded();

    private:
      void initialize();
      void loadAssets();

      std::string name;
      bool isLoaded;
      int time;


    };

  }
}

#endif
