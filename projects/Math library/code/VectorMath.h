#pragma once
#include <IOstream>;
#include <IOmanip>;
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
	VectorMath(float xIn, float yIn, float zIn);
	VectorMath(float wIn);
	VectorMath();
	float operator[](int index)const;
	float& operator[](int index);
	VectorMath operator+(VectorMath vectorA);
	VectorMath operator-(VectorMath vectorA);
	VectorMath operator*(float multiplier);
	float len();
	void normalize();
	float dotProduct(VectorMath vectorA);
	VectorMath crossProduct(VectorMath vectorA);
	void printVector();

};
VectorMath::VectorMath(float xIn, float yIn, float zIn, float wIn) {
	x = xIn;
	y = yIn;
	z = zIn;
	w = wIn;;
}
// constructor for // constructor for x, y, z
VectorMath::VectorMath(float xIn, float yIn, float zIn) {
	x = xIn;
	y = yIn;
	z = zIn;
	w = 0;
}
// constructor for empty vector with preset w
VectorMath::VectorMath(float wIn) {
	x = 0;
	y = 0;
	z = 0;
	w = wIn;
}

// constructor for empty vector
VectorMath::VectorMath() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

// [] operator overload
float& VectorMath::operator[](int index) {
	return coords[index];
}

// [] operator overload
float VectorMath::operator[](int index)const {
	return coords[index];
}

// + operator overload
VectorMath VectorMath::operator+(VectorMath vectorA) {
	VectorMath temp;
	for (int i = 0; i < 4; i++)
	{
		temp[i] = coords[i] + vectorA[i];
	}
	return temp;
}

// - operator overload
VectorMath VectorMath::operator-(VectorMath vectorA) {
	VectorMath temp;
	for (int i = 0; i < 4; i++)
	{
		temp[i] = coords[i] - vectorA[i];
	}
	return temp;
}

// * operator overload
VectorMath VectorMath::operator*(float multiplier) {
	VectorMath temp;
	for (int i = 0; i < 4; i++) {
		temp[i] = coords[i] * multiplier;
	}
	return temp;
}

// calculates and returns the length of a vector
float VectorMath::len() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

// normalizes a vector
void VectorMath::normalize() {	
	*this  = *this * (1.0f/len());
}

// calculates the dot product between a vector and agument vector
float VectorMath::dotProduct(VectorMath vectorA) {
	float temp = 0;
	for (int i = 0; i < 4; i++)
	{
		temp += coords[i] * vectorA[i];
	}
	return temp;
}

// calculates the cross product between a vector and agument vector
VectorMath VectorMath::crossProduct(VectorMath vectorA) {
	VectorMath temp;
	//x*y
	temp[2] = (coords[0] * vectorA[1]) - (coords[1] * vectorA[0]);
	//y*z
	temp[0] = (coords[1] * vectorA[2]) - (coords[2] * vectorA[1]);
	//x*z
	temp[1] = (coords[0] * vectorA[2]) - (coords[2] * vectorA[0]);
	//w
	temp[3] = 0;
	return temp;
}

// this function prints vectors
void VectorMath::printVector() {
	for (int i = 0; i < 4; i++)
	{
		std::cout << coords[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}
