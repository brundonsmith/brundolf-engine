#ifndef __component_hpp__
#define __component_hpp__

// external


// internal


namespace brundolfEngine {
  namespace core {

    class Component {

    public:
      Component();
      ~Component();

      // hooks
      void initialize();
      void update(int timeSinceLastUpdate, int currentTime);

    private:


    };

  }
}

#endif
