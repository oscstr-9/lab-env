#pragma once
#define _USE_MATH_DEFINES
#include "VectorMath.h";
#include <math.h>

class MatrixMath
{
	VectorMath4 matrix[4];

public:
	MatrixMath(VectorMath4 col1In, VectorMath4 col2In, VectorMath4 col3In, VectorMath4 col4In);
	MatrixMath(VectorMath4 col1In, VectorMath4 col2In, VectorMath4 col3In);
<<<<<<< HEAD:engine/core/MatrixMath.h
	MatrixMath(float w = 1);
	static MatrixMath TranslationMatrix(VectorMath3 W);
	void PrintMatrix();
	VectorMath4 operator[](int index)const;
	VectorMath4& operator[](int index);
	MatrixMath operator*(MatrixMath matrixA);
	VectorMath4 VectorMultiplication(VectorMath4 vectorA);
	//MatrixMath RotateMatrix(float angle, VectorMath4 dir);
	//static MatrixMath Identity();
	MatrixMath TransposeMatrix();
	MatrixMath InverseMatrix();
	static MatrixMath ProjectionMatrix(float FOV, float AspectRatio, float Near, float Far);
=======
	MatrixMath();
	void printMatrix();
	VectorMath4 operator[](int index)const;
	VectorMath4& operator[](int index);
	MatrixMath matrixMultiplication(MatrixMath matrixA);
	VectorMath4 vectorMultiplication(VectorMath4 vectorA);
	MatrixMath rotateMatrix(float angle, VectorMath4 dir);
	MatrixMath transposeMatrix();
	MatrixMath inverseMatrix();
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
};

/// constructor for x, y, z and w
inline MatrixMath::MatrixMath(VectorMath4 col1In, VectorMath4 col2In, VectorMath4 col3In, VectorMath4 col4In) {
	matrix[0] = col1In;
	matrix[1] = col2In;
	matrix[2] = col3In;
	matrix[3] = col4In;
}

/// constructor for x, y, z and preset w
inline MatrixMath::MatrixMath(VectorMath4 col1In, VectorMath4 col2In, VectorMath4 col3In) {
	matrix[0] = col1In;
	matrix[1] = col2In;
	matrix[2] = col3In;
	matrix[3] = VectorMath4(1);
<<<<<<< HEAD:engine/core/MatrixMath.h
}
// returns translation matrix
inline MatrixMath MatrixMath::TranslationMatrix(VectorMath3 W) {
	MatrixMath temp;
	temp[0] = VectorMath4(1,0,0,0);
	temp[1] = VectorMath4(0,1,0,0);
	temp[2] = VectorMath4(0,0,1,0);
	temp[3] = VectorMath4(W, 1);
	return temp;
}

//Returns identity matrix
inline MatrixMath Identity() {
	MatrixMath temp;
	temp[0] = VectorMath4(1,0,0,0);
	temp[1] = VectorMath4(0,1,0,0);
	temp[2] = VectorMath4(0,0,1,0);
	temp[3] = VectorMath4(0,0,0,1);
	return temp;
=======
}

/// constuctor for x, y, z and empty w
inline MatrixMath::MatrixMath() {
	for (int  i = 0; i < 3; i++)
	matrix[i] = VectorMath4();
	matrix[3] = VectorMath4(1);
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
}

/// constuctor for x, y, z and empty w
inline MatrixMath::MatrixMath(float w) {
	for (int  i = 0; i < 3; i++)
	matrix[i] = VectorMath4();
	matrix[3] = VectorMath4(w);
}
/// [] operator overload
inline VectorMath4& MatrixMath::operator[](int index) {
	return matrix[index];
}

/// [] operator overload
inline VectorMath4 MatrixMath::operator[](int index)const {
	return matrix[index];
}

/// mathematical matrix multiplication using matrix * matrix, (this * argument)
<<<<<<< HEAD:engine/core/MatrixMath.h
inline MatrixMath MatrixMath::operator*(MatrixMath matrixA) {
	MatrixMath tempMatrix(0);
	//[column][row]
=======
inline MatrixMath MatrixMath::matrixMultiplication(MatrixMath matrixA) {
	MatrixMath tempMatrix;
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
<<<<<<< HEAD:engine/core/MatrixMath.h
				tempMatrix[j][i] += (*this)[k][i] * matrixA[j][k];
=======
				tempMatrix[j][i] += (*this)[j][k] * matrixA[k][i];
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
			}
		}

	}
	return tempMatrix;
}

