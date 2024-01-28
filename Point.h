#pragma once
#include "Engine/GameObject.h"
class Point : public GameObject
{
	int hModel_;
public:
	Point(GameObject* _pParent) :GameObject(_pParent, "Point") {}
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

