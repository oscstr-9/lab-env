#include "config.h"
#include "MeshResource.h"
#include "TextureResource.h"

MeshResource::MeshResource(Vertex vertices[], unsigned int indices[], int numOfVertices, int numOfIndicesIn) {
	numOfIndices = numOfIndicesIn;
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 7 * numOfVertices, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * numOfIndices, indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MeshResource::Render() {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, NULL);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (GLvoid*)(sizeof(GLfloat) * 3));

		glDrawElements(GL_TRIANGLES, numOfIndices, GL_UNSIGNED_INT, 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
MeshResource MeshResource::Cube(float size) {
							
	
						  //Front (red)
	Vertex vertices[] = { Vertex(VectorMath3(-size/2,-size/2,size/2),VectorMath4(1,0,0,1)),
						  Vertex(VectorMath3(size/2,-size/2,size/2), VectorMath4(1,0,0,1)),
						  Vertex(VectorMath3(size/2,size/2,size/2), VectorMath4(1,0,0,1)),
						  Vertex(VectorMath3(-size/2,size/2,size/2), VectorMath4(1,0,0,1)),

						  //Back (green)
						  Vertex(VectorMath3(-size/2,-size/2,-size/2),VectorMath4(0,1,0,1)),
						  Vertex(VectorMath3(size/2,-size/2,-size/2), VectorMath4(0,1,0,1)),
						  Vertex(VectorMath3(size/2,size/2,-size/2), VectorMath4(0,1,0,1)),
						  Vertex(VectorMath3(-size/2,size/2,-size/2), VectorMath4(0,1,0,1)),
		
						  //Left (blue)
						  Vertex(VectorMath3(-size/2,-size/2,-size/2),VectorMath4(0,0,1,1)),
						  Vertex(VectorMath3(-size/2,-size/2,size/2), VectorMath4(0,0,1,1)),
						  Vertex(VectorMath3(-size/2,size/2,size/2), VectorMath4(0,0,1,1)),
						  Vertex(VectorMath3(-size/2,size/2,-size/2), VectorMath4(0,0,1,1)), 

						  //Right (Purple)
						  Vertex(VectorMath3(size/2,-size/2,-size/2),VectorMath4(1,0,1,1)),
						  Vertex(VectorMath3(size/2,-size/2,size/2), VectorMath4(1,0,1,1)),
						  Vertex(VectorMath3(size/2,size/2,size/2), VectorMath4(1,0,1,1)),
						  Vertex(VectorMath3(size/2,size/2,-size/2), VectorMath4(1,0,1,1)),

						  //Top (Yellow)
						  Vertex(VectorMath3(-size/2,size/2,size/2),VectorMath4(1,1,0,1)),
						  Vertex(VectorMath3(size/2,size/2,size/2), VectorMath4(1,1,0,1)),
						  Vertex(VectorMath3(size/2,size/2,-size/2), VectorMath4(1,1,0,1)),
						  Vertex(VectorMath3(-size/2,size/2,-size/2), VectorMath4(1,1,0,1)),

						  //Bottom (Cyan)
						  Vertex(VectorMath3(size/2,-size/2,size/2),VectorMath4(0,1,1,1)),
						  Vertex(VectorMath3(-size/2,-size/2,size/2), VectorMath4(0,1,1,1)),
						  Vertex(VectorMath3(-size/2,-size/2,-size/2), VectorMath4(0,1,1,1)),
						  Vertex(VectorMath3(size/2,-size/2,-size/2), VectorMath4(0,1,1,1))
};

	unsigned int indices[] = { 3,0,1,1,2,3,			//Front
							   7,4,5,5,6,7,			//Back
							   11,8,9,9,10,11,		//Left
							   15,12,13,13,14,15,	//Right
							   19,16,17,17,18,19,	//Top
							   23,20,21,21,22,23	//Bottom
	};

	//LoadFromFile("carved_pumpkin.png");
	return MeshResource(vertices, indices, sizeof(vertices)/sizeof(Vertex), sizeof(indices) / sizeof(unsigned int));
}
void MeshResource::Destroy() {
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
}
MeshResource::~MeshResource() {
	Destroy();
}