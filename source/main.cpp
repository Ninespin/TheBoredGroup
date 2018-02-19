#include <stdio.h>
#include <stdlib.h>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Bore.h"


enum class RETURN_CODE: int{
	RETURN_OK = 0,
	RETURN_ERROR
};


static void error_callback(int error, const char* description){
	fprintf(stderr, "Error: %s\n", description);
}


int main(int argc, char** argv){
	fprintf(stdout, "TheBoredGroup\n");
	glfwSetErrorCallback(error_callback);

	if(!glfwInit()){
		fprintf(stderr, "GLFW initialization failed.\n");
		return (int)RETURN_CODE::RETURN_ERROR;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // enable 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// use opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	// use opengl 3.3
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // include only the newer opengl pipeline
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "TheBoredGroup",  nullptr, nullptr); // create window (width, height, title, fullscreen on what monitor (nptr means not fullscreen), n/a)

	if(window == nullptr){
		fprintf(stderr, "Window creation failed\n");
		glfwTerminate(); // cleanup glfw because we initialized it
		return (int)RETURN_CODE::RETURN_ERROR;

	}

	glfwMakeContextCurrent(window); // GLEW initialization
	glewExperimental = GL_TRUE; // required since we use opengl core profile
	if(glewInit()!=GLEW_OK){
		fprintf(stderr, "Failed to initialize glew");
		glfwTerminate(); // cleanup glfw because we initialized it
		return (int)RETURN_CODE::RETURN_ERROR;
	}



	Bore::Bore b;
	std::shared_ptr<Scene::Scene> s = std::shared_ptr<Scene::Scene>(new Scene::Scene("default"));
	s->addGameObject(std::shared_ptr<GameObjects::RenderableObject>(new GameObjects::RenderableObject("object 1")));
	b.addScene(s);
	b.setCurrentScene("default");

	fprintf(stdout, "Main loop\n");
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.3f, 0.33f, 0.37f, 1.0f);
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		b.Update();
		b.Render();

		glfwSwapBuffers(window); // copy the main render buffer to the screen (aka show frame)
		glfwPollEvents(); // process glfw events
	}while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0); // stop upon ESC pressed or something raised the windowShouldClose flag
	fprintf(stdout, "Main loop OVER\n");


	glfwDestroyWindow(window);
	glfwTerminate();
	return (int)RETURN_CODE::RETURN_OK;
}
