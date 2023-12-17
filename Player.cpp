#include "Player.h"
#include "Engine/Model.h"
#include "Engine/ImGui/imgui.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	//ƒ‚ƒfƒ‹‚Ìƒ[ƒh
	hModel_ = Model::Load("DebugCollision/BoxCollider.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	ImGui::Begin("Player"); {
		if (ImGui::CollapsingHeader("position_")) {
			ImGui::SliderFloat("position_x", &transform_.position_.x, -10.0f, 10.0f);
			ImGui::SliderFloat("position_y", &transform_.position_.y, -10.0f, 10.0f);
			ImGui::SliderFloat("position_z", &transform_.position_.z, -10.0f, 10.0f);
		}
	}ImGui::End();
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
