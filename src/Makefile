all: main

main: main.o shader.o scene.o window.o objects.o camera.o imgui.o 
	g++ main.o shader.o scene.o window.o objects.o camera.o imgui_demo.o imgui_draw.o imgui_impl_glfw.o imgui_impl_opengl3.o imgui_tables.o imgui_widgets.o imgui.o -std=c++11 -o main -lglfw -lglew -framework OpenGL

main.o: main.cpp
	g++ main.cpp -std=c++11 -c

camera.o: camera/camera.cpp
	g++ camera/camera.cpp -std=c++11 -c

objects.o: objects/objects.cpp objects/objects.h
	g++ objects/objects.cpp -std=c++11 -c

window.o: window/window.cpp window/window.h
	g++ window/window.cpp -std=c++11 -c

shader.o: shaders/shader.cpp shaders/shader.h
	g++ shaders/shader.cpp -std=c++11 -c

scene.o: scene/scene.cpp scene/scene.h
	g++ scene/scene.cpp -std=c++11 -c

imgui.o: ../libraries/imgui/imgui.cpp ../libraries/imgui/imgui_demo.cpp ../libraries/imgui/imgui_draw.cpp ../libraries/imgui/imgui_tables.cpp ../libraries/imgui/imgui_widgets.cpp ../libraries/imgui/imgui_impl_glfw.cpp ../libraries/imgui/imgui_impl_opengl3.cpp
	g++ ../libraries/imgui/imgui.cpp ../libraries/imgui/imgui_demo.cpp ../libraries/imgui/imgui_draw.cpp ../libraries/imgui/imgui_tables.cpp ../libraries/imgui/imgui_widgets.cpp ../libraries/imgui/imgui_impl_glfw.cpp ../libraries/imgui/imgui_impl_opengl3.cpp ../libraries/imgui/imgui_impl_opengl3.cpp -std=c++11 -c

clean: 
	rm -f *.o 