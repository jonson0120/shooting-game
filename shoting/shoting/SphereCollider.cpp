#include "SphereCollider.h"
#include<math.h>

SphereCollider::SphereCollider(T_Location location, float radius) {

	this->location.x = location.x;
	this->location.y = location.y;

	this->radius = radius;
}

bool  SphereCollider::HitSphere(SphereCollider s)  //ƒqƒbƒg”»’è
{
	//‰~‚Æ‰~‚Ì“–‚½‚è”»’è
	//Ž©•ª‚ÌƒxƒNƒgƒ‹|‘ŠŽè‚ÌƒxƒNƒgƒ‹
	
	
	T_Location location = s.GetLocation();
	float x = this->location.x - location.x;
	float y = this->location.y - location.y;

	//â‘Î’l‚É•ÏŠ·
	x = fabsf(x);
	y = fabsf(y);


	//ƒxƒNƒgƒ‹‚Ì‘å‚«‚³
	float xy = (x * x) + (y * y);
	double vectorSize = sqrt(xy);

	//Ž©•ª‚Ì”¼Œa{‘ŠŽè‚Ì”¼Œa@‚æ‚è¬‚³‚¢Žž“–‚½‚Á‚Ä‚¢‚é
	double radius = this->radius + s.GetRadius();

	bool ret = (vectorSize <= radius);
	return radius;
}
float SphereCollider::GetRadius()
{
	return radius;
}
T_Location SphereCollider::GetLocation()
{
	return location;
}
void SphereCollider::SetLocation(T_Location value)
{
	location.x = value.x;
	location.y = value.y;
}