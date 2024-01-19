#include "Player.h"
#include "Card/Card.h"
#include "Job/Job.h"
#include "Card/CardType/Attack.h"
#include "../Engine/Model.h"
#include "../Engine/Global.h"
#include "../Engine/Input.h"

namespace {
    int PLAYER_HP = 100;
    int PLAYER_ATTACK = 10;
    char PLAYER_NAME[64] = "noname";
}

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hPlayerModel_(-1), selectedCard_(nullptr),metaAI_(nullptr)
{
    status_ = { "noname",0,0,PLAYER_HP, PLAYER_ATTACK,1.0f,false };

    metaAI_ = Instantiate<MetaAI>(this);

    //カードを作成する
    for (int i = 0; i < 2; i++) {
        
        Card* card = Instantiate<Card>(this);
        card->SetCardType(CardType::ATTACK);
        card->SetCardID(i);

        XMFLOAT3 cardPos(transform_.position_);
        transform_.position_.z -= 5.0f;
        transform_.position_.x -= 5.0f;
        transform_.position_.x += i * 3;
        card->SetPosition(transform_.position_);

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

    if (Input::IsKeyDown(DIK_1)) {

        SelectCard(0);
    }

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

    SAFE_RELEASE(selectedCard_);
    SAFE_RELEASE(metaAI_);

    for (auto it = cardList_.begin(); it != cardList_.end(); it++) {

        (*it)->ReleaseSub();
        SAFE_DELETE(*it);
    }

   
}

//選択されたIDのカードを選んで攻撃して新しくカードをセットする
void Player::SelectCard(int ID)
{
    
    selectedCard_ = cardList_.at(ID);

    SendAttack(selectedCard_->GetAttackPower() + status_.baseAttackPower);

    cardList_.at(ID)->Release();
    SAFE_DELETE(cardList_.at(ID));

    //cardList_.at(ID) = metaAI_->
}

void Player::SendAttack(int damage)
{

    //サーバに情報を渡す処理

}

void Player::HitDamage(int damage)
{

    status_.hp -= damage;

    if (status_.hp <= 0) {
        status_.isDead = true;
    }
}

