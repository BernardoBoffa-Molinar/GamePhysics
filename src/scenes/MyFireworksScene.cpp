#include "TestScene.h"

#include "core/Draw.h"
#include "imgui.h"
#include "MyFireworksScene.h"


MyFireworksScene::MyFireworksScene()
    : 
    circleVelocity(10,5), circlePosition(0, 1), circleRadius(1),
    groundLine(0),GravityForce(-5),fireworksActive(false),
      BoxTopR(10, 10),
      BoxTopL(-10, 10),
      BoxBotR(10, 0),
      BoxBotL(-10, 0),
      fireworkVelocity(6),
      fireworkGravity(6),
     
      timer(0)
    {

    balls = std::vector<Ball>(3);
    fireworksballs = std::vector<Ball>(8);
    


    balls[0].BallPosition = glm::vec2(5, 2);
    balls[0].BallVelocity = glm::vec2(5, 2);
    balls[0].BallRadius = 1;
    balls[1].BallPosition = glm::vec2(5, 2);
    balls[1].BallVelocity = glm::vec2(5, 2);
    balls[1].BallRadius = 2;
    balls[2].BallPosition = glm::vec2(5, 2);
    balls[2].BallVelocity = glm::vec2(5, 2);
    balls[2].BallRadius = 3;



    fireworksballs[0].BallVelocity = glm::vec2(-1 ,-1);
    fireworksballs[1].BallVelocity = glm::vec2( 0,-1);
    fireworksballs[2].BallVelocity = glm::vec2( 1,-1);
    fireworksballs[3].BallVelocity = glm::vec2( 0, 1);
    fireworksballs[4].BallVelocity = glm::vec2(-1, 0);
    fireworksballs[5].BallVelocity = glm::vec2(-1, 1);
    fireworksballs[6].BallVelocity = glm::vec2( 1, 0);
    fireworksballs[7].BallVelocity = glm::vec2( 1, 1);
    
    
     for (int i = 0; i < fireworksballs.size(); i++) {
        
         fireworksballs[i].BallVelocity =
             glm::vec2(fireworkVelocity * fireworksballs[i].BallVelocity.x,
                       fireworkVelocity + fireworkVelocity *fireworksballs[i].BallVelocity.y);

         fireworksballs[i].BallPosition = glm::vec2(0, 20);
         fireworksballs[i].BallRadius = 0.5;
         fireworksballs[i].BallAceleration = glm::vec2(0, fireworkGravity * 2.5);

     }



}

MyFireworksScene::~MyFireworksScene() {}

void MyFireworksScene::onEnable() {}

void MyFireworksScene::onDisable() {}



/*
* 
    if (circlePosition.y - circleRadius < BoxBotL.y) {
        circlePosition.y = BoxBotL.y + circleRadius;
        circleVelocity.y = circleVelocity.y * -1;
    }
    if (circlePosition.y + circleRadius > BoxTopR.y) {
        circlePosition.y = BoxTopR.y - circleRadius;
        circleVelocity.y = circleVelocity.y * -1;
    }

    // colission Horizontal
    if (circlePosition.x - circleRadius < BoxBotL.x) {
        circlePosition.x = BoxBotL.x + circleRadius;
        circleVelocity.x = circleVelocity.x * -1;
    }
    if (circlePosition.x + circleRadius > BoxTopR.x) {
        circlePosition.x = BoxTopR.x - circleRadius;
        circleVelocity.x = circleVelocity.x * -1;
    }

    circlePosition.y += deltaTime * circleVelocity.y;
    circlePosition.x += deltaTime * circleVelocity.x;
*/


