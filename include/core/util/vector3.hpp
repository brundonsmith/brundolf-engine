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

        float getLength();
        float getDistanceTo(Vector3 other);
        Vector3 getNormalized();

        Vector3 operator+(Vector3 other);
        Vector3 operator-(Vector3 other);
        Vector3 operator*(Vector3 other);
        Vector3 operator/(Vector3 other);
        Vector3 operator*(float scale);
        Vector3 operator/(float scale);

        float x;
        float y;
        float z;
      };

    }
  }
}

#endif
