#pragma once
#include "CharaBase.h"

struct T_MoveInfomation
{
    int pattern;             //行動パターン
    T_Location destnation;   //目的地
    int nextArrayNum;        //次の配列番号
    int waitFrameTime;       //持ち時間
    int attackType;       //攻撃の種類
};

class Enemy : public CharaBase, public SphereCollider
{


private:
    int hp;
    int point;
    int WaitCount;
    int ShotNum;

    int Angle;

    int current = 0;
    int waitTime = 0;
    int EnemyImage;
    //移動座標
    T_MoveInfomation moveInfo[8] = {};


public:

    Enemy(T_Location location, float radius);

public:

    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit()override;
    virtual void Hit(int damage);
    bool HpCheck();
    int GetPoint();
    void DeletaBullet(int bulletCount);
    void inputCSV();
    void Move();
};



//0	640	150	1	0	0
//0	1200.4	150	2	0	2
//0	600	400	3	300	1
//0	80.2	150	4	0	2
//1	0	0	5	300	1
//0	300	300	1	0	2

