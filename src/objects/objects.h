#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "SceneObject.h"


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