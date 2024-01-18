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

/// <summary>
/// プレイヤーを管理するクラス
/// </summary>
class Player : public GameObject
{

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    /////////////オーバーライドした関数//////////////
    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    ////////メンバ関数//////////////////////////

    /// <summary>
    /// カードを選択する
    /// </summary>
    void SelectCard();

    /// <summary>
    /// 攻撃をする
    /// </summary>
    void SendAttack();

    /// <summary>
    /// ダメージを受けた
    /// </summary>
    /// <param name="damage">受けたダメージ量</param>
    void HitDamage(int damage);

    /// <summary>
    /// 死んでいるかどうか
    /// </summary>
    /// <returns></returns>
    bool isDead() { return status_.isDead; }

    ///////////////アクセス関数////////////

    Status GetStatus() { return status_; }
    int GetHp() { return status_.hp; }
    void SetHp(int hp) { status_.hp = hp; }
    void SetPos(int x, int y) { status_.x = x; status_.y = y; }

    //////////
    

private:

    int hPlayerModel_;

    //ジョブ
    Job* pJob_;
    
    //プレイヤーのステータス
    Status status_;

    //選択したカード
    Card* selectedCard_;

    //カード一覧を入れておく？
    std::list<Card*> cardList_;

};