#define GLFW_INCLUDE_NONE
#include "glfw3.h"
#include "glad.h"
#include <iostream>
#include <fstream>
#include <sstream>


float deltaTime;
float prevTime = 1;

void Update();


int main(void)
{
	GLFWwindow* window;

	//Initialses glfw or something
	if (!glfwInit())
	{
		std::cout << "glfw failed to Initiate \n";
		return -1;
	}

	window = glfwCreateWindow(1280, 720, "You should check out Terraria!", nullptr, nullptr); //creates a window to be used
	if (!window)
	{
		std::cout << "glfw failed to Initiate \n";
		glfwTerminate(); //If creating window failed, get out lol
		return -1;
	}

	glfwMakeContextCurrent(window); //Set currrent window to render be the one we made

	if (!gladLoadGL())
	{
		std::cout << "glad failed to load OpenGL functions";
		return -1;
	}
	
	//Game loop
	while (!glfwWindowShouldClose(window))
	{
		//Clear screen, then do rendering here
		glClear(GL_COLOR_BUFFER_BIT);

		Update();
		//Swap buffer - transfering to next frame
		glfwSwapBuffers(window);

		//Tell glfw to check if anything is going on with input, etc.
		glfwPollEvents();
	}

	//Window closed, cleanup glfw and exit
	glfwTerminate();
	return 0;
}

void Update()
{
	deltaTime = clock() - prevTime;
	prevTime = clock();
	glClearColor(cos(clock() * 0.001) + 1, 0, 1, 1);
}

std::string LoadFileAsString(std::string filename)
{
	std::ifstream curFile;
	curFile.open(".../Assets/" + filename, );
	curFile
}