#pragma once
#include "../Engine/GameObject.h"
#include "Job/Job.h"
#include "Card/Card.h"
#include <vector>
#include <list>

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


    ///////////////セッターゲッター////////////

    int GetHp() { return hp_; }

    void SetPlayerJob(Job* _job) { pJob_ = _job; }

    Job GetPlayerJob() { return pJob_; }

    

private:

    int hModel_;

    Job* pJob_;
    int hp_;
    float speed_;

    //選択したカード
    Card selectedCard_;

    //カード一覧を入れておく？
    std::list<Card> cardList_;

};