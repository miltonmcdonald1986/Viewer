#version 330 core
layout(location = 0) out vec4 FragColor;

uniform vec4 ourColor;

void main()
{
	FragColor = ourColor;
}
