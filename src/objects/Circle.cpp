#include "Circle.h"

#include "core/Draw.h"

Circle::Circle(const glm::vec2& position,
               const glm::vec2& velocity,
               const glm::vec2& acceleration,
               float radius,
               float mass)
    : position(position),
      velocity(velocity),
      acceleration(acceleration),
      radius(radius) {
    if (mass == 0) {
        inverseMass = 0;
    } else {
        inverseMass = 1.f / mass;
    }
}

Circle::Circle() {

    position = glm::vec2(0, 0);
    velocity = glm::vec2(0, 0);
    acceleration = glm::vec2(0, 0);
    inverseMass = 1.f/1.f;
    radius = 1;
}

void Circle::draw() {
    Draw::circle(position, radius);
}

void Circle::update(float deltaTime) {
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
}
