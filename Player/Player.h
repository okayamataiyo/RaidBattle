#pragma once
#include "../Engine/GameObject.h"
#include "Job/Job.h"
#include "Card/Card.h"
#include <vector>
#include <list>

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    /////////////�I�[�o�[���C�h�֐�//////////////
    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;



    ////////�����o�֐�//////////////////////////

    //�J�[�h��I������
    void SelectCard();

    void SendAttack();


    ///////////////�Z�b�^�[�Q�b�^�[////////////

    int GetHp() { return hp_; }

    void SetPlayerJob(Job* _job) { pJob_ = _job; }

    Job GetPlayerJob() { return pJob_; }

    

private:

    int hModel_;

    Job* pJob_;
    int hp_;
    float speed_;

    //�I�������J�[�h
    Card selectedCard_;

    //�J�[�h�ꗗ�����Ă����H
    std::list<Card> cardList_;

};