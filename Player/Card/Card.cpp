#include "Card.h"
#include "../../Engine/Texture.h"

//�R���X�g���N�^
Card::Card(std::string name, int power, std::string texturePath)
{
	texture_ = new Texture;
	cardName_ = name;
	attackPower_ = power;
	texture_->Load(texturePath);

}

//�f�X�g���N�^
Card::~Card()
{
}

//������
void Card::Initialize()
{
}
