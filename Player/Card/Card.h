#pragma once
#include "../../Engine/GameObject.h"

struct CardStatus {
    
};

class Texture;

/// <summary>
/// �v���C���[���g���J�[�h���Ǘ�����N���X
/// </summary>
class Card
{
private:


public:
    //�R���X�g���N�^
    Card(std::string name,int power, std::string texturePath);

    //�f�X�g���N�^
    ~Card();

    //������
    void Initialize();

private:

    char cardName_[64];
    int attackPower_;
    Texture* texture_;


};