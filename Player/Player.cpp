#include "Player.h"
#include "Card/Card.h"
#include "Job/Job.h"

namespace {
    int PLAYER_HP = 100;
    char PLAYER_NAME[64] = "noname";
}

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
    status_ = { "noname",0,0,PLAYER_HP,1.0f,false };

}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
}

//�X�V
void Player::Update()
{
}

//�`��
void Player::Draw()
{
}

//�J��
void Player::Release()
{
}

void Player::SelectCard()
{


}

void Player::SendAttack()
{
}

void Player::HitDamage(int damage)
{

    status_.hp -= damage;

    if (status_.hp <= 0) {
        status_.isDead = true;
    }
}

