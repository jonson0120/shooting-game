#pragma once
#include"AbstractScene.h"


class GameClear:public AbstractScene
{
private:
	int GameClearImage;
    int GameClearCount;

public:
    // �f�X�g���N�^
    ~GameClear() {};
    GameClear();
    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};

