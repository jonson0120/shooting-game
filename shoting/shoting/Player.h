#pragma once
#include "CharaBase.h"

class Player :public CharaBase, public SphereCollider
{
private:
	int score;  //現在のスコア
	int life;   //

public:
	Player(T_Location location, float radius);

public:
	void Update() override;
	void Draw() override;
	void Hit() override;
	bool LifeCheck();
	int  GetScore();

};

