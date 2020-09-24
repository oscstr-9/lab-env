#pragma once
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class TextureResource
{
private:

	GLuint texture;
public:
	TextureResource();
	~TextureResource();
	void bindTexture();
	void LoadFromFile(const char* filePath); 
};