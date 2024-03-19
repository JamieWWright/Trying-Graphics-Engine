#version 450

layout (location = 0) in vec3 verPosition;
layout (location = 1) in vec3 verColor;
layout (location = 2) in vec2 verUV;

uniform mat4 mvpMatrix;
out vec3 color;


void main()
{
	color = verColor;
	gl_Position = mvpMatrix * vec4(verPosition, 1.0);
}