#include "Ore.h"

#include "Engine/Model.h"
#include "Player.h"
#include "Engine/ImGui/imgui.h"

void Ore::Initialize()
{
    hCircle_ = Model::Load("DebugCollision/CircleCollider.fbx");
    assert(hCircle_ >= 0);
    transform_.position_.y -= 0.5f;	
	transform_.scale_ = { 2.f,1.f,2.f };
}

void Ore::Update()
{
	circle_.center_ = { transform_.position_.x, transform_.position_.z };
	circle_.radius_ = 2.f;

	Player* pP = (Player*)FindObject("Player");

	std::string res;
	if (circle_.ContainsPoint(XMFLOAT2(pP->GetPosition().x, pP->GetPosition().z))) {
		ImGui::Text("OverlapCircle = true");
	}
	else
		ImGui::Text("OverlapCircle = false");
}

void Ore::Draw()
{
    Model::SetTransform(hCircle_, transform_);
    Model::Draw(hCircle_);
}

void Ore::Release()
{
}
