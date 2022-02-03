#include "objects.h"
#include "../../libraries/imageLoading/stb_image.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Cube::Cube(std::string name, glm::vec3 color, const char* texture){
    this->name = name;
    this->color = color;
    this->texture = texture;
    this->vertexPositions = {
         //front face
        0.5f, 0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,
        0.0f, 0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f, 
        0.0f, 0.0f, 0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 
        0.0f, 0.0f, 0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
        0.5f, 0.0f, 0.5f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
        0.5f, 0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,

        //right face
        0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
        0.5f, 0.5f, 0.5f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
        0.5f, 0.0f, 0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
        0.5f, 0.0f, 0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
        0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,

        //left face
        0.0f, 0.5f, 0.5f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 0.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.5f,  -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.5f,  -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,  -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 0.0f,  -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,

        //back face
        0.5f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
        0.5f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f,

        //top face
        0.5f, 0.5f, 0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
        0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
        0.0f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
        0.0f, 0.5f, 0.5f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
        0.5f, 0.5f, 0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,

        //bottom face
        0.0f, 0.0f, 0.5f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 0.0f,  0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.0f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.5f,  0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.0f, 0.5f,  0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
    };

    this->model = glm::mat4(1.0f);
    
    this->genVertexArray();
    this->bindVertexArray();

    //set buffer
    this->genBuffer(&this->vertexPosBuffer);
    this->bindBuffer(this->vertexPosBuffer);
    this->setBufferData(this->vertexPositions.size(), this->vertexPositions);
    this->setTexture();

    //set vertex positions
    this->setAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    this->enableAttribPointer(0);

    //set normals
    this->setAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    this->enableAttribPointer(1);

    //set uv coordinates
    this->setAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    this->enableAttribPointer(2);
};

void Cube::draw(void){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->textBuffer);
    this->bindVertexArray();
    glDrawArrays(GL_TRIANGLES, 0, this->vertexPositions.size());  
};

void Cube::move(float x, float y, float z){
    this->model = glm::translate(this->model, glm::vec3(x, y, z));
};

void Cube::updateNormalMat(void){
    this->normalMat = glm::transpose(this->model);
    this->normalMat = glm::inverse(this->normalMat);
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

void Cube::setTexture(void){
    glGenTextures(1, &this->textBuffer);
    glBindTexture(GL_TEXTURE_2D, this->textBuffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(this->texture, &width, &height, &nrChannels, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        std::cout << "Texture loading failed" << std::endl;
    }
    stbi_image_free(data);
};

void Cube::deleteRes(void){
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vertexPosBuffer);
}