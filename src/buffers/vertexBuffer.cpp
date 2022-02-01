#include "vertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void VertexBuffer::generate(unsigned int i){
    glGenBuffers(i, &this->id);
};

void VertexBuffer::bind(void){
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
};

void VertexBuffer::setData(std::size_t size, std::vector<float> data){
    float positions[size];
    std::copy(data.begin(), data.end(), positions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
};

void VertexBuffer::setAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset){
    glVertexAttribPointer(index, size, type, normalized, stride, offset);
};

