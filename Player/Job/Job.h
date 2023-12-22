#pragma once
#include "../../Engine/GameObject.h"

//職業を管理するクラス
class Job : public GameObject
{

public:
    //コンストラクタ
    Job(GameObject* parent);

    //デストラクタ
    ~Job();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};