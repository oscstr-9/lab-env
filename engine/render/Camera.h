#include "core/VectorMath.h"
#include "core/MatrixMath.h"

class Camera
{
private:
	VectorMath3 axis;
	VectorMath3 pos;
	float rad = 0;
	MatrixMath projectionMat;

public:
	Camera(float FOV, int width, int height, float near, float far);
	~Camera();
	void SetRotation(VectorMath3 axisIn, float radIn );
	void SetPosition(VectorMath3 posIn);
	MatrixMath GetProjViewMatrix();
};