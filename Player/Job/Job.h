#pragma once
#include "../../Engine/GameObject.h"

/// <summary>
/// �E�Ƃ��Ǘ�����N���X
/// </summary>
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