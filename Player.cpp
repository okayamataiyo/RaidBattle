#include "Player.h"
#include "Engine/Model.h"
#include "Engine/ImGui/imgui.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	//���f���̃��[�h
	hModel_ = Model::Load("DebugCollision/BoxCollider.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	//���W�̊m�F�p�ړ������FImGui
	DebugMove();
}

void Player::Draw()
{
	//���f���̕`��
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::DebugMove()
{
	//ImGui::�v���C���[�̈ړ�
	ImGui::Begin("Player"); {
		if (ImGui::CollapsingHeader("position_")) {
			ImGui::SliderFloat("position_x", &transform_.position_.x, -10.0f, 10.0f);
			ImGui::SliderFloat("position_y", &transform_.position_.y, -10.0f, 10.0f);
			ImGui::SliderFloat("position_z", &transform_.position_.z, -10.0f, 10.0f);
		}
	}ImGui::End();
}
