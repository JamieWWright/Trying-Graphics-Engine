#version 450

layout (location = 0) in vec3 verPosition;
layout (location = 1) in vec3 verColor;

in normal vec3 offset;
out vec3 Color;

void main()
{
	Color = verColor;
	gl_Position = vec4(verPosition + offset, 1.0);
}