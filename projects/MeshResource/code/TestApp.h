#pragma once
//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015-2020 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/MeshResource.h"
#include "render/ShaderResource.h"
#include "render/window.h"
#include "render/GraphicsNode.h"
#include <memory>

namespace Example
{
class ExampleApp : public Core::App
{
public:
	/// constructor
	ExampleApp();
	/// destructor
	~ExampleApp();
	/// open app
	bool Open();
	/// run app
	void Run();
private:
	//screen size
	int width, height;

	float size = 1;
	float speed = 0.003;
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	MatrixMath rotMat = Identity();
	MatrixMath posMat = Identity();
	std::shared_ptr<ShaderResource> shaders;
	Display::Window* window;
	GraphicsNode* cube;
};
} // namespace Example