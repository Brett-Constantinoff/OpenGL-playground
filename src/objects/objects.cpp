#include "objects.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Cube::Cube(std::string name, glm::vec3 color){
    this->name = name;
    this->color = color;
    this->vertexPositions = {
         //front face
        0.5f, 0.5f, 0.5f, 
        0.0f, 0.5f, 0.5f, 
        0.0f, 0.0f, 0.5f, 

        0.0f, 0.0f, 0.5f, 
        0.5f, 0.0f, 0.5f, 
        0.5f, 0.5f, 0.5f, 

        //right face
        0.5f, 0.5f, 0.0f, 
        0.5f, 0.5f, 0.5f, 
        0.5f, 0.0f, 0.5f, 

        0.5f, 0.0f, 0.5f, 
        0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 

        //left face
        0.0f, 0.5f, 0.5f, 
        0.0f, 0.0f, 0.0f, 
        0.0f, 0.0f, 0.5f, 
        
        0.0f, 0.5f, 0.5f, 
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, 0.0f,

        //back face
        0.5f, 0.0f, 0.0f, 
        0.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 

        0.0f, 0.5f, 0.0f, 
        0.5f, 0.5f, 0.0f, 
        0.5f, 0.0f, 0.0f, 

        //top face
        0.5f, 0.5f, 0.5f, 
        0.5f, 0.5f, 0.0f, 
        0.0f, 0.5f, 0.0f, 

        0.0f, 0.5f, 0.0f, 
        0.0f, 0.5f, 0.5f, 
        0.5f, 0.5f, 0.5f,

        //bottom face
        0.0f, 0.0f, 0.5f, 
        0.0f, 0.0f, 0.0f, 
        0.5f, 0.0f, 0.0f, 

        0.0f, 0.0f, 0.5f, 
        0.5f, 0.0f, 0.0f, 
        0.5f, 0.0f, 0.5f,
    };

    this->vertexNormals = {
         //front face
        0.0f, 0.0f, 1.0f, 
        0.0f, 0.0f, 1.0f, 
        0.0f, 0.0f, 1.0f, 

        0.0f, 0.0f, 1.0f, 
        0.0f, 0.0f, 1.0f, 
        0.0f, 0.0f, 1.0f,

        //right face
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        //left face
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,

        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,

        //back face
        0.0f, 0.0f, -1.0f, 
        0.0f, 0.0f, -1.0f, 
        0.0f, 0.0f, -1.0f, 

        0.0f, 0.0f, -1.0f, 
        0.0f, 0.0f, -1.0f, 
        0.0f, 0.0f, -1.0f,

        //top face
        0.0f, 1.0f, 0.0f, 
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,

        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,

        //bottom face
        0.0f, -1.0f, 0.0f, 
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,

        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
    };
    this->model = glm::mat4(1.0f);
    
    this->genVertexArray();
    this->bindVertexArray();

    this->genBuffer(&this->vertexPosBuffer);
    this->bindBuffer(this->vertexPosBuffer);
    this->setBufferData(this->vertexPositions.size(), this->vertexPositions);
    this->setAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    this->enableAttribPointer(0);

    this->genBuffer(&this->vertexNormBuffer);
    this->bindBuffer(this->vertexNormBuffer);
    this->setBufferData(this->vertexNormals.size(), this->vertexNormals);
    this->setAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    this->enableAttribPointer(1);
};

void Cube::draw(void){
    this->bindVertexArray();
    glDrawArrays(GL_TRIANGLES, 0, this->vertexPositions.size());  
};

void Cube::move(float x, float y, float z){
    this->model = glm::translate(this->model, glm::vec3(x, y, z));
};

void Cube::genVertexArray(void){
    glGenVertexArrays(1, &this->vao);
};

void Cube::bindVertexArray(void){
    glBindVertexArray(this->vao);
};

void Cube::genBuffer(unsigned int *buffer){
    glGenBuffers(1, buffer);
};

void Cube::bindBuffer(unsigned int buffer){
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
};

void Cube::setBufferData(size_t size, std::vector<float> data){
    float positions[size];
    std::copy(data.begin(), data.end(), positions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
};

void Cube::setAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset){
    glVertexAttribPointer(index, size, type, normalized, stride, offset);
};

void Cube::enableAttribPointer(unsigned int i){
    glEnableVertexAttribArray(i);
};