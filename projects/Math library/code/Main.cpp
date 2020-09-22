#include "core/VectorMath.h";
#include "core/MatrixMath.h";
#include <iostream>;
using namespace std;

void main() {
	VectorMath vectorA (7, 4, -1);
	VectorMath vectorB(-5, 1, 3);
	VectorMath vectorC (6, -3, 2);
	VectorMath vectorD (-2, -4, 11, 1);
	VectorMath f;
	VectorMath vectorResult;
	//vectorResult = vectorA + vectorB;
	//vectorResult.printVector();
	//vectorResult = vectorB - vectorA;
	//vectorResult.printVector();
	//vectorResult = vectorResult * 4;
	//vectorResult.printVector();
	//cout << vectorA.len() << endl;
	////vectorA.normalize();
	//vectorA.printVector();

	MatrixMath matrixA(vectorA, vectorB, vectorC);
	MatrixMath matrixB(vectorC, vectorD, vectorB);

	//cout << endl;
	//matrixB.printMatrix();

	//cout << endl;
	//matrixA.vectorMultiplication(vectorC).printVector();
	//
	//cout << endl;
	//matrixA.matrixMultiplication(matrixB).printMatrix();

	cout << endl;
	matrixA.rotateMatrix(50, VectorMath(1, 0, 0)).printMatrix();

	cout << endl;
	MatrixMath BD = MatrixMath(vectorA, vectorB, vectorC, vectorD);
	BD.printMatrix();
	cout << BD.inverseMatrix();


}