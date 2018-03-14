
// external
#include <iostream>

// internal
#include "core/components/transform.hpp"
#include "core/components/sphereCollider.hpp"

using namespace std;
using namespace brundolfEngine::core::util;
using namespace brundolfEngine::core::components;

SphereCollider::SphereCollider() {
}
SphereCollider* SphereCollider::clone() {
  return new SphereCollider(*this);
}
SphereCollider::~SphereCollider() {
}

bool SphereCollider::intersectsWith(Collider* other) {
  return Collider::areIntersecting(this, other);
}

/*
void SphereCollider::initialize() {

}
void SphereCollider::update(int deltaTime, int currentTime) {

}
void SphereCollider::draw() {

}
*/
