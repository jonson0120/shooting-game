#pragma once
#include "AbstractScene.h"
#include"Player.h"
class GameMainScene :public AbstractScene {

private:
	Player player;

public:
	GameMainScene{

	}

	//�f�X�g���N�g
	virtual ~GameMainScene() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;

};