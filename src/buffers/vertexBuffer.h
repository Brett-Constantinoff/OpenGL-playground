#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <iostream>
#include <vector>

class VertexBuffer{
    private:
        unsigned int id;

    public:
        void generate(unsigned int i);
        void bind(void);
        void setData(std::size_t size, std::vector<float> data);
        void setAttribPointer(unsigned int index, int size, int type, bool normalized, int stride, const void* offset);
};

#endif