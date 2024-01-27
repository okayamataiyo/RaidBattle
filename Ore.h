#pragma once
#include "Engine/GameObject.h"

class Ore : public GameObject
{
	int hCircle_;
public:
	Ore(GameObject* _pParent):GameObject(_pParent,"Ore") {}
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

