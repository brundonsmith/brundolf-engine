#ifndef __entity_hpp__
#define __entity_hpp__

// external
#include <string>
#include <vector>

// internal
#include "component.hpp"

namespace brundolfEngine {
  namespace core {

    class Entity {

    public:
      Entity();
      Entity(const Entity& src);
      Entity& operator=(const Entity& src);
      ~Entity();

      void addComponent(Component* component);

      void update(int deltaTime, int currentTime);
      void draw();

    private:
      std::string name;
      std::vector<Component*> components;

    };

  }
}

#endif
