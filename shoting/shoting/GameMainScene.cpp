#include "GameMainScene.h"
#include"AbstractScene.h"
AbstractScene* GameMainScene::Update() {
	
	player->Update();
	//�������g�̃|�C���^
	return this;
}
void GameMainScene::Draw()const {
	player->Draw();
}