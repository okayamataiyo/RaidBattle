#pragma once
#include <DirectXMath.h>
using namespace DirectX;

class Circle {
public:
	XMFLOAT2 center_;
	float radius_;

	Circle(){}
	Circle(float _cX, float _cY, float _radius)
		:center_{ _cX,_cY }, radius_(_radius) {}

	bool ContainsPoint(const XMFLOAT2& _point) {
		float a = _point.x - center_.x;
		float b = _point.y - center_.y;
		float c = sqrt(a * a + b * b);

		return c <= radius_;
	}

	bool OverlapCircle(const Circle& _circle) {
		float a = _circle.center_.x - this->center_.x;
		float b = _circle.center_.y - this->center_.y;
		float c = sqrt(a * a + b * b);

		return c <= _circle.radius_ + this->radius_;
	}
};
