#version 450

layout (location = 0) in vec3 verPosition;
layout (location = 1) in vec3 verColor;
layout (location = 2) in vec2 verUV;

uniform vec3 objectPosition;
uniform mat4 mvp
out vec3 color;


void main()
{
	color = verColor;
	gl_Position = vec4(verPosition + offset, 1.0);
}