#!/bin/sh
g++ \
	./source/main.cpp -o ./build/main.x \
	-l GL \
	-l GLU \
	-L ./external/glew-2.1.0/build/lib \
	-l GLEW \
	-L ./external/glfw-3.2.1/build \
	-l glfw3 \
	-l m \
	-l X11 \
	-l Xxf86vm \
	-l Xrandr \
	-l pthread \
	-l Xi \
	-l Xinerama \
	-l Xcursor \
	-l rt \
	-l dl \
	-I ./source \
	-I ./external/glew-2.1.0/include \
	-I ./external/glfw-3.2.1/include \
	-I ./external/glm \
	\
	-std=c++14
