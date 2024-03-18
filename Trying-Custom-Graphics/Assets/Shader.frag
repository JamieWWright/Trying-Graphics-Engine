#version 450

out vec4 PixelColor;

in vec3 color;
void main()
{
	PixelColor = vec4(color, 1);
}