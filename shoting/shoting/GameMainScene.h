#pragma once
#include "AbstractScene.h"
#include"Player.h"
class GameMainScene :public AbstractScene {

private:
	Player*player;

public:
	GameMainScene()
	{
		T_Location location;
		location.x = 10;
		location.y = 100;

		float radius = 10.f;

		player = new Player(location, radius);
	}

	//�f�X�g���N�g
	virtual ~GameMainScene() 
	{
		delete player;
	};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;

};