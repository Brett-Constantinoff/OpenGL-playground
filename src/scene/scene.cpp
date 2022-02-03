#include "scene.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Scene::add(Cube c){
    this->objects.push_back(c);
};

std::vector<Cube> Scene::getObjects(void){
    return this->objects;
};

void Scene::setView(Window *win, Camera *cam){
     this->projection = glm::perspective(glm::radians(45.0f), (float)win->getHeight() / (float)win->getWidth(), 1.0f, 100.0f); //creates perspective viewing
     this->view = glm::lookAt(cam->position, cam->position + cam->front, cam->up);
};

void Scene::deleteScene(void){
    for(Cube c : this->objects){
        c.deleteRes();
    }
};