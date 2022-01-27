#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>
#include <vector>
#include "../buffers/vertexArrayObject.h"
#include "../buffers/vertexBuffer.h"

class Cube{
    public:
        Cube(std::string name);
        std::string name;
        std::vector<float> vertexPositions;
        void draw(void);
};

#endif