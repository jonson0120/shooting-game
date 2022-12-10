//#include "StraightBullets1.h"
//
//#include "StraightBullets.h"
//#include "DxLib.h"
//#include"common.h"
//
//StraightBullets1::StraightBullets1(T_Location location1, T_Location speed)
//    : BulletsBase(location1, 5.f, 1, speed)
//{
//    image = 0;
//}
//
//void StraightBullets1::Update()
//{
//
//    T_Location newLocation = GetLocation1();
//    newLocation.y1 += speed.y;
//    newLocation.x1 += speed.x;
//    SetLocation(newLocation);
//
//}
//void StraightBullets1::Draw()
//{
//    DrawCircle(GetLocation1().x1, GetLocation1().y1, GetRadius(), GetColor(0, 255, 0));
//}
//
//bool StraightBullets1::isDeath()
//{
//    float y1 = GetLocation1().y1 + GetRadius();
//    if (y1 <= 0)
//    {
//
//        return true;
//
//    }
//
//    y1 = GetLocation1().y1 - GetRadius();
//    if (SCREEN_HEIGHT <= y1)
//    {
//        return true;
//    }
//
//    float x1 = GetLocation1().x1 + GetRadius();
//    if (x1 <= 0)
//    {
//
//        return true;
//
//    }
//
//    x1 = GetLocation1().x1 - GetRadius();
//    if (SCREEN_WINDTH <= x1)
//    {
//        return true;
//    }
//    return false;
//}
