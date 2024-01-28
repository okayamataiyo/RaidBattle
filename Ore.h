#pragma once
#include "Engine/GameObject.h"
#include "Circle.h"


class Ore : public GameObject
{
	int hCircle_;
	Circle circle_;
public:
	Ore(GameObject* _pParent):GameObject(_pParent,"Ore"){}
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	Circle GetCircle() { return circle_; }
};

