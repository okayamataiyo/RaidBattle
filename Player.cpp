#include "Player.h"
#include "Engine/Model.h"

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
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
