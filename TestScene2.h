#pragma once
#include "Engine/GameObject.h"


//�e�X�g�V�[�����Ǘ�����N���X
class TestScene2 : public GameObject
{
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TestScene2(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};