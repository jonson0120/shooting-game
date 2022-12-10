#pragma once
#include"BulletsBase.h"
class StraightBullets1 :public BulletsBase
{
private:
    int image;  // 一旦放置

public:

    StraightBullets1(T_Location location1, T_Location speed);  // コンストラクタ

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

