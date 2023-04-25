#include "ImpulseScene.h"

#include "core/Draw.h"
#include "imgui.h"
#include "SDL_stdinc.h"


ImpulseScene::ImpulseScene() {
    mainCircle = Circle(glm::vec2(0, 0), glm::vec2(0, 0), gravity, 1, 1);

 
}

void ImpulseScene::onEnable() {


    

    for (int i = 0; i <= NumberoftrajectoryCircles; i++) {
        trajectoryCircles.push_back(
            Circle(glm::vec2(0, 0), glm::vec2(0, 0), gravity, 1, 1));
    }

}

void ImpulseScene::onDisable() {}

void ImpulseScene::update(float deltaTime) {


    mainCircle.update(deltaTime);

    MouseCurrentPosition = Input::getMousePos();

    if (Input::isMouseDown(0) && !MouseClicked)  {

        if (glm::length(MouseCurrentPosition - mainCircle.position) <= mainCircle.radius){
                MouseClicked = true;
                MouseStartPosition = Input::getMousePos();
        }
    }
    
    if (MouseClicked) {
        MouseImpulseVector = Input::getMousePos() - MouseStartPosition;


          glm::vec2 firstAcc = (mainCircle.acceleration * timeInterval * timeInterval) / 2.0f;
          glm::vec2 firstvel = (-MouseImpulseVector * timeInterval);
          glm::vec2 firstpos = mainCircle.position + firstvel + firstAcc;

          trajectoryCircles[0].position = firstpos;
          trajectoryCircles[0].velocity = firstvel;
          trajectoryCircles[0].acceleration = firstAcc;


        for (int i = 1; i <= NumberoftrajectoryCircles; i++) {
           
           float timeValue = timeInterval * i;
            glm::vec2 temppos =  mainCircle.position + (-MouseImpulseVector * timeValue) +
                (mainCircle.acceleration * timeValue * timeValue) / 2.0f;
            trajectoryCircles[i].position = temppos;

           /*
            glm::vec2 tempAcc = trajectoryCircles[i-1].acceleration;
           glm::vec2 tempVel = trajectoryCircles[i - 1].velocity +
                               trajectoryCircles[i - 1].acceleration * timeInterval;
           
           glm::vec2 tempPosition = trajectoryCircles[i - 1].position + tempVel * timeInterval + tempAcc;

           trajectoryCircles[i].position = tempPosition;
           trajectoryCircles[i].velocity = tempVel;
          // trajectoryCircles[i].acceleration = tempVel;
           
           if (trajectoryCircles[i].position.y - trajectoryCircles[i].position.y < groundY) {
               trajectoryCircles[i].position.y = groundY + trajectoryCircles[i].position.y;
               trajectoryCircles[i].velocity.y *= -1;
           
           }

           */
          
           
           




         }

        for (auto& circle : trajectoryCircles) {
             circle.velocity = glm::vec2(0, 0);
             circle.acceleration = glm::vec2(0, 0);
            circle.update(deltaTime);
        }

    }
    
    if (Input::isMouseReleased(0) && MouseClicked) {
        MouseClicked = false;
        mainCircle.velocity -= MouseImpulseVector;
    }

    if (mainCircle.position.y - mainCircle.radius < groundY) {
        mainCircle.position.y = groundY + mainCircle.radius;
        mainCircle.velocity.y *= -1;
    }



    circleSpeed = glm::length(mainCircle.velocity);
}

void ImpulseScene::draw() {
    //Draw::circle(circlePosition, circleRadius);
    Draw::line(glm::vec2(-50, groundY), glm::vec2(50, groundY));


    //Draw::setColor()
    Draw::arrow(mainCircle.position, mainCircle.position - MouseImpulseVector);
    

     
        for (auto& circle : trajectoryCircles) {
            circle.draw();
        }

         mainCircle.draw();


    

    
    Draw::arrow(mainCircle.position,  mainCircle.position + mainCircle.velocity);


}

void ImpulseScene::drawGUI() {
    ImGui::Begin("Inspector");
    ImGui::DragFloat2("Circle Position", &mainCircle.position[0], 0.1f);
    ImGui::DragFloat2("Circle Velocity", &mainCircle.velocity[0], 0.1f);
    ImGui::DragFloat2("Circle Acceleration", &mainCircle.acceleration[0], 0.1f);
    ImGui::DragFloat("Circle Radius", &mainCircle.radius, 0.1f);
    ImGui::DragFloat("Circle Speed", &circleSpeed, 0.1f);



    if (ImGui::Button("Reset")) {
        mainCircle.velocity = glm::vec2(0);
        mainCircle.acceleration = glm::vec2(0, -9.81);
    }


    ImGui::DragFloat2("Mouse Position", &MouseCurrentPosition[0], 0.1f);
    ImGui::DragFloat2("Mouse Clicked Position", &MouseStartPosition[0], 0.1f);
    ImGui::DragFloat2("Mouse Vector", &MouseImpulseVector[0], 0.1f);
    ImGui::End();





}