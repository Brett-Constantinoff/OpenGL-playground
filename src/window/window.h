#ifndef WINDOW_H
#define WINDOW_H
#define GL_SILENCE_DEPRECATION

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
        int getWidth(void);
        int getHeight(void);
        void setViewPort(int x, int y);
        bool isOpen(void);
        void clearColor(float r, float g, float b, float alpha);
        void clearBuffers(void);
        void swapBuffers(void);
        void pollEvents(void);
        void quit(void);
        void enable3d(void);
        void enableGui(void);
        void renderGui(void);
        void quitGui(void);
        void startGuiElement(std::string name);
        void stopGuiElement(void);
        void setGuiFloat3(const char* title, glm::vec3 value, float min, float max);
        void setGuiColor(const char* title, glm::vec3* color);
};
#endif