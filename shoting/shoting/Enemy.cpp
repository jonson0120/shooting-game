#include "DxLib.h"
#include "Enemy.h"
#include "KeyManager.h"
#include "StraightBullets.h"
#include"CircleBullet.h"
#define PI 3.1415926535897932384626433832795f
#define ATTACK_INTERVAL  10

//エクセルデータの読み込み
void Enemy::inputCSV()
{
    FILE* fp;      //FILE型構造体

    errno_t error;
    error = fopen_s(&fp, "data/text.csv", "r");

    if (error != 0)
    {
        //ファイルが開けてない
        return;

    }
    else
    {
        //ファイルが開けた
        //fgetsは1行読み通る
        char line[100];
        for (int i = 0; fgets(line, 100, fp) != NULL; i++)
        {
            sscanf_s(line, "%d, %f, %f, %d, %d, %d",
                &moveInfo[i].pattern,
                &moveInfo[i].destnation.x,
                &moveInfo[i].destnation.y,
                &moveInfo[i].nextArrayNum,
                &moveInfo[i].waitFrameTime,
                &moveInfo[i].attackType);
                
        }
        return;
    }

    fclose(fp);    //ファイルを閉じる

}



Enemy::Enemy(T_Location location, float radius): SphereCollider(location, radius)
{
    inputCSV();
   
    hp = 10;
    point = 10;
    WaitCount = 0;
    ShotNum = 0;

    Angle=0;

     current = 0;
     waitTime = 0;
     
     EnemyImage = LoadGraph("images/Leonardo.png");

    speed = T_Location{ 2, 2 };

    bullets = new BulletsBase * [30];
    for (int i = 0; i < 30; i++)
    {
        bullets[i] = nullptr;
    }

}

void Enemy::Update()
{
    /*T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation)*/;
    
    Angle++;
    /*if (Angle>=100)
    {
        Angle = 0;
    }*/
    switch (moveInfo[current].pattern)
    {
    case 0:
        Move();
        break;
    case 1:
        waitTime++;
        if (moveInfo[current].waitFrameTime <= waitTime)
        {
            waitTime = 0;
            current = moveInfo[current].nextArrayNum;
        }
        break;

    default:
        break;
    }


    int bulletCount;
    for (bulletCount = 0; bulletCount<30; bulletCount++)
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

    if (moveInfo[current].attackType != 0)
    {
        WaitCount++;
        //ATTACK_INTERVALの値を変えることで弾を出すスピードを変える
        if (ATTACK_INTERVAL <= WaitCount)
        {
            if (bulletCount<30 && bullets[bulletCount] == nullptr)
            {
                WaitCount = 0;
                ShotNum++;
                //止まっているか判断
                if (moveInfo[current].attackType == 1)
                {
                    bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0,2 });
                }
                //動いているか判断
                else if (moveInfo[current].attackType == 2)
                {
                    bullets[bulletCount] = new CircleBullet(GetLocation(), 2.f, (20 * ShotNum));
                }
            }

        }
    }
   

}

void Enemy::Draw()
{
#define _DEBUG_MODE_

#ifdef _DEBUG_MODE_
    DrawFormatString(10, 30, GetColor(255, 255, 255), "hp=%d", this->hp);
#endif 

    DrawFormatString(10, 60, GetColor(255, 255, 255),"%d",Angle/3 );
    //敵
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));


    DrawRotaGraph(GetLocation().x, GetLocation().y,0.5f,Angle/5,EnemyImage,TRUE );


    //弾の
    int bulletCount;
    for (bulletCount = 0; bulletCount<30; bulletCount++)
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

void Enemy::Move() {

    T_Location newLocation = GetLocation();

    //座標が目的地にいるか確認
    if ((newLocation.x == moveInfo[current].destnation.x) &&
        (newLocation.y == moveInfo[current].destnation.y))
    {
        //current更新
        current = moveInfo[current].nextArrayNum;
        return;
    }
    
    else
    {
        //xの座標が目的地と合っているか確認
        if (newLocation.x != moveInfo[current].destnation.x)
        {
            //目的地よりxの座標が小さいかを確認
            if (newLocation.x < moveInfo[current].destnation.x)
            {
                newLocation.x += speed.x;
                //プラスして目的地より大きくなってないかを確認
                if (moveInfo[current].destnation.x < newLocation.x)
                {
                    newLocation.x = moveInfo[current].destnation.x;
                }
            }
            else
            {
                newLocation.x -= speed.x;
                //マイナスして目的地より小さくなってないかを確認
                if (newLocation.x < moveInfo[current].destnation.x)
                {
                    newLocation.x = moveInfo[current].destnation.x;
                }
            }
        }


        //yの座標が目的地と合っているか確認
        if (newLocation.y != moveInfo[current].destnation.y)
        {
            //目的地よりyの座標が小さいかを確認
            if (newLocation.y < moveInfo[current].destnation.y)
            {
                newLocation.y += speed.y;
                //プラスして目的地より大きくなってないかを確認
                if (moveInfo[current].destnation.y < newLocation.y)
                {
                    newLocation.y = moveInfo[current].destnation.y;
                }
            }
            else
            {
                newLocation.y -= speed.y;
                //マイナスして目的地より小さくなってないかを確認
                if (newLocation.y < moveInfo[current].destnation.y)
                {
                    newLocation.y = moveInfo[current].destnation.y;
                }
            }
        }
    }

    SetLocation(newLocation);
}















