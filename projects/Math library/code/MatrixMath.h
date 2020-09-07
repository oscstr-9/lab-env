#pragma once
#include "VectorMath.h";

class MatrixMath
{
	VectorMath matrix[4];

public:
	MatrixMath(VectorMath col1In, VectorMath col2In, VectorMath col3In, VectorMath col4In);
	MatrixMath(VectorMath col1In, VectorMath col2In, VectorMath col3In);
	MatrixMath();
	void printMatrix();
	VectorMath operator[](int index)const;
	VectorMath& operator[](int index);
	MatrixMath matrixMultiplication(MatrixMath matrixA);
	VectorMath vectorMultiplication(VectorMath vectorA);
	MatrixMath rotateMatrix(float angle, VectorMath dir);
	MatrixMath transposeMatrix();
	bool inverseMatrix();
};

/// constructor for x, y, z and w
MatrixMath::MatrixMath(VectorMath col1In, VectorMath col2In, VectorMath col3In, VectorMath col4In) {
	matrix[0] = col1In;
	matrix[1] = col2In;
	matrix[2] = col3In;
	matrix[3] = col4In;
}

/// constructor for x, y, z and preset w
MatrixMath::MatrixMath(VectorMath col1In, VectorMath col2In, VectorMath col3In) {
	matrix[0] = col1In;
	matrix[1] = col2In;
	matrix[2] = col3In;
	matrix[3] = VectorMath(1);
}

/// constuctor for x, y, z and empty w
MatrixMath::MatrixMath() {
	for (int  i = 0; i < 4; i++)
	matrix[i] = VectorMath();

}

/// [] operator overload
VectorMath& MatrixMath::operator[](int index) {
	return matrix[index];
}

/// [] operator overload
VectorMath MatrixMath::operator[](int index)const {
	return matrix[index];
}

/// mathematical matrix multiplication using matrix * matrix, (this * argument)
MatrixMath MatrixMath::matrixMultiplication(MatrixMath matrixA) {
	MatrixMath tempMatrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				tempMatrix[j][i] += (*this)[j][i] * matrixA[k][j];
			}
		}

	}
	return tempMatrix;
}

/// mathematical matrix/vector multiplication using matrix * vector, (this * argument)
VectorMath MatrixMath::vectorMultiplication(VectorMath vectorA) {
	VectorMath tempVector;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempVector[i] += (*this)[i][j] * vectorA[i];
		}
	}
	return tempVector;
}

/// rotates matrix. takes in the rotation angle as float and the rotation axis as VectorMath
MatrixMath MatrixMath::rotateMatrix(float rad, VectorMath dir) {
	MatrixMath rotMat;
	dir.normalize();
	// [columns][rows]
	rotMat[0][0] = cos(rad) + (1 - cos(rad) * pow(dir.x, 2));
	rotMat[0][1] = (1-cos(rad))*dir.x*dir.y+dir.z*sin(rad);
	rotMat[0][2] = (1-cos(rad))*dir.x*dir.z+dir.y*sin(rad);

	rotMat[1][0] = (1 - cos(rad)) * dir.x * dir.y - dir.z * sin(rad);
	rotMat[1][1] = cos(rad) + (1 - cos(rad) * pow(dir.y, 2));
	rotMat[1][2] = (1 - cos(rad)) * dir.y * dir.z + dir.x * sin(rad);

	rotMat[2][0] = (1 - cos(rad)) * dir.x * dir.z + dir.y * sin(rad);
	rotMat[2][1] = (1 - cos(rad)) * dir.y * dir.z - dir.x * sin(rad);
	rotMat[2][2] = cos(rad) + (1 - cos(rad) * pow(dir.z, 2));

	return rotMat;
}
/// transposes the matrix
MatrixMath MatrixMath::transposeMatrix() {
	MatrixMath temp;
	for (char i = 0; i < 16; i++)
	{
		temp[i / 4][i % 4] = matrix[i % 4][i / 4];
	}
	return temp;
}

