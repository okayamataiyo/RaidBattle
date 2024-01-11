#include "Player.h"
#include "Card/Card.h"
#include "Job/Job.h"

namespace {
    int PLAYER_HP = 100;
    char PLAYER_NAME[64] = "noname";
}

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
    status_ = { "noname",0,0,PLAYER_HP,1.0f,false };

}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
}

//更新
void Player::Update()
{
}

//描画
void Player::Draw()
{
}

//開放
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

