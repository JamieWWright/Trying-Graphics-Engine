#include "Object.h"

void Object::Draw()
{
	std::string uniformName_Pos = std::string("objectPosition");
	glm::vec3 globalPos = glm::vec3(0.2f, 0.3f, 0);

	shader->SetUniform(uniformName_Pos, globalPos);

	
}