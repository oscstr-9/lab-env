#pragma once
#include "VectorMath.h";

class MatrixMath
{
	VectorMath matrix[4];

public:
	MatrixMath(VectorMath col1In, VectorMath col2In, VectorMath col3In, VectorMath col4In);
	MatrixMath matrixMultiplication(MatrixMath matrixA);
};

MatrixMath::MatrixMath(VectorMath col1In, VectorMath col2In, VectorMath col3In, VectorMath col4In) {
	matrix[0] = col1In;
	matrix[1] = col2In;
	matrix[2] = col3In;
	matrix[3] = col4In;
}

MatrixMath MatrixMath::matrixMultiplication(MatrixMath matrixA) {

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; i < 4; i++)
		{
				matrix[i].coords[j] * matrixA.matrix[j].coords[i];
		}

	}
}