#pragma once
#include"AbstractScene.h"


class GameClear:public AbstractScene
{
private:
	int GameClearImage;
    int GameClearCount;

public:
    // デストラクタ
    ~GameClear() {};
    GameClear();
    //描画以外の更新を実装する
    virtual AbstractScene* Update() override;

    //描画に関することを実装する
    virtual void Draw() const override;
};

