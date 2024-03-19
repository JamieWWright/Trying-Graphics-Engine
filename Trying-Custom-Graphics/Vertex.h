#pragma once
#include "glm.hpp"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 UV;

	Vertex(glm::vec3 pos, glm::vec3 col, glm::vec2 uv);

};