#include "DxLib.h"
#include "Enemy.h"
#include "KeyManager.h"
#include "StraightBullets.h"

#define ATTACK_INTERVAL 30

Enemy::Enemy(T_Location location, float radius): SphereCollider(location, radius)
{
    hp = 10;
    point = 10;
    WaitCount = 0;

    speed = T_Location{ 0, 0.5 };

    bullets = new BulletsBase * [30];
    for (int i = 0; i < 30; i++)
    {
        bullets[i] = nullptr;
    }

}

void Enemy::Update()
{
    T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation);

    int bulletCount;
    for (bulletCount = 0; bulletCount < 30; bulletCount++)
    {
        if (bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Update();

        if (bullets[bulletCount]->isDeath())
        {
            DeletaBullet(bulletCount);
            bulletCount--;
           
        }
    }

    WaitCount++;
    //ATTACK_INTERVALの値を変えることで弾を出すスピードを変える
    if (ATTACK_INTERVAL <= WaitCount)
    {
        if (bulletCount < 30 && bullets[bulletCount] == nullptr)
        {
            WaitCount = 0;

            //一個目と二個目は同じGetLocationを使ってるので一個目の文が使えない(?)
            //だからただ複製して、T_Locationの値を変えても変化しない

            bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0,2 });
            //bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0.3,2 });

        }

    }
   
    if (hp <= 8)
    {
        if (bulletCount < 30 && bullets[bulletCount] == nullptr)
        {
                       bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0.3,2 });

        }
    }
    
    
}

void Enemy::Draw()
{

    //敵
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));


    //弾の
    int bulletCount;
    for (bulletCount = 0; bulletCount < 30; bulletCount++)
    {
        if (bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Draw();
    }
    
}


void Enemy::Hit() {

}

void Enemy::Hit(int damege)
{

    if (0 < damege)
    {
        hp -= damege;
        if (hp < 0) 
        {
            hp = 0;
        }
    }

}

bool Enemy::HpCheck()
{

    bool ret = (hp <= 0);
    return ret;

}

int Enemy::GetPoint()
{

    return point;

}

void Enemy::DeletaBullet(int bulletCount)
{

    delete bullets[bulletCount];
    bullets[bulletCount] = nullptr;
    
    for (int i = (bulletCount + 1); i < 30; i++)
        {
            if (bullets[i] == nullptr)
            {
                break;
            }
            bullets[i - 1] = bullets[i];
            bullets[i] = nullptr;
     }
}