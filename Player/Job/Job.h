#pragma once
#include "../../Engine/GameObject.h"

//�E�Ƃ��Ǘ�����N���X
class Job : public GameObject
{

public:
    //�R���X�g���N�^
    Job(GameObject* parent);

    //�f�X�g���N�^
    ~Job();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};