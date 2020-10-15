#include <vector>
#include "config.h"
#include "MeshResource.h"
#include "TextureResource.h"

MeshResource::MeshResource(Vertex vertices[], unsigned int indices[], int numOfVertices, int numOfIndicesIn) {
	numOfIndices = numOfIndicesIn;

	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numOfVertices, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * numOfIndices, indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

MeshResource::MeshResource(MeshResource& mesh) {
	this->vertexBuffer = mesh.vertexBuffer;
	this->indexBuffer = mesh.indexBuffer;
	this->numOfIndices = mesh.numOfIndices;
}

void MeshResource::Render() {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(GLfloat) * 3));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(GLfloat) * 7));
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(GLfloat) * 9));

		glDrawElements(GL_TRIANGLES, numOfIndices, GL_UNSIGNED_INT, 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

std::shared_ptr<MeshResource> MeshResource::Cube(float size) {

	// Vertex configuration: Vertex(Pos(x,y,z), color(x,y,z,w), texture(x,y), normals(x,y,z));

						  //Front (red)
	Vertex vertices[] = { Vertex(VectorMath3(-size / 2,-size / 2,size / 2),VectorMath4(1,0,0,1),1.f/3.f,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,-size/2,size/2), VectorMath4(1,0,0,1),2.f/3.f,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,size/2,size/2), VectorMath4(1,0,0,1),2.f/3.f,1, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,size/2,size/2), VectorMath4(1,0,0,1),1.f/3.f,1, VectorMath3(0,0,0)),

						  //Back (green)
						  Vertex(VectorMath3(-size/2,-size/2,-size/2),VectorMath4(0,1,0,1),0,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,-size/2,-size/2), VectorMath4(0,1,0,1),1.f/3.f,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,size/2,-size/2), VectorMath4(0,1,0,1),1.f / 3.f,1, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,size/2,-size/2), VectorMath4(0,1,0,1),0,1, VectorMath3(0,0,0)),
		
						  //Left (blue)
						  Vertex(VectorMath3(-size/2,-size/2,-size/2),VectorMath4(0,0,1,1),0,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,-size/2,size/2), VectorMath4(0,0,1,1),1.f / 3.f,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,size/2,size/2), VectorMath4(0,0,1,1),1.f / 3.f,1, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,size/2,-size/2), VectorMath4(0,0,1,1),0,1, VectorMath3(0,0,0)),

						  //Right (Purple)
						  Vertex(VectorMath3(size/2,-size/2,-size/2),VectorMath4(1,0,1,1),0,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,-size/2,size/2), VectorMath4(1,0,1,1),1.f / 3.f,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,size/2,size/2), VectorMath4(1,0,1,1),1.f / 3.f,1, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,size/2,-size/2), VectorMath4(1,0,1,1),0,1, VectorMath3(0,0,0)),

						  //Top (Yellow)
						  Vertex(VectorMath3(-size/2,size/2,size/2),VectorMath4(1,1,0,1),2.f / 3.f,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,size/2,size/2), VectorMath4(1,1,0,1),1,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,size/2,-size/2), VectorMath4(1,1,0,1),1,1, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,size/2,-size/2), VectorMath4(1,1,0,1),2.f/3.f,1, VectorMath3(0,0,0)),

						  //Bottom (Cyan)
						  Vertex(VectorMath3(size/2,-size/2,size/2),VectorMath4(0,1,1,1),2.f/3.f,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,-size/2,size/2), VectorMath4(0,1,1,1),1,0, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(-size/2,-size/2,-size/2), VectorMath4(0,1,1,1),1,1, VectorMath3(0,0,0)),
						  Vertex(VectorMath3(size/2,-size/2,-size/2), VectorMath4(0,1,1,1),2.f/3.f,1, VectorMath3(0,0,0))
};

	unsigned int indices[] = { 3,0,1,1,2,3,			//Front
							   7,4,5,5,6,7,			//Back
							   11,8,9,9,10,11,		//Left
							   15,12,13,13,14,15,	//Right
							   19,16,17,17,18,19,	//Top
							   23,20,21,21,22,23	//Bottom
	};

	return std::make_shared<MeshResource>(vertices, indices, sizeof(vertices)/sizeof(Vertex), sizeof(indices) / sizeof(unsigned int));
}
std::shared_ptr<MeshResource> LoadObj(std::string fileName)
{
	FILE* myfile = fopen(("textures/OBJs/" + fileName + ".obj").c_str(), "r");
	std::vector<VectorMath3> vC; // Vertex Coords
	std::vector<float[2]> vT; // Vertex Textures
	std::vector<VectorMath3> vN; // Vertex normals
	std::vector<Vertex> vertices; // Vertex indices
	int numOfIndices = 0;

	char buf[256];

	if (myfile != NULL)
	{
		while (fscanf(myfile, "%256s", buf) > 0)
		{
			// Vertex Coords
			if (buf[0] == 'v' && buf[1] == '\0') {
				float x, y, z;
				if (fscanf(myfile, "%f %f %f", &x, &y, &z) == 3) {
					vC.push_back(VectorMath3(x, y, z));
				}
				else { std::cout << "Vertex coords broken" << std::endl; }
			}

			// Vertex Textures
			else if (buf[0] == 'v' && buf[1] == 't' && buf[2] == '\0') {
				float x, y;
				float texPos[2];
				if (fscanf(myfile, "%f %f", &x, &y) == 2) {
					texPos[0] = x; texPos[1] = y;
					vT.push_back(texPos);
				}
				else { std::cout << "Vertex texture coords broken" << std::endl; }
			}

			// Vertex Normals
			else if (buf[0] == 'v' && buf[1] == 'n' && buf[2] == '\0') {
				float x, y, z;
				if (fscanf(myfile, "%f %f %f", &x, &y, &z) == 3) {
					vN.push_back(VectorMath3(x, y, z));
				}
				else { std::cout << "Vertex normal coords broken" << std::endl; }
			}

			// Vertices
			else if (buf[0] == 'f' && buf[1] == '\0') {
				std::string x, y, z, w;
				if (fscanf(myfile, "%s %s %s %s", &x, &y, &z, &w) == 4) {
					//		     Vertex(VectorMath3(pos),VectorMath4(color),  float(xTex),   float(yTex),VectorMath3(normal))
					vertices.push_back(Vertex(vC[x[0]-1],VectorMath4(1,1,1,1),vT[x[2]-1][0], vT[x[2]][1],vN[x[4]-1]));
					vertices.push_back(Vertex(vC[y[0]-1],VectorMath4(1,1,1,1),vT[y[2]-1][0], vT[y[2]][0],vN[y[4]-1]));
					vertices.push_back(Vertex(vC[z[0]-1],VectorMath4(1,1,1,1),vT[z[2]-1][0], vT[z[2]][0],vN[z[4]-1]));
					vertices.push_back(Vertex(vC[w[0]-1],VectorMath4(1,1,1,1),vT[w[2]-1][0], vT[w[2]][0],vN[w[4]-1]));

					numOfIndices += 4;
				}
				else if (fscanf(myfile, "%f %f %f", &x, &y, &z) == 3) {
					// add some stuff here
				}
				else { std::cout << "Vertex indices broken" << std::endl; }
			}
		}
		fclose(myfile);

		// Vertex Indices
		std::vector<int> indices;
		for (int i = 0; i < numOfIndices; i+=6)
		{
			indices.push_back(i);
			indices.push_back(i+1);
			indices.push_back(i+2);

			indices.push_back(i);
			indices.push_back(i+2);
			indices.push_back(i+3);
		}

		return std::make_shared<MeshResource>(&vertices[0], &indices[0], sizeof(vertices) / sizeof(Vertex), sizeof(indices) / sizeof(unsigned int));
	}
	else { std::cout << "Unable to open file"; }
	return NULL;
}
void MeshResource::Destroy() {
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
}
MeshResource::~MeshResource() {
	Destroy();
}