/// calculates the inverse of a matrix and returns a bool indicating wether its determenant is zero
inline bool MatrixMath::inverseMatrix()
{
	//to hold the matrix values
	double m[16];

	// to hold the Inverse
	MatrixMath tempMatrix;
	char k = 0;
	for (char i = 0; i < 4; i++)
	{
		for (char j = 0; j < 4; j++)
		{
			m[k] = (*this)[j][i];
			k++;
		}
	}
	double det;

	//Row 0/3
	tempMatrix[0][0] =
		m[5] * m[10] * m[15] -
		m[5] * m[11] * m[14] -
		m[9] * m[6] * m[15] +
		m[9] * m[7] * m[14] +
		m[13] * m[6] * m[11] -
		m[13] * m[7] * m[10];

	tempMatrix[1][0] =
		-m[4] * m[10] * m[15] +
		m[4] * m[11] * m[14] +
		m[8] * m[6] * m[15] -
		m[8] * m[7] * m[14] -
		m[12] * m[6] * m[11] +
		m[12] * m[7] * m[10];

	tempMatrix[2][0] =
		m[4] * m[9] * m[15] -
		m[4] * m[11] * m[13] -
		m[8] * m[5] * m[15] +
		m[8] * m[7] * m[13] +
		m[12] * m[5] * m[11] -
		m[12] * m[7] * m[9];

	tempMatrix[3][0] =
		-m[4] * m[9] * m[14] +
		m[4] * m[10] * m[13] +
		m[8] * m[5] * m[14] -
		m[8] * m[6] * m[13] -
		m[12] * m[5] * m[10] +
		m[12] * m[6] * m[9];


	//Row 1/3
	tempMatrix[0][1] =
		-m[1] * m[10] * m[15] +
		m[1] * m[11] * m[14] +
		m[9] * m[2] * m[15] -
		m[9] * m[3] * m[14] -
		m[13] * m[2] * m[11] +
		m[13] * m[3] * m[10];

	tempMatrix[1][1] =
		m[0] * m[10] * m[15] -
		m[0] * m[11] * m[14] -
		m[8] * m[2] * m[15] +
		m[8] * m[3] * m[14] +
		m[12] * m[2] * m[11] -
		m[12] * m[3] * m[10];

	tempMatrix[2][1] =
		-m[0] * m[9] * m[15] +
		m[0] * m[11] * m[13] +
		m[8] * m[1] * m[15] -
		m[8] * m[3] * m[13] -
		m[12] * m[1] * m[11] +
		m[12] * m[3] * m[9];

	tempMatrix[3][1] =
		m[0] * m[9] * m[14] -
		m[0] * m[10] * m[13] -
		m[8] * m[1] * m[14] +
		m[8] * m[2] * m[13] +
		m[12] * m[1] * m[10] -
		m[12] * m[2] * m[9];


	//Row 2/3
	tempMatrix[0][2] =
		m[1] * m[6] * m[15] -
		m[1] * m[7] * m[14] -
		m[5] * m[2] * m[15] +
		m[5] * m[3] * m[14] +
		m[13] * m[2] * m[7] -
		m[13] * m[3] * m[6];

	tempMatrix[1][2] =
		-m[0] * m[6] * m[15] +
		m[0] * m[7] * m[14] +
		m[4] * m[2] * m[15] -
		m[4] * m[3] * m[14] -
		m[12] * m[2] * m[7] +
		m[12] * m[3] * m[6];

	tempMatrix[2][2] =
		m[0] * m[5] * m[15] -
		m[0] * m[7] * m[13] -
		m[4] * m[1] * m[15] +
		m[4] * m[3] * m[13] +
		m[12] * m[1] * m[7] -
		m[12] * m[3] * m[5];

	tempMatrix[3][2] =
		-m[0] * m[5] * m[14] +
		m[0] * m[6] * m[13] +
		m[4] * m[1] * m[14] -
		m[4] * m[2] * m[13] -
		m[12] * m[1] * m[6] +
		m[12] * m[2] * m[5];


	//Row 3/3
	tempMatrix[0][3] =
		-m[1] * m[6] * m[11] +
		m[1] * m[7] * m[10] +
		m[5] * m[2] * m[11] -
		m[5] * m[3] * m[10] -
		m[9] * m[2] * m[7] +
		m[9] * m[3] * m[6];

	tempMatrix[1][3] =
		m[0] * m[6] * m[11] -
		m[0] * m[7] * m[10] -
		m[4] * m[2] * m[11] +
		m[4] * m[3] * m[10] +
		m[8] * m[2] * m[7] -
		m[8] * m[3] * m[6];

	tempMatrix[2][3] =
		-m[0] * m[5] * m[11] +
		m[0] * m[7] * m[9] +
		m[4] * m[1] * m[11] -
		m[4] * m[3] * m[9] -
		m[8] * m[1] * m[7] +
		m[8] * m[3] * m[5];

	tempMatrix[3][3] =
		m[0] * m[5] * m[10] -
		m[0] * m[6] * m[9] -
		m[4] * m[1] * m[10] +
		m[4] * m[2] * m[9] +
		m[8] * m[1] * m[6] -
		m[8] * m[2] * m[5];

	det = m[0] * tempMatrix[0][0] + m[1] * tempMatrix[1][0] + m[2] * tempMatrix[2][0] + m[3] * tempMatrix[3][0];
	if (det == 0)
		return false;

	for (char i = 0; i < 16; i++)
	{
		(*this)[i / 4][i % 4] = tempMatrix[i / 4][i % 4] / det;
	}

	return true;
}

/// This function is used to print matrices.
void MatrixMath::printMatrix() {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::left << std::setw(15) << matrix[j].coords[i];
		}
		std::cout << std::endl;
	}
}