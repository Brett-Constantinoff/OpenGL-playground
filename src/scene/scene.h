#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../objects/SceneObject.h"
#include "../window/window.h"
#include "../camera/camera.h"


class Scene{
    private:
        std::vector<SceneObject> objects;
    
    public:
        glm::mat4 projection;
        glm::mat4 view;
        void add(SceneObject shape);
        void setView(Window *win, Camera *cam);
        void deleteScene(void);
        std::vector<SceneObject> getObjects(void);

};

#endif