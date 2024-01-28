#pragma once
#include "Engine/GameObject.h"


//テストシーンを管理するクラス
class TestScene2 : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TestScene2(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};