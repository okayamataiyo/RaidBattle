#pragma once
#include "../../Engine/GameObject.h"

//◆◆◆を管理するクラス
class Card : public GameObject
{

public:
    //コンストラクタ
    Card(GameObject* parent);

    //デストラクタ
    ~Card();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};