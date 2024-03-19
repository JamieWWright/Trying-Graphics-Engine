#pragma once
#include <vector>
#include "Graphics.h"
#include "Vertex.h"

struct Mesh
{
	GLuint bufferID = 0;
	std::vector<Vertex> verticies;

	Mesh(std::vector<Vertex> design);

	void Draw();
};