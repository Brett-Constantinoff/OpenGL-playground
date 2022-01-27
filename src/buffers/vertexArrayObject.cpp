#include "vertexArrayObject.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void VertexArrayObject::generate(unsigned int i){
    glGenVertexArrays(i,  &this->id);
};

void VertexArrayObject::bind(void){
    glBindVertexArray(this->id);
};

void VertexArrayObject::enableAttribute(unsigned int i){
    glEnableVertexAttribArray(i);
};