#pragma once
#include "AbstractScene.h"
class Title :  public AbstractScene
{
private:
    int TitleImage;

public:
    // �f�X�g���N�^
    ~Title() {};
    Title();
    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};

