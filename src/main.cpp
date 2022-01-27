#define GL_SILENCE_DEPRECATION

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "window/window.h"

int main(){
    /*
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    
    const unsigned int width = 800, height = 600;
    GLFWwindow *win = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if(!win){
        std::cerr << "Error creating OpenGL window" << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(win);
    glViewport(0, 0, width, height);

   
    glewExperimental = true;
    if(glewInit() != GLEW_OK){
        std::cerr << "ERROR INITIALIZING GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }

    Window my_window(800, 600, "Hello world");
    */


    /*
    while(!glfwWindowShouldClose(win)){

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(win); //swap front and back buffer
        glfwPollEvents();
    }

    return 0;
    */
   Window window(800, 600, "Hello World");
   window.init();
   window.setViewPort(0, 0);

   while(window.isOpen()){
       window.clearColor(1.0f, 1.0f, 1.0f, 1.0f);
       window.clearBuffers();

       window.swapBuffers();
       window.pollEvents();

   }
   



}