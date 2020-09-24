#ifndef VERTEX_H
#define VERTEX_H

#include "core/VectorMath.h"

struct Vertex
{
	VectorMath3 pos;
	VectorMath4 color;
	float texture[2];
	//-----------------------//
	Vertex(VectorMath3 pos, VectorMath4 color, float texX, float texY);
};

inline Vertex::Vertex(VectorMath3 posIn, VectorMath4 colorIn, float texX, float texY) {
	pos = posIn;
	color = colorIn;
	texture[0] = texX;
	texture[1] = texY;
}
#endif // !VERTICES_H