#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
    int image;  // ��U���u

    int BulletsImage;
public:

    StraightBullets(T_Location location, T_Location speed);  // �R���X�g���N�^

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

