#pragma once
#include "AbstractScene.h"
class GameMainScene :public AbstractScene {



	//�f�X�g���N�g
	virtual ~GameMainScene() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;

};