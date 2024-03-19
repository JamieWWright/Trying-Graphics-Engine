#include "Graphics.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ShaderProgram.h"
#include "Object.h"
#include "ext/matrix_transform.hpp"
#include "ext/matrix_clip_space.hpp"

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
	
	ShaderProgram basicShader("Shader.vert", "Shader.frag");
	basicShader.UseShader();

	std::vector<Vertex> cubeVerticies
	{
		Vertex({0, 0, 0}, {0, 0, 1}, {0, 0}),
		Vertex({1, 0, 0}, {0, 0, 1}, {0, 0}),
		Vertex({0, 1, 0}, {0, 0, 1}, {0, 0}),
		Vertex({0, 1, 0}, {0, 0, 1}, {0, 0}),
		Vertex({1, 0, 0}, {0, 0, 1}, {0, 0}),
		Vertex({1, 1, 0}, {0, 0, 1}, {0, 0}),

		Vertex({0, 0, 1}, {1, 1, 0}, {0, 0}),
		Vertex({0, 1, 1}, {1, 1, 0}, {0, 0}),
		Vertex({1, 0, 1}, {1, 1, 0}, {0, 0}),
		Vertex({0, 1, 1}, {1, 1, 0}, {0, 0}),
		Vertex({1, 0, 1}, {1, 1, 0}, {0, 0}),
		Vertex({1, 1, 1}, {1, 1, 0}, {0, 0}),
		
		Vertex({0, 0, 0}, {0, 1, 0}, {0, 0}),
		Vertex({0, 0, 1}, {0, 1, 0}, {0, 0}),
		Vertex({1, 0, 0}, {0, 1, 0}, {0, 0}),
		Vertex({0, 0, 1}, {0, 1, 0}, {0, 0}),
		Vertex({1, 0, 0}, {0, 1, 0}, {0, 0}),
		Vertex({1, 0, 1}, {0, 1, 0}, {0, 0}),
		
		Vertex({0, 1, 0}, {1, 0, 1}, {0, 0}),
		Vertex({0, 1, 1}, {1, 0, 1}, {0, 0}),
		Vertex({1, 1, 0}, {1, 0, 1}, {0, 0}),
		Vertex({0, 1, 1}, {1, 0, 1}, {0, 0}),
		Vertex({1, 1, 0}, {1, 0, 1}, {0, 0}),
		Vertex({1, 1, 1}, {1, 0, 1}, {0, 0}),
		
		Vertex({0, 0, 0}, {1, 0, 0}, {0, 0}),
		Vertex({0, 0, 1}, {1, 0, 0}, {0, 0}),
		Vertex({0, 1, 0}, {1, 0, 0}, {0, 0}),
		Vertex({0, 0, 1}, {1, 0, 0}, {0, 0}),
		Vertex({0, 1, 0}, {1, 0, 0}, {0, 0}),
		Vertex({0, 1, 1}, {1, 0, 0}, {0, 0}),
		
		Vertex({1, 0, 0}, {0, 1, 1}, {0, 0}),
		Vertex({1, 0, 1}, {0, 1, 1}, {0, 0}),
		Vertex({1, 1, 0}, {0, 1, 1}, {0, 0}),
		Vertex({1, 0, 1}, {0, 1, 1}, {0, 0}),
		Vertex({1, 1, 0}, {0, 1, 1}, {0, 0}),
		Vertex({1, 1, 1}, {0, 1, 1}, {0, 0}),
	}; 

	Mesh cubeMesh(cubeVerticies);

	glEnable(GL_DEPTH_TEST);

	//Game loop
	while (!glfwWindowShouldClose(window))
	{
		//Clear screen, then do rendering here
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 modelMatrix = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(), { 0.0f, 1.0f, 0.0f });

		float aspect = 1280 / (float)720;

		glm::mat4 projectionMatrix = glm::perspective(3.14159f / 4.0f, aspect, 0.1f, 50.0f);

		glm::mat4 viewMatrix = glm::lookAt(glm::vec3(5, 5, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

		glm::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

		basicShader.SetUniform((std::string)"mvpMatrix", mvpMatrix);

		Update();
		cubeMesh.Draw();
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
	//deltaTime = clock() - prevTime;
	//prevTime = clock();
	//glClearColor(cos(clock() * 0.001) + 1, 0, 1, 1);
}