void MyFireworksScene::update(float deltaTime) {

    for (int i = 0; i < balls.size(); i++) {
        if (balls[i].BallPosition.y - balls[i].BallRadius < BoxBotL.y) {
            balls[i].BallPosition.y = BoxBotL.y + balls[i].BallRadius;
            balls[i].BallVelocity.y = balls[i].BallVelocity.y * -1;
        }
        if (balls[i].BallPosition.y + balls[i].BallRadius > BoxTopR.y) {
            balls[i].BallPosition.y = BoxTopR.y - balls[i].BallRadius;
            balls[i].BallVelocity.y = balls[i].BallVelocity.y * -1;
        }

        if (balls[i].BallPosition.x - balls[i].BallRadius < BoxBotL.x) {
            balls[i].BallPosition.x = BoxBotL.x + balls[i].BallRadius;
            balls[i].BallVelocity.x = balls[i].BallVelocity.x * -1;
        }
        if (balls[i].BallPosition.x + balls[i].BallRadius > BoxTopR.x) {
            balls[i].BallPosition.x = BoxTopR.x - balls[i].BallRadius;
            balls[i].BallVelocity.x = balls[i].BallVelocity.x * -1;
        }

        balls[i].BallPosition.y += deltaTime * balls[i].BallVelocity.y;
        balls[i].BallPosition.x += deltaTime * balls[i].BallVelocity.x;
    }

    if (fireworksActive) {
        timer += deltaTime;
        if (timer > 3) {
            fireworksActive = false;
            timer = 0;
        } 

        for (int i = 0; i < fireworksballs.size(); i++) {
            fireworksballs[i].BallVelocity.y += deltaTime * fireworksballs[i].BallAceleration.y;

            fireworksballs[i].BallPosition.y += deltaTime * fireworksballs[i].BallVelocity.y;
            fireworksballs[i].BallPosition.x += deltaTime * fireworksballs[i].BallVelocity.x;
            fireworksballs[i].BallRadius = 0.5 + 3 - timer; // 3 -timer;
        }
   
     

    }
   

    if (circlePosition.y - circleRadius < BoxBotL.y) {
        circlePosition.y = BoxBotL.y + circleRadius;
        circleVelocity.y = circleVelocity.y * -1;
    }
    if (circlePosition.y + circleRadius > BoxTopR.y) {
        circlePosition.y = BoxTopR.y - circleRadius;
        circleVelocity.y = circleVelocity.y * -1;
    }

    // colission Horizontal
    if (circlePosition.x - circleRadius < BoxBotL.x) {
        circlePosition.x = BoxBotL.x + circleRadius;
        circleVelocity.x = circleVelocity.x * -1;
    }
    if (circlePosition.x + circleRadius > BoxTopR.x) {
        circlePosition.x = BoxTopR.x - circleRadius;
        circleVelocity.x = circleVelocity.x * -1;
    }

    circlePosition.y += deltaTime * circleVelocity.y ;
    circlePosition.x += deltaTime * circleVelocity.x;
  


    
    }



void MyFireworksScene::draw() {

    for (int i = 0; i < balls.size(); i++) {
        Draw::circle(balls[i].BallPosition, balls[i].BallRadius);
    }

    if (fireworksActive) {
        for (int i = 0; i < fireworksballs.size(); i++) {
            Draw::circle(fireworksballs[i].BallPosition,
                         fireworksballs[i].BallRadius);
        }
    }
   


    Draw::circle(circlePosition, circleRadius);
    Draw::line(glm::vec2(-5, 0), glm::vec2(5, 0));
    Draw::aabb(BoxBotL, BoxTopR);
}

void MyFireworksScene::drawGUI() {
    ImGui::Begin("Inspector");
    ImGui::DragFloat2("Circle Position", &circlePosition[0], 0.1f);
    ImGui::DragFloat2("Circle Velocity", &circleVelocity[0], 0.1f);
    ImGui::DragFloat("Circle Radius", &circleRadius, 0.1f);
    ImGui::End();

    /*
    
      ImGui::Begin("Balls");
    for (int i = 0; i < balls.size(); i++) {
        ImGui::DragFloat2("Circle Position", &balls[i].BallPosition[0], 0.1f);
        ImGui::DragFloat2("Circle Velocity", &balls[i].BallVelocity[0], 0.1f);
        ImGui::DragFloat("Circle Radius", &balls[i].BallRadius, 0.1f);
    }

    */
  

    ImGui::Begin("FireWorks");
    ImGui::DragFloat("Fireworks velocity", &fireworkVelocity, 0.1f);
    ImGui::DragFloat("Fireworks Gravity", &fireworkGravity, 0.1f);

    //ImGui::Begin("Mouse");
    //glm::vec2 pos = glm::vec2(ImGui::GetMousePos().x, ImGui::GetMousePos().y);
   // ImGui::DragFloat2("Mouse Position", &pos[0], 0.1f);
                          
    //if (ImGui::IsMouseDown(ImGuiMouseButton_Left)){
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)){
        fireworksActive = true;
        timer = 0;
        fireworksballs[0].BallVelocity = glm::vec2(-1, -1);
        fireworksballs[1].BallVelocity = glm::vec2(0, -1);
        fireworksballs[2].BallVelocity = glm::vec2(1, -1);
        fireworksballs[3].BallVelocity = glm::vec2(0, 1);
        fireworksballs[4].BallVelocity = glm::vec2(-1, 0);
        fireworksballs[5].BallVelocity = glm::vec2(-1, 1);
        fireworksballs[6].BallVelocity = glm::vec2(1, 0);
        fireworksballs[7].BallVelocity = glm::vec2(1, 1);

        for (int i = 0; i < fireworksballs.size(); i++) {

             fireworksballs[i].BallAceleration =
                glm::vec2(0, -1* abs(fireworkGravity * 2));
            fireworksballs[i].BallPosition = glm::vec2(0, 20);
            fireworksballs[i].BallVelocity = glm::vec2(fireworkVelocity * fireworksballs[i].BallVelocity.x,
                          fireworkVelocity*2 + fireworkVelocity *  fireworksballs[i].BallVelocity.y);
            fireworksballs[i].BallRadius = 0.5;
        }
    }


    ImGui::End();
}


