#pragma once
#include "../Engine/GameObject.h"
#include "Job/Job.h"
#include "Card/Card.h"
#include <vector>
#include <list>

struct Status {

    char playerName[64];
    int x;
    int y;
    int hp;
    float speed;
    bool isDead;

};


//プレイヤーを管理するクラス
class Player : public GameObject
{

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    /////////////オーバーライド関数//////////////
    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    ////////メンバ関数//////////////////////////

    //カードを選択する
    void SelectCard();

    void SendAttack();

    void HitDamage(int damage);

    bool isDead() { return status_.isDead; }

    ///////////////アクセス関数////////////

    Status GetStatus() { return status_; }
    int GetHp() { return status_.hp; }
    void SetHp(int hp) { status_.hp = hp; }
    void SetPos(int x, int y) { status_.x = x; status_.y = y; }

    //////////
    

private:

    int hModel_;

    Job* pJob_;
    
    Status status_;

    //選択したカード
    Card* selectedCard_;

    //カード一覧を入れておく？
    std::list<Card*> cardList_;

};