#include "Point.h"
#include "Engine/Model.h"

void Point::Initialize()
{
	hModel_ = Model::Load("DebugCollision/Point.fbx");
	transform_.position_.y -= 0.5f;
}

void Point::Update()
{
}

void Point::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Point::Release()
{
}
