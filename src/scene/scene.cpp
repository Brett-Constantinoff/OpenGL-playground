#include "scene.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Scene::add(SceneObject object){
    this->objects.push_back(object);
};

std::vector<SceneObject> Scene::getObjects(void){
    return this->objects;
};

void Scene::setView(Window *win, Camera *cam){
     this->projection = glm::perspective(glm::radians(45.0f), (float)(*win).height/ (float)(*win).width, 1.0f, 100.0f); //creates perspective viewing
     this->view = glm::lookAt(cam->position, cam->position + cam->front, cam->up);
};

void Scene::deleteScene(void){
    for(SceneObject object : this->objects){
        object.deleteRes();
    }
};

void Scene::setUp(void){
    for(int i = 0; i < OBJECTS; i++){
       glm::vec3 color = glm::vec3(((float)rand() / RAND_MAX), ((float)rand() / RAND_MAX), ((float)rand() / RAND_MAX));
       Cube cube("cube" + std::to_string(i), color, "../res/brick.jpeg");
       Pyramid pyramid("pyramid" + std::to_string(i), color, "../res/rock.jpeg");
       Octahedron octahedron("octahedron" + std::to_string(i), color, "../res/wood.jpeg");
       this->add(cube);
       this->add(pyramid);
       this->add(octahedron);
   }
};

void Scene::render(Shader* shader){
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    for (int i = 0; i < OBJECTS; i++){
           for(SceneObject object : this->getObjects()){
               object.move(position.x, position.y, position.z);
               object.updateNormalMat();
               shader->setVec3("diffuseVal", object.color);
               shader->setMat4("model", object.model);
               shader->setMat4("normalMatrix", object.normalMat);
               object.draw();
               position.x += 2.0f;
           }
           position.z += 2.0f;
           position.x = 0.0f;
       }
};