#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "SceneObject.h"

class Light{
    
    public:
        glm::vec3 color;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        glm::vec3 position;
        float strength;
        float n;
        Light(glm::vec3 color, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position, float strength, float n){
            this->color = color;
            this->ambient = ambient;
            this->diffuse = diffuse;
            this->specular = specular;
            this->position = position;
            this->strength = strength;
            this->n = n;
        };
};


class Cube : public SceneObject{
    public:
        Cube(std::string name, glm::vec3 color, const char* texture);  
};

class Pyramid : public SceneObject{
    public:
        Pyramid(std::string name, glm::vec3 color, const char* texture);
};

class Octahedron : public SceneObject{
    public:
        Octahedron(std::string name, glm::vec3 color, const char* texture);
};

#endif