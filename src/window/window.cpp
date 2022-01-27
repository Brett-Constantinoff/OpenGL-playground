#define GL_SILENCE_DEPRECATION
#include "window.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Window::Window(int width, int height, std::string title){
    this->width = width;
    this->height = height;
    this->title = title.c_str(); 
};

void Window::init(void){
    /* INIT GLFW */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->win = glfwCreateWindow(this->width, this->height, "Hello World", NULL, NULL);
    if(!this->win){
        std::cerr << "Error creating OpenGL window" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->makeCurrentContext();

    /* GLEW INIT */
    glewExperimental = true;
    if(glewInit() != GLEW_OK){
        std::cerr << "ERROR INITIALIZING GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }
    
};

void Window::makeCurrentContext(void){
    glfwMakeContextCurrent(this->win);
};

void Window::setViewPort(int x, int y){
    glViewport(0, 0, this->width, this->height);
};

bool Window::isOpen(void){
    return !glfwWindowShouldClose(this->win);
}

void Window::clearColor(float r, float g, float b, float alpha){
    glClearColor(r, g, b, alpha);
}

void Window::clearBuffers(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers(void){
    glfwSwapBuffers(win);
};

void Window::pollEvents(void){
    glfwPollEvents();
}


