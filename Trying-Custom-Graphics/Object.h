#pragma once
#include "glm.hpp"

#include "Mesh.h"
#include "ShaderProgram.h"

struct Object
{
	glm::vec2 position;
	Mesh* loadedMeshID;
	ShaderProgram* shader;

	void Draw();
};