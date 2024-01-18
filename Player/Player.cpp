#include "Player.h"
#include "Card/Card.h"
#include "Job/Job.h"
#include "../Engine/Model.h"

namespace {
    int PLAYER_HP = 100;
    char PLAYER_NAME[64] = "noname";
}

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hPlayerModel_(-1), selectedCard_(nullptr)
{
    status_ = { "noname",0,0,PLAYER_HP,1.0f,false };

    //カードを作成する
    for (int i = 0; i < 2; i++) {
        
        Card* card = Instantiate<Card>(this);
        card->SetCardType(CardType::ATTACK);
        card->SetCardID(i);
        cardList_.push_back(card);

    }
    
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    hPlayerModel_ = Model::Load("PlayerFbx/player.fbx");
    assert(hPlayerModel_ <= 0);
   


}

//更新
void Player::Update()
{

}

//描画
void Player::Draw()
{

    Model::SetTransform(hPlayerModel_, transform_);
    Model::Draw(hPlayerModel_);

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

