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
      ~Entity();

    private:
      std::string name;
      std::vector<Component> components;

    };

  }
}

#endif
