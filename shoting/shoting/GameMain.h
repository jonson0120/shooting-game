#pragma once
#include"AbstractScene.h"
#include"Player.h"
class GameMain :public AbstractScene {

public:
	GameMain() {

	}
	
	//デストラクト
	virtual ~GameMain() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	//描画に関することを実装する
	virtual void Draw()const override;

};
