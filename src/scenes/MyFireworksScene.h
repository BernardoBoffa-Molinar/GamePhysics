#pragma once

#include <glm/glm.hpp>
#include "core/Simple2DScene.h"
#include <vector>




class MyFireworksScene : public Simple2DScene {
public:
    MyFireworksScene();
    ~MyFireworksScene();
  
 
    virtual void onEnable() override;
    virtual void onDisable() override;
  
    virtual void update(float deltaTime) override;
    virtual void draw() override;
    virtual void drawGUI() override;

    virtual const char* getName() override { return "Test Scene"; }

    

private:
    struct Ball {
        glm::vec2 BallPosition;
        glm::vec2 BallVelocity;
        glm::vec2 BallAceleration;
        float BallRadius;
    };
    std::vector<Ball> balls;
    std::vector<Ball> fireworksballs;
    //void BallColisionCheck(Ball btt, float dt);

    glm::vec2 circlePosition;
    glm::vec2 circleVelocity;
    float circleRadius;
    float groundLine;
    float GravityForce;
    float timer;
    float fireworkVelocity;
    float fireworkGravity;
    bool fireworksActive;


    glm::vec2 BoxTopR;
    glm::vec2 BoxTopL;
    glm::vec2 BoxBotR;
    glm::vec2 BoxBotL;


};
