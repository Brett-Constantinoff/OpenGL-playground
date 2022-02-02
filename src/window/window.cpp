#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "../../libraries/imgui/imgui.h"
#include "../../libraries/imgui/imgui_impl_glfw.h"
#include "../../libraries/imgui/imgui_impl_opengl3.h"

Window::Window(int width, int height, std::string title){
    this->width = width;
    this->height = height;
    this->title = title.c_str(); 

    /* INIT GLFW */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->win = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
    if(!this->win){
        std::cerr << "Error creating OpenGL window" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->makeCurrentContext();
    this->setViewPort(0, 0);

    /* GLEW INIT */
    glewExperimental = true;
    if(glewInit() != GLEW_OK){
        std::cerr << "ERROR INITIALIZING GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }

     /* IMGUI INIT */
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io; //sets up input / output
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(this->win, true);
    ImGui_ImplOpenGL3_Init("#version 150");
};

int Window::getHeight(void){
    return this->height;
};

int Window::getWidth(void){
    return this->width;
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
    glfwSwapBuffers(this->win);
};

void Window::pollEvents(void){
    glfwPollEvents();
};

void Window::quit(void){
    glfwDestroyWindow(this->win);
    glfwTerminate();
};

void Window::enable3d(void){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
};

void Window::enableGui(void){
    //setup imgui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
};

void Window::renderGui(void){
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
};

void Window::quitGui(void){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
};

void Window::startGuiElement(std::string name){
    ImGui::Begin("Hello, world!");     
};

void Window::stopGuiElement(void){
    ImGui::End();
};




