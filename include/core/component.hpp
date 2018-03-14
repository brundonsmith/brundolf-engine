#ifndef __component_hpp__
#define __component_hpp__

// external


// internal


namespace brundolfEngine {
  namespace core {

    class Entity;

    class Component {

    public:
      Component();
      virtual Component* clone();
      virtual ~Component();

      void setEntity(Entity* entity);

      template<class C>
      C* getComponent();

      // hooks
      virtual void initialize();
      virtual void update(int deltaTime, int currentTime);
      virtual void draw();

    protected:
      Entity* entity;

    };

  }
}

#endif
