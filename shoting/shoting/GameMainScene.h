#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include"ItemBase.h"
#include"common.h"

class GameMainScene : public AbstractScene
{
private:
    Player* player;
    Enemy** enemy;
    ItemBase** items;
public:

    GameMainScene()
    {

        T_Location location;
        location.x = SCREEN_WINDTH / 2;
        location.y = 600;

        float radius = 22.f;
        
        player = new Player(location, radius);

        enemy = new Enemy * [10];
        for (int i = 0; i < 10; i++)
        {
            enemy[i] = nullptr;
        }
        enemy[0] = new Enemy(T_Location{ SCREEN_WINDTH/2, SCREEN_HEIGHT/2 }, 50);

        items = new ItemBase*[10];
        for (int i = 0; i < 10; i++) {
            items[i] = nullptr;
        }
    }


    // �f�X�g���N�^
    virtual ~GameMainScene()
    {
        delete player;
    };

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};