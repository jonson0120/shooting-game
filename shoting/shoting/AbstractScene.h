#pragma once
#include<stdio.h>
//�f�t�H���g�̒��o�V�[���N���X
//���[�U�[�͂�����p�����ăV�[����������Ɗy
class AbstractScene {
public:

	//�f�X�g���N�g
	virtual ~AbstractScene() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const = 0;
};

