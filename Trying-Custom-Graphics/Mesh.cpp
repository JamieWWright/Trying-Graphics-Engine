#include "Mesh.h"
#include "Graphics.h"

Mesh::Mesh(std::vector<Vertex> design)
{
	verticies = design;
	glGenBuffers(1, &bufferID);

	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * verticies.size(), verticies.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}

void Mesh::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);	

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, color)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, UV)));

	glDrawArrays(GL_TRIANGLES, 0, verticies.size());

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	
}
