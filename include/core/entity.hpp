#ifndef __entity_hpp__
#define __entity_hpp__

// external
#include <iostream>
#include <string>
#include <map>

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

      template<class C>
      C* getComponent() {
        if(this->components.find(typeid(C).name()) != this->components.end()) {
          return (C*)(this->components[typeid(C).name()]);
        } else {
          return NULL;
        }
      }

      void update(int deltaTime, int currentTime);
      void draw();

    //private:
      std::string name;
      std::map<const char*, Component*> components;

    };

  }
}

#endif
