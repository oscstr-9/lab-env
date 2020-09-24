#define STB_IMAGE_IMPLEMENTATION
#include "config.h"
#include "stb_Image.h"
#include "TextureResource.h"


TextureResource::TextureResource()
{
	//cool
}

void TextureResource::bindTexture(){
	glBindTexture(GL_TEXTURE_2D, texture);
	}

void TextureResource::LoadFromFile(const char* file) {

	int width, height, channels;

	unsigned char* img = stbi_load(file, &width, &height, &channels, 0);
	if (img == NULL) {
		printf("Image loaded incorrectly %s", file);
		exit(1);
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (channels == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	else if (channels == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(img);
}

TextureResource::~TextureResource()
{
}