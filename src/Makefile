all: main

main: main.o shader.o window.o imgui.o 
	g++ main.o shader.o window.o imgui_demo.o imgui_draw.o imgui_impl_glfw.o imgui_impl_opengl3.o imgui_tables.o imgui_widgets.o imgui.o -std=c++11 -o main -lglfw -lglew -framework OpenGL

main.o: main.cpp
	g++ main.cpp -std=c++11 -c

window.o: window/window.cpp window/window.h
	g++ window/window.cpp -std=c++11 -c

shader.o: shaders/shader.cpp shaders/shader.h
	g++ shaders/shader.cpp -std=c++11 -c

imgui.o: ../libraries/imgui/imgui.cpp ../libraries/imgui/imgui_demo.cpp ../libraries/imgui/imgui_draw.cpp ../libraries/imgui/imgui_tables.cpp ../libraries/imgui/imgui_widgets.cpp ../libraries/imgui/imgui_impl_glfw.cpp ../libraries/imgui/imgui_impl_opengl3.cpp
	g++ ../libraries/imgui/imgui.cpp ../libraries/imgui/imgui_demo.cpp ../libraries/imgui/imgui_draw.cpp ../libraries/imgui/imgui_tables.cpp ../libraries/imgui/imgui_widgets.cpp ../libraries/imgui/imgui_impl_glfw.cpp ../libraries/imgui/imgui_impl_opengl3.cpp ../libraries/imgui/imgui_impl_opengl3.cpp -std=c++11 -c

clean: 
	rm -f *.o 