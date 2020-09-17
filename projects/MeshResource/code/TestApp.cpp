//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015-2020 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#define _USE_MATH_DEFINES
#include "config.h"
#include "render/MeshResource.h"
#include "core/MatrixMath.h"
#include "TestApp.h"
#include <math.h>
#include <cstring>

const GLchar* vs =
"#version 430\n"
"layout(location=0) in vec3 pos;\n"
"layout(location=1) in vec4 color;\n"
"layout(location=0) out vec4 Color;\n"
"uniform mat4 posMatrix;"
"uniform vec4 colorVector;"
"void main()\n"
"{\n"
"	gl_Position = posMatrix*vec4(pos, 1);\n"
"	Color = colorVector*color;\n"
"}\n";

const GLchar* ps =
"#version 430\n"
"layout(location=0) in vec4 color;\n"
"out vec4 Color;\n"
"void main()\n"
"{\n"
"	Color = color;\n"
"}\n";

using namespace Display;
namespace Example
{

//------------------------------------------------------------------------------
/**
*/
ExampleApp::ExampleApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
ExampleApp::~ExampleApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
bool
ExampleApp::Open()
{
	App::Open();
	this->window = new Display::Window;
	window->SetKeyPressFunction([this](int32, int32, int32, int32)
	{
		this->window->Close();
	});

	GLfloat buf[] =
	{
		-0.5f,	-0.5f,	-1,			// pos 0
		1,		0,		0,		1,	// color 0
		0,		0.5f,	-1,			// pos 1
		0,		1,		0,		1,	// color 0
		0.5f,	-0.5f,	-1,			// pos 2
		0,		0,		1,		1	// color 0
	};

	if (this->window->Open())
	{
		// set clear color to gray
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		// setup vertex shader
		this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLint length = static_cast<GLint>(std::strlen(vs));
		glShaderSource(this->vertexShader, 1, &vs, &length);
		glCompileShader(this->vertexShader);

		// get error log
		GLint shaderLogSize;
		glGetShaderiv(this->vertexShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetShaderInfoLog(this->vertexShader, shaderLogSize, NULL, buf);
			printf("[SHADER COMPILE ERROR]: %s", buf);
			delete[] buf;
		}

		// setup pixel shader
		this->pixelShader = glCreateShader(GL_FRAGMENT_SHADER);
		length = static_cast<GLint>(std::strlen(ps));
		glShaderSource(this->pixelShader, 1, &ps, &length);
		glCompileShader(this->pixelShader);

		// get error log
		shaderLogSize;
		glGetShaderiv(this->pixelShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetShaderInfoLog(this->pixelShader, shaderLogSize, NULL, buf);
			printf("[SHADER COMPILE ERROR]: %s", buf);
			delete[] buf;
		}

		// create a program object
		this->program = glCreateProgram();
		glAttachShader(this->program, this->vertexShader);
		glAttachShader(this->program, this->pixelShader);
		glLinkProgram(this->program);
		glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetProgramInfoLog(this->program, shaderLogSize, NULL, buf);
			printf("[PROGRAM LINK ERROR]: %s", buf);
			delete[] buf;
		}

		// setup vbo
		Vertex vertices[] = { Vertex(VectorMath3(-0.5,-0.5,0),VectorMath4(1,0,0,1)),
						 	  Vertex(VectorMath3(0.5,-0.5,0), VectorMath4(0,1,0,1)),
						 	  Vertex(VectorMath3(0.5,0.5,0), VectorMath4(0,0,1,1)),
							  Vertex(VectorMath3(-0.5,0.5,0), VectorMath4(1,0,1,1)) };
		unsigned int indices[] = { 3,0,1,1,2,3 };
		quadrilateral = new MeshResource(vertices, indices, 4, sizeof(indices) / sizeof(unsigned int));
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
/**
*/
void
ExampleApp::Run()
{
	float xpos = cos(1), angle = 0, rotation = 0, size = 1;
	while (this->window->IsOpen())
	{
		MatrixMath posMatrix (VectorMath4(1, 0, 0), VectorMath4(0, 1, 0), VectorMath4(0, 0, 1), VectorMath4(xpos,0,0,1));
		MatrixMath scaleMatrix (VectorMath4(size, 0, 0), VectorMath4(0, size, 0), VectorMath4(0, 0, size), VectorMath4(1));
		VectorMath4 rotVector(0, 0,1);
		MatrixMath rotMatrix = rotateMatrix(rotation, rotVector);
		MatrixMath finalMatrix = scaleMatrix.matrixMultiplication(rotMatrix.matrixMultiplication(posMatrix));
		VectorMath4 colorVector (cos(angle*2),sin(angle*7),cos(angle*5),1);
		xpos = cos(angle) * sin(angle*2);
		angle += 0.05;
		rotation += 0.05;
		size = cos(angle*4)*sin(angle*4)+1;
		glClear(GL_COLOR_BUFFER_BIT);
		this->window->Update();

		// do stuff
		glUseProgram(this->program);
		auto loc = glGetUniformLocation(program, "posMatrix");
		auto color = glGetUniformLocation(program, "colorVector");
		glUniformMatrix4fv(loc, 1, GL_FALSE, (float*)&finalMatrix);
		glUniform4fv(color, 1, (float*)&colorVector);
		quadrilateral->render();



		this->window->SwapBuffers();
	}
}

} // namespace Exampled