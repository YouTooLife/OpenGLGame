#version 410 core
out vec4 color;

uniform vec3 boxColor;

void main()
{
    color = vec4(boxColor, 1.0f);
}
