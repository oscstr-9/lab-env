#pragma once
#include <IOstream>;
#include <IOmanip>;
struct VectorMath3
{
	union {
		struct
		{
			float x;
			float y;
			float z;
		};
		float coords[3];
	};

	VectorMath3(float xIn, float yIn, float zIn);
	VectorMath3();
	float& operator[](int index);
	float operator[](int index)const;
	VectorMath3 operator+(VectorMath3 vectorA);
	VectorMath3 operator-(VectorMath3 vectorA);
	VectorMath3 operator*(float multiplier);
	float len();
	void normalize();
	float dotProduct(VectorMath3 vectorA);
	VectorMath3 crossProduct(VectorMath3 vectorA);
	void printVector3();
};

// vector constructor for all values
inline VectorMath3::VectorMath3(float xIn, float yIn, float zIn)
{
	x = xIn;
	y = yIn;
	z = zIn;
}

// empty vector constructor
inline VectorMath3::VectorMath3()
{
	x = 0;
	y = 0;
	z = 0;
}

// [] operator overload
inline float& VectorMath3::operator[](int index) {
	return coords[index];
}

// [] operator overload
inline float VectorMath3::operator[](int index)const {
	return coords[index];
}

// + operator overload
inline VectorMath3 VectorMath3::operator+(VectorMath3 vectorA) {
	VectorMath3 temp;
	for (int i = 0; i < 3; i++)
	{
		temp[i] = coords[i] + vectorA[i];
	}
	return temp;
}

// - operator overload
inline VectorMath3 VectorMath3::operator-(VectorMath3 vectorA) {
	VectorMath3 temp;
	for (int i = 0; i < 3; i++)
	{
		temp[i] = coords[i] - vectorA[i];
	}
	return temp;
}

// * operator overload
inline VectorMath3 VectorMath3::operator*(float multiplier) {
	VectorMath3 temp;
	for (int i = 0; i < 3; i++) {
		temp[i] = coords[i] * multiplier;
	}
	return temp;
}

// calculates and returns the length of a vector
inline float VectorMath3::len() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

// normalizes a vector
inline void VectorMath3::normalize() {
	*this = *this * (1.0f / len());
}

// calculates the dot product between a vector and agument vector
inline float VectorMath3::dotProduct(VectorMath3 vectorA) {
	float temp = 0;
	for (int i = 0; i < 3; i++)
	{
		temp += coords[i] * vectorA[i];
	}
	return temp;
}

// calculates the cross product between a vector and agument vector
inline VectorMath3 VectorMath3::crossProduct(VectorMath3 vectorA) {
	VectorMath3 temp;
	//x*y
	temp[2] = (coords[0] * vectorA[1]) - (coords[1] * vectorA[0]);
	//y*z
	temp[0] = (coords[1] * vectorA[2]) - (coords[2] * vectorA[1]);
	//x*z
	temp[1] = (coords[0] * vectorA[2]) - (coords[2] * vectorA[0]);
	return temp;
}

// this function prints vector3s
inline void VectorMath3::printVector3() {
	for (int i = 0; i < 3; i++)
	{
		std::cout << coords[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}

//--------------------------------------------------------------------------------------\\

struct VectorMath4
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

	VectorMath4(float xIn, float yIn, float zIn, float wIn);
	VectorMath4(float xIn, float yIn, float zIn);
	VectorMath4(float wIn);
	VectorMath4();
	float operator[](int index)const;
	float& operator[](int index);
	VectorMath4 operator+(VectorMath4 vectorA);
	VectorMath4 operator-(VectorMath4 vectorA);
	VectorMath4 operator*(float multiplier);
	float len();
	void normalize();
	float dotProduct(VectorMath4 vectorA);
	VectorMath4 crossProduct(VectorMath4 vectorA);
	void printVector4();
};

inline VectorMath4::VectorMath4(float xIn, float yIn, float zIn, float wIn) {
	x = xIn;
	y = yIn;
	z = zIn;
	w = wIn;;
}

// constructor for // constructor for x, y, z
inline VectorMath4::VectorMath4(float xIn, float yIn, float zIn) {
	x = xIn;
	y = yIn;
	z = zIn;
	w = 0;
}

// constructor for empty vector with preset w
inline VectorMath4::VectorMath4(float wIn) {
	x = 0;
	y = 0;
	z = 0;
	w = wIn;
}

// constructor for empty vector
inline VectorMath4::VectorMath4() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

// [] operator overload
inline float& VectorMath4::operator[](int index) {
	return coords[index];
}

// [] operator overload
inline float VectorMath4::operator[](int index)const {
	return coords[index];
}

// + operator overload
inline VectorMath4 VectorMath4::operator+(VectorMath4 vectorA) {
	VectorMath4 temp;
	for (int i = 0; i < 4; i++)
	{
		temp[i] = coords[i] + vectorA[i];
	}
	return temp;
}

// - operator overload
inline VectorMath4 VectorMath4::operator-(VectorMath4 vectorA) {
	VectorMath4 temp;
	for (int i = 0; i < 4; i++)
	{
		temp[i] = coords[i] - vectorA[i];
	}
	return temp;
}

// * operator overload
inline VectorMath4 VectorMath4::operator*(float multiplier) {
	VectorMath4 temp;
	for (int i = 0; i < 4; i++) {
		temp[i] = coords[i] * multiplier;
	}
	return temp;
}

// calculates and returns the length of a vector
inline float VectorMath4::len() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

// normalizes a vector
inline void VectorMath4::normalize() {
	*this  = *this * (1.0f/len());
}

// calculates the dot product between a vector and agument vector
inline float VectorMath4::dotProduct(VectorMath4 vectorA) {
	float temp = 0;
	for (int i = 0; i < 4; i++)
	{
		temp += coords[i] * vectorA[i];
	}
	return temp;
}

// calculates the cross product between a vector and agument vector
inline VectorMath4 VectorMath4::crossProduct(VectorMath4 vectorA) {
	VectorMath4 temp;
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

// this function prints vector4s
inline void VectorMath4::printVector4() {
	for (int i = 0; i < 4; i++)
	{
		std::cout << coords[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}