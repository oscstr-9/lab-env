#include "config.h"
#include "Camera.h"

Camera::Camera(float FOV, int width, int height, float near, float far)
{
	axis = VectorMath3(0,1,0);
	pos = VectorMath3(0,0,0);
	projectionMat = MatrixMath::ProjectionMatrix(FOV, (float)width / (float)height, near, far);
}

void Camera::SetRotation(VectorMath3 axisIn, float radIn) {
	axis = axisIn;
	rad = radIn;
}

void Camera::SetPosition(VectorMath3 posIn) {
	pos = posIn;
}

MatrixMath Camera::GetProjViewMatrix() {
	return  projectionMat * MatrixMath::TranslationMatrix(pos) * RotateMatrix(rad, axis);
}

Camera::~Camera()
{
}