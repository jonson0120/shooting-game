#pragma once
#include"BulletsBase.h"
class StraightBullets1 :public BulletsBase
{
private:
    int image;  // ��U���u

public:

    StraightBullets1(T_Location location1, T_Location speed);  // �R���X�g���N�^

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

