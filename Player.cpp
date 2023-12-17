#include "Player.h"
#include "Engine/Model.h"


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