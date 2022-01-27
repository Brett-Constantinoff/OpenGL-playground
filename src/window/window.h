#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Window{
    private:
        int width;
        int height;
        const char* title;
        void makeCurrentContext(void);
    
    public:
        GLFWwindow* win;
        Window(int width, int height, std::string title);
        void init(void);
        void setViewPort(int x, int y);
        bool isOpen(void);
        void clearColor(float r, float g, float b, float alpha);
        void clearBuffers(void);
        void swapBuffers(void);
        void pollEvents(void);

    
};
#endif