#pragma once
#include "../Engine/GameObject.h"

//テストシーンを管理するクラス
class AI : public GameObject
{

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	AI(GameObject* parent, std::string name);

	//初期化
	virtual void Initialize() override;

	//更新
	virtual void Update() override;

	//描画
	virtual void Draw() override;

	//開放
	virtual void Release() override;
};