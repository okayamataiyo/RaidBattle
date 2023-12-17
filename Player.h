#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
	int hModel_;
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

private:
	void DebugMove();
};

