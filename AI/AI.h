#pragma once
#include "../Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class AI : public GameObject
{

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	AI(GameObject* parent, std::string name);

	//������
	virtual void Initialize() override;

	//�X�V
	virtual void Update() override;

	//�`��
	virtual void Draw() override;

	//�J��
	virtual void Release() override;
};