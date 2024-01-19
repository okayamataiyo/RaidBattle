#pragma once
#include "../../Engine/GameObject.h"

struct CardStatus {
    
};

enum CardType {
    ATTACK,
    DEFENSE,
    NUM
};

class Texture;

/// <summary>
/// �v���C���[���g���J�[�h���Ǘ�������N���X
/// </summary>
class Card : public GameObject
{
    //�J�[�h�̃��f��
    int hModel_;

    //�J�[�h�̎��ʔԍ��I��
    int cardID_;

protected:

    //�U����
    int attackPower_;

    //�J�[�h�̃^�C�v
    CardType type_;

    //�J�[�h�̃e�N�X�`��
    Texture* pTexture_;

public:
    //�R���X�g���N�^
    Card(GameObject* parent);

    //�f�X�g���N�^
    ~Card();

    //������
    virtual void Initialize() override;

    //������
    virtual void Update() override;

    //������
    virtual void Draw() override;

    //������
    virtual void Release() override;


    ///////////�A�N�Z�X�֐�//////////

    void SetCardType(CardType type) { type_ = type; }
    void SetCardID(int ID) { cardID_ = ID; }
    void SetAttackPower(int attack) { attackPower_ = attack; }
    CardType GetCardType() { return type_; }
    int GetCardID() { return cardID_; }
    int GetAttackPower() { return attackPower_; }

private:



    


};