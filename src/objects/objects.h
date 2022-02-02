#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../buffers/vertexArrayObject.h"
#include "../buffers/vertexBuffer.h"

class Cube{
    private:
        std::vector<float> vertexPositions;
        VertexArrayObject vao;
        VertexBuffer vertexBuffer;
        VertexBuffer colorBuffer;
        void genVertexArray(void);
        void bindVertexArray(void);
        void genVertexBuffer(void);
        void genColorBuffer(void);
        void bindVertexBuffer(void);
        void bindColorBuffer(void);
        void setVertexBufferData(size_t size, std::vector<float> data);
        void setColorBufferData(size_t size, std::vector<float> data); 
        void setVertexAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset);
        void setColorAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset);
        void enableVertexAttrib(unsigned int i);
    public:
        Cube(std::string name, glm::vec3 color);
        glm::vec3 color;
        std::string name;
        glm::mat4 model;
        void draw(void);
        void move(float x, float y, float z);
        void translate(glm::vec3 vec);

       
};

#endif