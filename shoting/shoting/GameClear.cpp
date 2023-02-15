#include "GameClear.h"
#include"AbstractScene.h"
#include"KeyManager.h"
#include"GameMainScene.h"
#include"Title.h"
#include"GameEnd.h"
GameClear::GameClear()
{
	GameClearImage = LoadGraph("images/GameClear.png");

	GameClearCount = 0;
}

AbstractScene* GameClear::Update()
{
	
	if (KeyManager::OnClick(KEY_INPUT_SPACE))
	{
		return new GameMainScene();
	}


	return this;
}

void GameClear::Draw()const
{
	DrawGraph(0, 0, GameClearImage, FALSE);
}