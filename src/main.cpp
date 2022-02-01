#include "window/window.h"
#include "shaders/shader.h"
#include "objects/objects.h"
#include "camera/camera.h"
#include "scene/scene.h"
#define CUBES 5


int main(){
    
   Window window(800, 600, "Hello World");
   window.setViewPort(0, 0);
   window.enable3d();

   Shader shader("shaders/shader.shader");
   Scene scene;
    
   for(int i = 0; i < CUBES; i++){
       Cube cube("cube" + std::to_string(i));
       scene.add(cube);
   }
   
   Camera camera(glm::vec3(0.0f, 0.0f ,3.0f), glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
   
   while(window.isOpen()){
       glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);

       window.clearColor(1.0f, 1.0f, 1.0f, 1.0f);
       window.clearBuffers();

       camera.move(&window.win);
       scene.setView(&window, &camera);

       shader.use();
       shader.setMat4("projection", scene.projection);
       shader.setMat4("view", scene.view);

       for (int i = 0; i < CUBES; i++){
           for(Cube c : scene.getObjects()){
               c.move(position.x, position.y, position.z);
               shader.setMat4("model", c.model);
               c.draw();
               position.x += 1.0f;
           }
           position.z += 1.0f;
           position.x = 0.0f;
       }

       window.swapBuffers();
       window.pollEvents();
   }

   window.quit();
}