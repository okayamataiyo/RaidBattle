#include "Player.h"
#include "Engine/Model.h"


Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	//モデルのロード
	hModel_ = Model::Load("DebugCollision/BoxCollider.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	//座標の確認用移動処理：ImGui
	DebugMove();
}

void Player::Draw()
{
	//モデルの描画
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}