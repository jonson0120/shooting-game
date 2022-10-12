#pragma once
#include "SphereCollider.h"


class CharaBase 
{
private:

	T_Location speed;  //�ړ����x

protected:
	int* image=nullptr;  //�`�悷��摜

	//�ϐ��F
	//�Ebullets(�|�C���^�z��)

public:
	
	virtual ~CharaBase();

public:
	 virtual void Update() = 0;
	 virtual void Draw() = 0;
	 virtual void Hit() = 0;

	T_Location GetSpeed();
	 void SetSpeed(T_Location speed);
	//�֐��F
	//�EGetBullets()

};
