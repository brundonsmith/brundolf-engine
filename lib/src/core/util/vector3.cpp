
// external
#include <cmath>

// internal
#include "core/util/vector3.hpp"

using namespace brundolfEngine::core::util;

Vector3::Vector3() {
  this->x = 0;
  this->y = 0;
  this->z = 0;
}
Vector3::Vector3(float x, float y, float z) {
  this->x = z;
  this->y = y;
  this->z = z;
}

float Vector3::getLength() {
  return this->getDistanceTo( Vector3(0,0,0) );
}
float Vector3::getDistanceTo(Vector3 other) {
  float diffX = this->x - other.x;
  float diffY = this->y - other.y;
  float diffZ = this->z - other.z;

  return sqrt( pow(diffX, 2) + pow(diffY, 2) + pow(diffZ, 2) );
}
Vector3 Vector3::getNormalized() {
  float normX = this->x;
  float normY = this->y;
  float normZ = this->z;

  float length = this->getLength();

  normX *= 1.0 / length;
  normY *= 1.0 / length;
  normZ *= 1.0 / length;

  return Vector3(normX, normY, normZ);
}


Vector3 Vector3::operator+(Vector3 other) {
  float newX = this->x;
  float newY = this->y;
  float newZ = this->z;

  newX += other.x;
  newY += other.y;
  newZ += other.z;

  return Vector3(newX, newY, newZ);
}
Vector3 Vector3::operator-(Vector3 other) {
  float newX = this->x;
  float newY = this->y;
  float newZ = this->z;

  newX -= other.x;
  newY -= other.y;
  newZ -= other.z;

  return Vector3(newX, newY, newZ);
}
Vector3 Vector3::operator*(float scale) {
  float newX = this->x;
  float newY = this->y;
  float newZ = this->z;

  newX *= scale;
  newY *= scale;
  newZ *= scale;

  return Vector3(newX, newY, newZ);
}
Vector3 Vector3::operator/(float scale) {
  float newX = this->x;
  float newY = this->y;
  float newZ = this->z;

  newX /= scale;
  newY /= scale;
  newZ /= scale;

  return Vector3(newX, newY, newZ);
}
