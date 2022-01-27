#include "window/window.h"
#include "shaders/shader.h"
#include "objects/objects.h"
#include "buffers/vertexArrayObject.h"
#include "buffers/vertexBuffer.h"

int main(){
    
   Window window(800, 600, "Hello World");
   window.init();
   window.setViewPort(0, 0);
   window.enable3d();

   Shader shader("shaders/shader.shader");

   Cube cube("my cube");


   VertexArrayObject vao;
   vao.generate(1);
   vao.bind();

   VertexBuffer vbo;
   vbo.generate(1);
   vbo.bind();
   vbo.setData(cube.vertexPositions.size(), cube.vertexPositions);
   vbo.setAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
   vao.enableAttribute(0);

   while(window.isOpen()){
       window.clearColor(1.0f, 1.0f, 1.0f, 1.0f);
       window.clearBuffers();

       shader.use();
       vao.bind();

       cube.draw();

       window.swapBuffers();
       window.pollEvents();
   }

   window.quit();
}