#pragma once
#include "../Engine/GameObject.h"
#include "AI.h"

//�e�X�g�V�[�����Ǘ�����N���X
class MetaAI : public AI
{

public:

	//�R���X�g���N�^
	MetaAI(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};