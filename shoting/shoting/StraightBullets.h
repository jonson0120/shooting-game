#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
    int image;  // ��U���u

public:
    StraightBullets(T_Location location);  // �R���X�g���N�^

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

