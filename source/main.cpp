#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

enum class RETURN_CODE: int{
	RETURN_OK = 0,
	RETURN_ERROR
};

// Test code to ensure the build script, GLEW, GLFW and glm work.
int main(int argc, char** argv){
	fprintf(stdout, "TheBoredGroup\n");
	if(!glfwInit()){
		fprintf(stderr, "GLFW initialization failed.\n");
		return (int)RETURN_CODE::RETURN_ERROR;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // enable 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);	// use opengl 4.5
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);	// use opengl 4.5
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // include only the newer opengl pipeline

	GLFWwindow* window;
	window = glfwCreateWindow(1080, 960, "TheBoredGroup", NULL, NULL); // create window (width, height, title, n/a, n/a)

	if(window == NULL){
		fprintf(stderr, "Window creation failed\n");
		glfwTerminate(); // cleanup glfw because we initialized it
		return (int)RETURN_CODE::RETURN_ERROR;

	}

	glfwMakeContextCurrent(window); // GLEW initialization
	glewExperimental = true; // required since we use opengl core profile
	if(!glewInit() != GLEW_OK){
		fprintf(stderr, "Failed to open window, your PC setup might not be compatible with opengl 4.5");
		glfwTerminate(); // cleanup glfw because we initialized it
		return (int)RETURN_CODE::RETURN_OK;
	}

	fprintf(stdout, "Main loop\n");
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	do{
		fprintf(stdout, "tick.\n");
		glfwSwapBuffers(window); // copy the main render buffer to the screen (aka show frame)
		glfwPollEvents(); // process glfw events
	}while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0); // stop upon ESC pressed or something raised the windowShouldClose flag
	fprintf(stdout, "Main loop OVER\n");

	return (int)RETURN_CODE::RETURN_OK;
}
