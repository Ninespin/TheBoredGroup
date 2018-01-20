CC = gcc
CXX = g++

CURRENT_DIR = $(shell pwd)
PREFIX = /usr


INCLUDES = -I$(glfw_inc) -I$(glew_inc) -I$(glm)
LIBRARIES = -L$(glfw_lib) -L$(glew_lib)

glfw = $(CURRENT_DIR)/external/glfw-3.2.1
glfw_inc = $(glfw)/include
glfw_lib = $(glfw)/build

glew = $(CURRENT_DIR)/external/glew-2.1.0
glew_inc = $(glew)/include
glew_lib = $(glew)/build/lib

glm = $(CURRENT_DIR)/external/glm

CFLAGS = -Wall -ggdb -O3 $(INCLUDES)
CXXFLAGS = -Wall -ggdb -O3 $(INCLUDES)
LDFLAGS = $(LIBRARIES)  $(gl_lib) $(x_lib) -lm -lpthread -lrt -ldl

x_lib = -lX11 -lXrandr -lXi -lXinerama -lXxf86vm -lXcursor
gl_lib = -lGL -lGLU -lGLEW -lglfw3

VPATH = source

TARGET = main
cpp_files = main.cpp
objects = $(cpp_files:.cpp=.o) main.o
headers =


all: $(TARGET)

$(TARGET): $(objects)
		$(CXX) -o $@ $^ $(LDFLAGS)

$(alib): $(obj)
	$(AR) rsc $@ $^

.PHONY : clean
clean :
		-rm $(TARGET) $(objects)

.PHONY: install
install:
	#mkdir -p $(DESTDIR)$(PREFIX)/lib
	#mkdir -p $(DESTDIR)$(PREFIX)/include
	cp -r $(glew_lib)/* $(DESTDIR)$(PREFIX)/lib
	cp -r $(glew_inc)/* $(DESTDIR)$(PREFIX)/include
