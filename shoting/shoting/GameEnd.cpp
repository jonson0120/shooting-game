#include "GameEnd.h"
#include"DxLib.h"
GameEnd::GameEnd()
{
	GameEndImage = LoadGraph("images/GameEnd.png");
	Time=0;
}
AbstractScene* GameEnd::Update()
{
	Time++;

	if (180 <= Time)
	{
		return 0;
	}
	return this;
}

void GameEnd::Draw()const
{
	DrawGraph(0, 0, GameEndImage, FALSE);

}
