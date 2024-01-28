#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Direct3D.h"
#include "Engine/ImGui/imgui.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	//モデルのロード
	hModel_ = Model::Load("DebugCollision/BoxCollider.fbx");
	assert(hModel_ >= 0);

	hPoint_ = Model::Load("DebugCollision/Point.fbx");
	assert(hPoint_ >= 0);

	hCircle_ = Model::Load("DebugCollision/CircleCollider.fbx");
	assert(hCircle_ >= 0);

}

void Player::Update()
{

	circle_.center_ = { transform_.position_.x, transform_.position_.z };
	circle_.radius_ = 1.f;

	if (Input::IsKey(DIK_W))transform_.position_.z += 0.1f;
	if (Input::IsKey(DIK_A))transform_.position_.x -= 0.1f;
	if (Input::IsKey(DIK_S))transform_.position_.z -= 0.1f;
	if (Input::IsKey(DIK_D))transform_.position_.x += 0.1f;

	// debug
	ImGui::Text("playerPosition = %f,%f", transform_.position_.x, transform_.position_.z);
}

void Player::Draw()
{
	//モデルの描画
	Direct3D::SetShader(Direct3D::SHADER_UNLIT);
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	Direct3D::SetShader(Direct3D::SHADER_3D);
	Transform pT = transform_;
	pT.position_.y -= 0.5f;
	Model::SetTransform(hPoint_, pT);
	Model::Draw(hPoint_);

	/*Transform cT = transform_;
	cT.position_.y -= 0.5f;
	Model::SetTransform(hCircle_, cT);
	Model::Draw(hCircle_);*/
}

void Player::Release()
{
}