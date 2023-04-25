#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "objects/Circle.h"
#include "core/Simple2DScene.h"

class ImpulseScene : public Simple2DScene {
public:
    ImpulseScene();
    ~ImpulseScene();

    virtual void onEnable() override;
    virtual void onDisable() override;
    virtual void update(float deltaTime) override;
    virtual void draw() override;
    virtual void drawGUI() override;

    virtual const char* getName() override { return "Impulse Scene"; }

private:
    glm::vec2 circlePosition;
  

    glm::vec2 circleVelocity = glm::vec2(0);
    glm::vec2 circleAcceleration = glm::vec2(0, -9.81f);
    float circleSpeed =0;

    float groundY = 0;


    Circle mainCircle;
    std::vector<Circle> trajectoryCircles;
    glm::vec2 gravity = glm::vec2(0, -9.81f);

     int numberOfCircles = 10;
    float radius = 2;
    float velocityMultiplier = 1;
    float circleRadius = 1;
    float timeInterval = 0.1f;
    glm::vec2 MouseStartPosition;
    glm::vec2 MouseCurrentPosition;
    glm::vec2 MouseImpulseVector;
    bool MouseClicked = false;


    int NumberoftrajectoryCircles = 20;
};