#pragma once
#include "AbstractScene.h"
class GameEnd :public AbstractScene
{
private:
    int GameEndImage;
    int Time;
    

public:
    // �f�X�g���N�^
    ~GameEnd() {};
    GameEnd();
    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};


