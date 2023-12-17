#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
	int hModel_;
public:
	Player(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

private:
	void DebugMove();
};

