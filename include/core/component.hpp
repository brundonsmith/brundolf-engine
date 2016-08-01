#ifndef __component_hpp__
#define __component_hpp__

// external


// internal


namespace brundolfEngine {
  namespace core {

    class Component {

    public:
      Component();
      virtual Component* clone();
      virtual ~Component();

      // hooks
      virtual void initialize();
      virtual void update(int deltaTime, int currentTime);
      virtual void draw();

    private:


    };

  }
}

#endif
