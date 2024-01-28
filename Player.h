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

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	Circle GetCircle() { return circle_; }
};

