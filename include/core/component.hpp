#ifndef __component_hpp__
#define __component_hpp__

// external


// internal


namespace brundolfEngine {
  namespace core {

    class Component {

    public:
      virtual ~Component() { };

      // hooks
      virtual void initialize() = 0;
      virtual void update(int deltaTime, int currentTime) = 0;
      virtual void draw() = 0;

    private:


    };

  }
}

#endif
