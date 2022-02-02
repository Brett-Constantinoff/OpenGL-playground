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
    this->model = glm::mat4(1.0f);
    this->genVertexArray();
    this->bindVertexArray();
    this->genVertexBuffer();
    this->bindVertexBuffer();
    this->setVertexBufferData(this->vertexPositions.size(), this->vertexPositions);
    this->setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    this->enableVertexAttrib(0);
};

void Cube::draw(void){
    this->vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, this->vertexPositions.size());  
};

void Cube::move(float x, float y, float z){
    this->model = glm::translate(this->model, glm::vec3(x, y, z));
};

void Cube::translate(glm::vec3 vec){
    this->model *= glm::vec4(vec, 1.0f);
};

void Cube::genVertexArray(void){
    this->vao.generate(1);
};

void Cube::bindVertexArray(void){
    this->vao.bind();
};

void Cube::genVertexBuffer(void){
    this->vertexBuffer.generate(1);
};

void Cube::genColorBuffer(void){
    this->colorBuffer.generate(1);
};

void Cube::bindVertexBuffer(void){
    this->vertexBuffer.bind();
};

void Cube::bindColorBuffer(void){
    this->colorBuffer.bind();
};

void Cube::setVertexBufferData(size_t size, std::vector<float> data){
    this->vertexBuffer.setData(size, data);
};

void Cube::setColorBufferData(size_t size, std::vector<float> data){
    this->colorBuffer.setData(size, data);
};

void Cube::setVertexAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset){
    this->vertexBuffer.setAttribPointer(index, size, type, normalized, stride, offset);
};

void Cube::setColorAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset){
    this->colorBuffer.setAttribPointer(index, size, type, normalized, stride, offset);
};

void Cube::enableVertexAttrib(unsigned int i){
    this->vao.enableAttribute(i);
};