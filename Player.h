#pragma once
#include "Engine/GameObject.h"
#include "Circle.h"

class Player : public GameObject
{
	int hModel_;
	int hPoint_;
	int hCircle_;
	Circle circle_;
public:
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	Circle GetCircle() { return circle_; }
};

