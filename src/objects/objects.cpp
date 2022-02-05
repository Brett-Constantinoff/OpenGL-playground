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
       0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f,  0.0f,    //0
       1.0f, 0.0f, 0.0f,    0.0f, 0.0f, 1.0f,   1.0f,  0.0f,    //1
       1.0f, 1.0f, 0.0f,    0.0f, 0.0f, 1.0f,   1.0f,  1.0f,    //2
       0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f,  1.0f,    //3

       //right face
       1.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f,   0.0f, 0.0f,     //4
       1.0f, 0.0f, 1.0f,    1.0f, 0.0f, 0.0f,   1.0f, 0.0f,     //5
       1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,     //6
       1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f,   0.0f, 1.0f,     //7

       //back face
       0.0f, 0.0f, 1.0f,    0.0f, 0.0f, -1.0f,  0.0f, 0.0f,     //8
       0.0f, 1.0f, 1.0f,    0.0f, 0.0f, -1.0f,  1.0f, 0.0f,     //9
       1.0f, 1.0f, 1.0f,    0.0f, 0.0f, -1.0f,  1.0f, 1.0f,     //10
       1.0f, 0.0f, 1.0f,    0.0f, 0.0f, -1.0f,  0.0f, 1.0f,     //11

       //left face
       0.0f, 0.0f, 0.0f,    -1.0f, 0.0f, 0.0f,  0.0f, 0.0f,     //12
       0.0f, 1.0f, 0.0f,    -1.0f, 0.0f, 0.0f,  1.0f, 0.0f,     //13
       0.0f, 1.0f, 1.0f,    -1.0f, 0.0f, 0.0f,  1.0f, 1.0f,     //14
       0.0f, 0.0f, 1.0f,    -1.0f, 0.0f, 0.0f,  0.0f, 1.0f,     //15

       //top face
       0.0f, 1.0f, 0.0f,     0.0f, 1.0f, 0.0f,  0.0f, 0.0f,     //16
       1.0f, 1.0f, 0.0f,     0.0f, 1.0f, 0.0f,  1.0f, 0.0f,     //17
       0.0f, 1.0f, 1.0f,     0.0f, 1.0f, 0.0f,  1.0f, 1.0f,     //18
       1.0f, 1.0f, 1.0f,     0.0f, 1.0f, 0.0f,  0.0f, 1.0f,     //19

       //bottom face
       0.0f, 0.0f, 1.0f,     0.0f, -1.0f, 0.0f, 0.0f, 0.0f,     //20
       0.0f, 1.0f, 1.0f,     0.0f, -1.0f, 0.0f, 1.0f, 0.0f,     //21
       1.0f, 1.0f, 1.0f,     0.0f, -1.0f, 0.0f, 1.0f, 1.0f,     //22
       1.0f, 0.0f, 1.0f,     0.0f, -1.0f, 0.0f, 0.0f, 1.0f      //23
    };
    this->triangles = {
        0,  1,  2,      0,  2,  3,
        4,  5,  6,      4,  6,  7,   
        8,  9,  10,     8,  10, 11,  
        12, 13, 14,     12, 14, 15, 
        16, 17, 18,     17, 18, 19,  
        20, 21, 22,     21, 22, 23
    };

    this->model = glm::mat4(1.0f);
    
    this->genVertexArray();
    this->bindVertexArray();

    //set buffers
    this->genBuffer(&this->vertexPosBuffer);
    this->bindBuffer(this->vertexPosBuffer);
    this->setBufferData(this->vertexPositions.size(), this->vertexPositions);
    
    this->genBuffer(&this->indexBuffer);
    this->bindIndexBuffer(this->indexBuffer);
    this->setIndexBufferData(this->triangles.size(), this->triangles);

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
