#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../objects/objects.h"
#include "../window/window.h"
#include "../camera/camera.h"


class Scene{
    private:
        std::vector<Cube> objects;
    
    public:
        glm::mat4 projection;
        glm::mat4 view;
        void add(Cube c);
        void setView(Window *win, Camera *cam);
        std::vector<Cube> getObjects(void);

};

#endif