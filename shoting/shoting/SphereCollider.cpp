#include "SphereCollider.h"
#include <math.h>

SphereCollider::SphereCollider(T_Location location, float radius)
{
    this->location.x = location.x;
    this->location.y = location.y;

    
    this->radius = radius;

}

bool SphereCollider::HitSphere(SphereCollider* s)
{

    // �~�Ɖ~�̓����蔻��
    // �������瑊��ւ̃x�N�g�������߂�
    T_Location location = s->GetLocation();
    float x = this->location.x - location.x;
    float y = this->location.y - location.y;

   
    // ��Βl�ɕϊ�
    x = fabsf(x);
    y = fabsf(y);

    
    // �x�N�g���̑傫�����擾�@��(x*x) + (y*y) 
    float xy = (x * x) + (y * y);
    double vectorSize = sqrt(xy);

  
    // �����̔��a�@�{�@����̔��a�@���擾
    float radius = this->radius + s->GetRadius();

    // �x�N�g���̑傫���@�����@���v�̔��a�@�̎��������Ă�
    bool ret = (vectorSize <= radius);
    return ret;

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

