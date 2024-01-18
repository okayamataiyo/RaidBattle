#include "Card.h"
#include "../../Engine/Texture.h"
#include "../../Engine/Model.h"
#include "../../Engine/Global.h"

//コンストラクタ
Card::Card(GameObject* parent)
	:GameObject(parent, "Card"),hModel_(-1)
{
	//pTexture_ = new Texture;
	attackPower_ = 10;
	//texture_->Load(texturePath);

}

//デストラクタ
Card::~Card()
{
}

//初期化
void Card::Initialize()
{
	hModel_ = Model::Load("PlayerFbx/Card.fbx");
	assert(hModel_ <= 0);
}

void Card::Update()
{
}

void Card::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Card::Release()
{
	SAFE_DELETE(pTexture_);
}
