#pragma once
#include "../../Engine/GameObject.h"

//���������Ǘ�����N���X
class Card : public GameObject
{

public:
    //�R���X�g���N�^
    Card(GameObject* parent);

    //�f�X�g���N�^
    ~Card();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};