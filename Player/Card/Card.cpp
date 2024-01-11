#include "Card.h"
#include "../../Engine/Texture.h"

//コンストラクタ
Card::Card(std::string name, int power, std::string texturePath)
{
	texture_ = new Texture;
	cardName_ = name;
	attackPower_ = power;
	texture_->Load(texturePath);

}

//デストラクタ
Card::~Card()
{
}

//初期化
void Card::Initialize()
{
}