/// mathematical matrix/vector multiplication using matrix * vector, (this * argument)
<<<<<<< HEAD:engine/core/MatrixMath.h
inline VectorMath4 MatrixMath::VectorMultiplication(VectorMath4 vectorA) {
=======
inline VectorMath4 MatrixMath::vectorMultiplication(VectorMath4 vectorA) {
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
	VectorMath4 tempVector;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempVector[i] += (*this)[i][j] * vectorA[i];
		}
	}
	return tempVector;
}

/// rotates matrix. takes in the rotation angle as float and the rotation axis as VectorMath4
<<<<<<< HEAD:engine/core/MatrixMath.h
inline MatrixMath RotateMatrix(float rad, VectorMath3 dir) {
=======
inline MatrixMath rotateMatrix(float rad, VectorMath4 dir) {
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
	MatrixMath rotMat;
	dir.Normalize();
	// [columns][rows]
	rotMat[0][0] = cos(rad) + (1 - cos(rad)) * pow(dir.x, 2);
	rotMat[0][1] = (1-cos(rad))*dir.x*dir.y+dir.z*sin(rad);
	rotMat[0][2] = (1-cos(rad))*dir.x*dir.z-dir.y*sin(rad);

	rotMat[1][0] = (1 - cos(rad)) * dir.x * dir.y - dir.z * sin(rad);
	rotMat[1][1] = cos(rad) + (1 - cos(rad)) * pow(dir.y, 2);
	rotMat[1][2] = (1 - cos(rad)) * dir.y * dir.z + dir.x * sin(rad);

	rotMat[2][0] = (1 - cos(rad)) * dir.x * dir.z + dir.y * sin(rad);
	rotMat[2][1] = (1 - cos(rad)) * dir.y * dir.z - dir.x * sin(rad);
	rotMat[2][2] = cos(rad) + (1 - cos(rad)) * pow(dir.z, 2);

	return rotMat;
}
/// transposes the matrix
<<<<<<< HEAD:engine/core/MatrixMath.h
inline MatrixMath MatrixMath::TransposeMatrix() {
=======
inline MatrixMath MatrixMath::transposeMatrix() {
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
	MatrixMath temp;
	for (char i = 0; i < 16; i++)
	{
		temp[i / 4][i % 4] = matrix[i % 4][i / 4];
	}
	return temp;
}

/// calculates the inverse of a matrix and returns a bool indicating wether its determenant is zero
<<<<<<< HEAD:engine/core/MatrixMath.h
inline MatrixMath MatrixMath::InverseMatrix()
=======
inline MatrixMath MatrixMath::inverseMatrix()
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
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
		return MatrixMath(VectorMath4(1,0,0,0), VectorMath4(0, 1, 0, 0), VectorMath4(0, 0, 1, 0), VectorMath4(0, 0, 0, 1));
<<<<<<< HEAD:engine/core/MatrixMath.h

	return tempMatrix;
}

inline MatrixMath MatrixMath::ProjectionMatrix(float FOV, float AspectRatio, float Near, float Far) {

	MatrixMath perspectiveMatrix;
	perspectiveMatrix[0][0] = 1 / tan(FOV * (float)M_PI / 360);
	perspectiveMatrix[1][1] = AspectRatio / tan(FOV * (float)M_PI / 360);
	perspectiveMatrix[2][2] = (Near + Far) / (Near - Far);
	perspectiveMatrix[2][3] = -1;
	perspectiveMatrix[3][2] = (2 * Near * Far) / (Near - Far);
	perspectiveMatrix[3][3] = 0;

	perspectiveMatrix.PrintMatrix();
	return perspectiveMatrix;
}

/// This function is used to print matrices.
inline void MatrixMath::PrintMatrix() {
=======

	return tempMatrix;
}

/// This function is used to print matrices.
inline void MatrixMath::printMatrix() {
>>>>>>> origin/master:projects/Math library/code/MatrixMath.h
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::left << std::setw(15) << matrix[j].coords[i];
		}
		std::cout << std::endl;
	}
}