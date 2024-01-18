#pragma once
#include "../Engine/GameObject.h"
#include "Job/Job.h"
#include "Card/Card.h"
#include <vector>
#include <list>

struct Status {

    char playerName[64];
    int x;
    int y;
    int hp;
    float speed;
    bool isDead;

};

/// <summary>
/// �v���C���[���Ǘ�����N���X
/// </summary>
class Player : public GameObject
{

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    /////////////�I�[�o�[���C�h�����֐�//////////////
    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    ////////�����o�֐�//////////////////////////

    /// <summary>
    /// �J�[�h��I������
    /// </summary>
    void SelectCard();

    /// <summary>
    /// �U��������
    /// </summary>
    void SendAttack();

    /// <summary>
    /// �_���[�W���󂯂�
    /// </summary>
    /// <param name="damage">�󂯂��_���[�W��</param>
    void HitDamage(int damage);

    /// <summary>
    /// ����ł��邩�ǂ���
    /// </summary>
    /// <returns></returns>
    bool isDead() { return status_.isDead; }

    ///////////////�A�N�Z�X�֐�////////////

    Status GetStatus() { return status_; }
    int GetHp() { return status_.hp; }
    void SetHp(int hp) { status_.hp = hp; }
    void SetPos(int x, int y) { status_.x = x; status_.y = y; }

    //////////
    

private:

    int hPlayerModel_;

    //�W���u
    Job* pJob_;
    
    //�v���C���[�̃X�e�[�^�X
    Status status_;

    //�I�������J�[�h
    Card* selectedCard_;

    //�J�[�h�ꗗ�����Ă����H
    std::list<Card*> cardList_;

};