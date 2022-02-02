##shader vertexShader
#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 oFragmentColour;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
   gl_Position = projection * view * model * vec4(aPos, 1.0);
}

#shader fragmentShader
#version 330 core

uniform vec3 color;

out vec4 colour;

void main()
{
   colour = vec4(color,  1.0);
}
