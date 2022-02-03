#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Cube{
    private:
        std::vector<float> vertexPositions;
        unsigned int vao;
        unsigned int vertexPosBuffer;
        unsigned int textBuffer;
        void genVertexArray(void);
        void bindVertexArray(void);
        void genBuffer(unsigned int* buffer);
        void bindBuffer(unsigned int buffer);
        void setBufferData(size_t size, std::vector<float> data);
        void setAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset);
        void enableAttribPointer(unsigned int i);
        void setTexture(void);
    public:
        Cube(std::string name, glm::vec3 color, const char* texture);
        glm::vec3 color;
        std::string name;
        const char* texture;
        glm::mat4 model;
        glm::mat4 normalMat;
        void draw(void);
        void move(float x, float y, float z);
        void updateNormalMat(void);
        void translate(glm::vec3 vec);
        void deleteRes(void);
};

#endif