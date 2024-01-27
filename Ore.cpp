#include "Ore.h"

#include "Engine/Model.h"
#include "Player.h"
#include "Engine/ImGui/imgui.h"

class Circle {
public:
	XMFLOAT2 center_;
	float radius_;

	Circle(float _cX, float _cY, float _radius)
		:center_{ _cX,_cY }, radius_(_radius) {}

	bool ContainsPoint(const XMFLOAT2& _point) {
		float a = _point.x - center_.x;
		float b = _point.y - center_.y;
		float c = sqrt(a * a + b * b);

		return c <= radius_;
	}
};

void Ore::Initialize()
{
    hCircle_ = Model::Load("DebugCollision/CircleCollider.fbx");
    assert(hCircle_ >= 0);
    transform_.position_.y -= 0.5f;
}

void Ore::Update()
{
	Circle circle(transform_.position_.x, transform_.position_.z, 1.f);

	Player* pP = (Player*)FindObject("Player");
	XMFLOAT2 pPos = { pP->GetPosition().x , pP->GetPosition().z };
	
	std::string res;
	if (circle.ContainsPoint(pPos)) {
		ImGui::Text("ContainsPoint = true");
	}
	else
		ImGui::Text("ContainsPoint = false");
}

void Ore::Draw()
{
    Model::SetTransform(hCircle_, transform_);
    Model::Draw(hCircle_);
}

void Ore::Release()
{
}
