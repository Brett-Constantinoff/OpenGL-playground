#include "window/window.h"

int main(){
    
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