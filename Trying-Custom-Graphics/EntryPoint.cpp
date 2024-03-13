#include "Graphics.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ShaderProgram.h"

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

	std::vector<float> triangleFloats
	{
		-1, -1, 0,    1, 0, 0,
		 0,  1, 0,    0, 1, 0,
		 1,  0, 0,    0, 0, 1,
	};

	GLuint vertexBufferID = 0;
	glGenBuffers(1, &vertexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * triangleFloats.size(), triangleFloats.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	

	//Game loop
	while (!glfwWindowShouldClose(window))
	{
		//Clear screen, then do rendering here
		glClear(GL_COLOR_BUFFER_BIT);


		Update();
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));


		glDrawArrays(GL_TRIANGLES, 0, triangleFloats.size() / 3);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
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
	glClearColor(cos(clock() * 0.001) + 1, 0, 1, 1);
	
}

