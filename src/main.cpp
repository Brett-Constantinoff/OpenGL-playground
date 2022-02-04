#include "window/window.h"
#include "shaders/shader.h"
#include "objects/objects.h"
#include "camera/camera.h"
#include "scene/scene.h"
#include <random>
#include <iostream>
#define CUBES 10


int main(){
    
   Window window(800, 600, "Playground");
   window.enable3d();

   Shader shader("shaders/shader.shader");
   Scene scene;
    
   for(int i = 0; i < CUBES; i++){
       glm::vec3 color = glm::vec3(((float)rand() / RAND_MAX), ((float)rand() / RAND_MAX), ((float)rand() / RAND_MAX));
       Cube cube("cube" + std::to_string(i), color, "../res/brick.jpeg");
       scene.add(cube);
   }
   
   Camera camera(glm::vec3(0.0f, 0.0f ,3.0f), glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
   glm::vec3 ambient = glm::vec3(0.1f, 0.1f, 0.1f);
   glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
   glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
   glm::vec3 lightPosition = glm::vec3(0.0f, 5.0f, 0.0f);
   glm::vec3 backgroundCol = glm::vec3(0.1f, 0.1f, 0.1f);
   const float lightStr = 2.0f;
   const float n = 2.0f;
   
   while(window.isOpen()){
       glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
       
       camera.move(&window.win);
       scene.setView(&window, &camera);
       window.clearColor(backgroundCol.r, backgroundCol.g, backgroundCol.b, 1.0f);
       window.clearBuffers();
       
       //starts gui frame, all gui calls need to happen after this and before the end call
       window.enableGui();
       //main demo window, each gui window can(not neccessary) have its own scope
       {
        window.startGuiElement("Main Window");
        window.setGuiColor("BackGround Color", &backgroundCol);
        window.displayGuiFloat3("Camera Position", camera.position.x, camera.position.y, camera.position.z);
       }
       //stops gui frame
       window.stopGuiElement();

       shader.use();
       shader.setFloat("lightStr", lightStr);
       shader.setFloat("n", n);
       shader.setVec3("cameraPosition", camera.position);
       shader.setVec3("ambientVal", ambient);
       shader.setVec3("specularVal", specular);
       shader.setVec3("lightCol", lightColor);
       shader.setVec3("lightPos", lightPosition);
       shader.setMat4("projection", scene.projection);
       shader.setMat4("view", scene.view);
    
       for (int i = 0; i < CUBES; i++){
           for(Cube c : scene.getObjects()){
               c.move(position.x, position.y, position.z);
               c.updateNormalMat();
               shader.setVec3("diffuseVal", c.color);
               shader.setMat4("model", c.model);
               shader.setMat4("normalMatrix", c.normalMat);
               c.draw();
               position.x += 2.0f;
           }
           position.z += 2.0f;
           position.x = 0.0f;
       }
       window.renderGui();
       window.swapBuffers();
       window.pollEvents();
   }
   scene.deleteScene();
   window.quitGui();
   window.quit();
}