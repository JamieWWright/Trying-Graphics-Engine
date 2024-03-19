#pragma once
#include "glm.hpp"

#include "Mesh.h"
#include "ShaderProgram.h"

struct Object
{
	glm::mat4 modelMatrix; 
	Mesh* loadedMeshID;
	ShaderProgram* shader;

	void Draw();
	void Move();
	void Rotate();

};