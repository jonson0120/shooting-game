#include "StraightBullets.h"
#include "DxLib.h"
#include"common.h"

StraightBullets::StraightBullets(T_Location location, T_Location speed): BulletsBase(location, 5.f, 1, speed)
{
    image = 0;
    BulletsImage = LoadGraph("images/Bullets.png");
    
}

void StraightBullets::Update()
{
    /*T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation);*/

    T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    newLocation.x += speed.x;
    SetLocation(newLocation);
}
void StraightBullets::Draw()
{
    /*DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));*/
    DrawRotaGraph(GetLocation().x, GetLocation().y,1,0,BulletsImage,TRUE);
}

bool StraightBullets::isDeath()
{
    float y = GetLocation().y + GetRadius();
    if (y <= 0 )
    {

        return true;

    }

    y = GetLocation().y - GetRadius();
    if (SCREEN_HEIGHT <= y) 
    {
        return true;
    }

    float x = GetLocation().x + GetRadius();
    if (x <= 0)
    {

        return true;

    }

    x = GetLocation().x - GetRadius();
    if (SCREEN_WINDTH <= x)
    {
        return true;
    }
    return false;
}