#pragma once
#include "AbstractScene.h"
class GameEnd :public AbstractScene
{
private:
    int GameEndImage;
    int Time;
    

public:
    // デストラクタ
    ~GameEnd() {};
    GameEnd();
    //描画以外の更新を実装する
    virtual AbstractScene* Update() override;

    //描画に関することを実装する
    virtual void Draw() const override;
};


