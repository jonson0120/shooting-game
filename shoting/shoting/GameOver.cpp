#include "GameOver.h"
#include"KeyManager.h"
#include"GameMainScene.h"
#include"Title.h"
#include"GameEnd.h"

GameOver::GameOver()
{
	GameOverImage = LoadGraph("images/GameOver.png");
}

AbstractScene* GameOver::Update()
{
	if (KeyManager::OnClick(KEY_INPUT_SPACE))
	{
		return new GameEnd();
	}
	return this;
}

void GameOver::Draw()const
{
	DrawGraph(0, 0, GameOverImage, FALSE);
}