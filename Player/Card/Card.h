#pragma once
#include "../../Engine/GameObject.h"

struct CardStatus {
    
};

enum CardType {
    ATTACK,
    DEFENSE,
    NUM
};

class Texture;

/// <summary>
/// プレイヤーが使うカードを管理する基底クラス
/// </summary>
class Card : public GameObject
{
    //カードのモデル
    int hModel_;

    //カードの識別番号的な
    int cardID_;

protected:

    //攻撃力
    int attackPower_;

    //カードのタイプ
    CardType type_;

    //カードのテクスチャ
    Texture* pTexture_;

public:
    //コンストラクタ
    Card(GameObject* parent);

    //デストラクタ
    ~Card();

    //初期化
    virtual void Initialize() override;

    //初期化
    virtual void Update() override;

    //初期化
    virtual void Draw() override;

    //初期化
    virtual void Release() override;


    ///////////アクセス関数//////////

    void SetCardType(CardType type) { type_ = type; }
    void SetCardID(int ID) { cardID_ = ID; }
    void SetAttackPower(int attack) { attackPower_ = attack; }
    CardType GetCardType() { return type_; }
    int GetCardID() { return cardID_; }
    int GetAttackPower() { return attackPower_; }

private:



    


};