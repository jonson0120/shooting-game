#include "HpPotion.h"
#include"DxLib.h"

HpPotion::HpPotion(T_Location location) :ItemBase(location, 5.f, E_ITEM_TYPE::HP_POTION, T_Location{0,0.5f}),HealPower(2)
{
    
}
void HpPotion::Update() 
{

    T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation);

}
void HpPotion::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(250, 0, 0));
}
int HpPotion::GetHealPower()
{
    return HealPower;
}

