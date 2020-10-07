#pragma once
#include "core/MatrixMath.h"
#include "core/VectorMath.h"
#include "Vertex.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

class MeshResource
{
	GLuint vertexBuffer;
	GLuint indexBuffer;
	
public:
	int numOfIndices;
	MeshResource(Vertex vertices[], unsigned int indices[], int numOfVertices, int numOfIndicesIn);
	MeshResource(MeshResource& mesh);
	MeshResource();
	static std::shared_ptr<MeshResource> Cube(float size);
	void Render();
	void Destroy();

	~MeshResource();
};
