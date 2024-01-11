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

    void HitDamage(int damage);

    bool isDead() { return status_.isDead; }

    ///////////////�A�N�Z�X�֐�////////////

    Status GetStatus() { return status_; }
    int GetHp() { return status_.hp; }
    void SetHp(int hp) { status_.hp = hp; }
    void SetPos(int x, int y) { status_.x = x; status_.y = y; }

    //////////
    

private:

    int hModel_;

    Job* pJob_;
    
    Status status_;

    //�I�������J�[�h
    Card* selectedCard_;

    //�J�[�h�ꗗ�����Ă����H
    std::list<Card*> cardList_;

};