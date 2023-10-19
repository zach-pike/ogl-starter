#version 330 core

layout(location = 0) in vec2 vertexPositionModelspace;
layout(location = 1) in vec3 color_in;

out vec3 fragColor;

void main(){
    gl_Position = vec4(vertexPositionModelspace, 0, 1);
    fragColor = color_in;
}
