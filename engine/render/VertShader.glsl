#version 430
layout(location=0) in vec3 pos;
layout(location=1) in vec4 color;
layout(location=2) in vec2 texturesIn;

out vec4 Colors;
out vec2 texturesOut;

uniform mat4 posMatrix;
uniform mat4 projectionViewMatrix;
uniform vec4 colorVector;
uniform sampler2D textureArray;

void main()
{
	gl_Position = projectionViewMatrix*posMatrix*vec4(pos, 1);
	Colors = colorVector*color;
	texturesOut = texturesIn;
};
