#pragma once
#include "AbstractScene.h"
class GameOver :public AbstractScene
{
private:
	int GameOverImage;

public:
	~GameOver() {};
	GameOver();

	//描画以外の更新を実装する
	virtual AbstractScene* Update() override;
		
	//描画に関することを実装する
	virtual void Draw() const override;
};

