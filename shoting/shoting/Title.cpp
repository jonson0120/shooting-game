#include "Title.h"
#include"KeyManager.h"
#include"GameMainScene.h"
Title::Title()
{
	TitleImage = LoadGraph("images/Title1.png");
}

AbstractScene* Title::Update()
{
	if (KeyManager::OnClick(KEY_INPUT_SPACE))
	{
		return new GameMainScene();
	}
	return this;

}

void Title::Draw()const
{
	DrawGraph(0, 0, TitleImage, FALSE);
}