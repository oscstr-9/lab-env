#pragma once
#include <IOstream>;
struct VectorMath
{
	union {
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float coords[4];
	};

	VectorMath(float xIn, float yIn, float zIn, float wIn);
	VectorMath();
	VectorMath operator+(VectorMath vectorA);
	VectorMath operator-(VectorMath vectorA);
	VectorMath operator*(float multiplier);
	float lengthVector();
	void normalizeVector();
	float dotProduct(VectorMath vectorA);
	VectorMath crossProduct(VectorMath vectorA);
	void printVector();

};
VectorMath::VectorMath(float xIn, float yIn, float zIn, float wIn) {
	x = xIn;
	y = yIn;
	z = zIn;
	w = wIn;
}
VectorMath::VectorMath() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

VectorMath VectorMath::operator+(VectorMath vectorA) {
	VectorMath temp;
	for (int i = 0; i < 4; i++)
	{
		temp.coords[i] = coords[i] + vectorA.coords[i];
	}
	return temp;
}

VectorMath VectorMath::operator-(VectorMath vectorA) {
	VectorMath temp;
	for (int i = 0; i < 4; i++)
	{
		temp.coords[i] = coords[i] - vectorA.coords[i];
	}
	return temp;
}

VectorMath VectorMath::operator*(float multiplier) {
	VectorMath temp;
	for (int i = 0; i < 4; i++) {
		temp.coords[i] = coords[i] * multiplier;
	}
	return temp;
}

float VectorMath::lengthVector() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

void VectorMath::normalizeVector() {
	float length = lengthVector();
	for (int i = 0; i < 4; i++)
	{
		coords[i] /= length;
	}
	VectorMath temp;
}

float VectorMath::dotProduct(VectorMath vectorA) {
	float temp = 0;
	for (int i = 0; i < 4; i++)
	{
		temp += coords[i] * vectorA.coords[i];
	}
	return temp;
}

VectorMath VectorMath::crossProduct(VectorMath vectorA) {
	VectorMath temp;
	//x*y
	temp.coords[2] = (coords[0] * vectorA.coords[1]) - (coords[1] * vectorA.coords[0]);
	//y*z
	temp.coords[0] = (coords[1] * vectorA.coords[2]) - (coords[2] * vectorA.coords[1]);
	//x*z
	temp.coords[1] = (coords[0] * vectorA.coords[2]) - (coords[2] * vectorA.coords[0]);
	//w
	temp.coords[3] = 0;
	return temp;
}

void VectorMath::printVector() {
	for (int i = 0; i < 4; i++)
	{
		std::cout << coords[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}

