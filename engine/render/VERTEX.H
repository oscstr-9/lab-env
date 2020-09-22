#ifndef VERTICES_H
#define VERTICES_H

#include "core/VectorMath.h"

struct Vertex
{
	VectorMath3 pos;
	VectorMath4 color;
	//-----------------------//
	Vertex(VectorMath3 pos, VectorMath4 color);
};

inline Vertex::Vertex(VectorMath3 posIn, VectorMath4 colorIn) {
	pos = posIn;
	color = colorIn;
}
#endif // !VERTICES_H