#ifndef __vector3_hpp__
#define __vector3_hpp__

// external


// internal


namespace brundolfEngine {
  namespace core {
    namespace util {

      class Vector3 {

      public:
        Vector3();
        Vector3(float x, float y, float z);
        ~Vector3();

        float distanceTo(Vector3 other);

      private:
        float x;
        float y;
        float z;

      };

    }
  }
}

#endif
