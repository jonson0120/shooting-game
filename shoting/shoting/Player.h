#pragma once
#include "CharaBase.h"

class Player : public CharaBase, public SphereCollider
{
private:
    int score;  // ���݃X�R�A
    int life;   // HP

    int time;

    int PlayerImage;
public:
    Player(T_Location location, float radius);

public:
    void Update() override;
    void Draw() override;
    void Hit()override;
    void Hit(int bulletsCount);

    void Hit(class BulletsBase* bullets);
    void Hit(class ItemBase* item);

    bool LifeCheck();
    int GetScore();
    void addScore(int point);
};

