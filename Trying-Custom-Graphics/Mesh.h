#pragma once
#include <vector>
#include "Graphics.h"
#include "Vertex.h"

struct Mesh
{
	GLuint bufferID;

	Mesh(std::vector<float> design);

	void MakeCurrentBuffer();
};