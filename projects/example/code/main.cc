#include "VectorMath.h";
#include <iostream>;
using namespace std;

void main() {
	VectorMath vectorA (1, 2, 3, 4);
	vectorA.printVector();
	VectorMath vectorB(5, 6, 7, 8);
	VectorMath vectorResult;
	vectorResult = vectorA + vectorB;
	vectorResult.printVector();
	vectorResult = vectorB - vectorA;
	vectorResult.printVector();
	vectorResult = vectorResult * 4;
	vectorResult.printVector();
	cout << vectorA.lengthVector() << endl;
	vectorA.normalizeVector();
	vectorA.printVector();
}