#version 450

out vec4 PixelColor;

in ver3 Color;
void main()
{
	PixelColor = vec4(Color, 1);
}