#include "SphereCollider.h"
#include<math.h>

bool  SphereCollider::HitSphere(SphereCollider s)  //�q�b�g����
{
	//�~�Ɖ~�̓����蔻��
	//�����̃x�N�g���|����̃x�N�g��
	
	
	T_Location location = s.GetLocation();
	float x = this->location.x - location.x;
	float y = this->location.y - location.y;

	//��Βl�ɕϊ�
	x = x < 0 ? -x : x;
	y = y < 0 ? -y : y;


	//�x�N�g���̑傫��
	float x2 = x * x;
	float y2 = y * y;
	float xy = x2 + y2;
	double vectorSize = sqrt(xy);

	//�����̔��a�{����̔��a�@��菬�������������Ă���
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