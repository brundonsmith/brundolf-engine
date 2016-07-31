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
      virtual void update(int timeSinceLastUpdate, int currentTime);
      virtual void draw();

    private:


    };

  }
}

#endif
