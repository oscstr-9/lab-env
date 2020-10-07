//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015-2020 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include <stb_image.h>
#include <cstring>
#include "config.h"
#include "TestApp.h"
#include "render/MeshResource.h"
#include "render/TextureResource.h"
#include "render/ShaderResource.h"
#include "core/MatrixMath.h"
#include "render/Camera.h"

using namespace Display;
namespace Example
{
	ExampleApp::ExampleApp()
	{/*cool*/}

	ExampleApp::~ExampleApp()
	{/*so cool*/}
	bool ExampleApp::Open()
	{
		App::Open();
		this->window = new Display::Window;
		window->SetKeyPressFunction([this](int32 keycode, int32, int32 action, int32)
			{
			switch (keycode)
			{
			case GLFW_KEY_W:
			case GLFW_KEY_UP:
				up = action;
				break;
			case GLFW_KEY_A:
			case GLFW_KEY_LEFT:
				left = action;
				break;
			case GLFW_KEY_S:
			case GLFW_KEY_DOWN:
				down = action;
				break;
			case GLFW_KEY_D:
			case GLFW_KEY_RIGHT:
				right = action;
				break;
			case GLFW_KEY_ESCAPE:
				this->window->Close();
				break;
			default:
				break;
			}
			});
		window->SetMouseMoveFunction([this](float64 x, float64 y) {
			rotMat = RotateMatrix(((width/2)-x)*speed, VectorMath3(0,1,0))*RotateMatrix(((height/2)-y)*speed, VectorMath3(1,0,0));
		});
		
		if (this->window->Open())
		{
			window->GetSize(width, height);

			// set clear color (Background color)
			glClearColor(0.5f, 1.0f, 0.8f, 1.0f);
			shaders = std::make_shared<ShaderResource>();
			shaders->LoadShader("Engine/Render/VertShader.glsl","Engine/Render/FragShader.glsl");
			std::shared_ptr<TextureResource> pumpkinTexture = std::make_shared<TextureResource>("pumpkin.png");
			std::shared_ptr<MeshResource> mesh = MeshResource::Cube(size);
			MatrixMath transform = Identity();
			cube = new GraphicsNode(mesh, pumpkinTexture, shaders, transform);

			return true;
		}
		return false;
	}

	void ExampleApp::Run()
	{
		//Create camera
		Camera camera(90, width, height, 0.001, 100);
		camera.SetPosition(VectorMath3(0, 0, -5));

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		
		shaders->setMat4(camera.GetProjViewMatrix(), "projectionViewMatrix");
		shaders->setVec4(VectorMath4(1, 1, 1, 1), "colorVector");

		while (this->window->IsOpen())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			this->window->Update();
			
			posMat = posMat * MatrixMath::TranslationMatrix(VectorMath3((right-left), (up-down), 0).NormalizeNew()*0.08);
			cube->setTransform(posMat * rotMat*ScalarMatrix(VectorMath3(1,-1,1)));
			
			this->cube->Draw();
			this->window->SwapBuffers();
		}
	}
}