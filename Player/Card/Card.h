#pragma once
#include "../../Engine/GameObject.h"

struct CardStatus {
    
};

class Texture;

/// <summary>
/// プレイヤーが使うカードを管理する基底クラス
/// </summary>
class Card
{
protected:


public:
    //コンストラクタ
    Card(std::string name,int power, std::string texturePath);

    //デストラクタ
    ~Card();

    //初期化
    void Initialize();

private:

    char cardName_[64];
    int attackPower_;
    Texture* texture_;


};