#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class TextureResource
{
private:


public:
	TextureResource();
	~TextureResource();
	static void LoadFromFile(const char* filePath); 
};