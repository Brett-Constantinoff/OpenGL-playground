CC=g++
CFLAGS=-std=c++11 -c
LDFLAGS=-lglfw -lglew -framework OpenGL

all: main

main: main.o shader.o scene.o window.o objects.o camera.o imgui.o stb_image.o
	$(CC) main.o shader.o scene.o window.o objects.o camera.o imgui_demo.o imgui_draw.o imgui_impl_glfw.o imgui_impl_opengl3.o imgui_tables.o imgui_widgets.o imgui.o stb_image.o -std=c++11 -o main -lglfw -lglew -framework OpenGL

main.o: *.cpp
	$(CC) *.cpp $(CFLAGS)

camera.o: camera/*.cpp camera/*.h
	$(CC) camera/camera.cpp $(CFLAGS)


objects.o: objects/*.cpp objects/*.h
	$(CC) objects/*.cpp $(CFLAGS)


window.o: window/*.cpp window/*.h
	$(CC) window/*.cpp $(CFLAGS)


shader.o: shaders/*.cpp shaders/*.h
	$(CC) shaders/*.cpp $(CFLAGS)


scene.o: scene/*.cpp scene/*.h
	$(CC) scene/*.cpp $(CFLAGS)

imgui.o: ../libraries/imgui/imgui.cpp ../libraries/imgui/imgui_demo.cpp ../libraries/imgui/imgui_draw.cpp ../libraries/imgui/imgui_tables.cpp ../libraries/imgui/imgui_widgets.cpp ../libraries/imgui/imgui_impl_glfw.cpp ../libraries/imgui/imgui_impl_opengl3.cpp
	$(CC) ../libraries/imgui/imgui.cpp ../libraries/imgui/imgui_demo.cpp ../libraries/imgui/imgui_draw.cpp ../libraries/imgui/imgui_tables.cpp ../libraries/imgui/imgui_widgets.cpp ../libraries/imgui/imgui_impl_glfw.cpp ../libraries/imgui/imgui_impl_opengl3.cpp ../libraries/imgui/imgui_impl_opengl3.cpp $(CFLAGS)

stb_image.o: ../libraries/imageLoading/*.cpp
	$(CC) ../libraries/imageLoading/*.cpp $(CFLAGS)

clean: 
	$(RM) *.o 
	$(RM) main
	$(RM) imgui.ini