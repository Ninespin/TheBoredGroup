CC = gcc
CXX = g++

INCLUDES = -I$(glfw_inc) -I$(glew_inc) -I$(glm) 
LIBRARIES = -L$(glfw_lib) -L$(glew_lib) 

glfw = ./external/glfw-3.2.1
glfw_inc = $(glfw)/include
glfw_lib = $(glfw)/build

glew = ./external/glew-2.1.0
glew_inc = $(glew)/include
glew_lib = $(glew)/build/lib

glm = ./external/glm

CFLAGS = -Wall -ggdb -O3 $(INCLUDES)
CXXFLAGS = -Wall -ggdb -O3 $(INCLUDES)
LDFLAGS = $(LIBRARIES) $(x_lib) $(gl_lib) -lm -lpthread -lrt -ldl

x_lib = -lXi -lXinerama -lX11 -lXxf86vm -lXrandr -lXcursor
gl_lib = -lglfw3 -lGL -lGLU -lGLEW

VPATH = source

TARGET = main
cpp_files = main.cpp
objects = $(cpp_files:.cpp=.o) main.o
headers =

all: $(TARGET)

$(TARGET): $(objects)
		$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY : clean
clean :
		-rm $(TARGET) $(objects)
