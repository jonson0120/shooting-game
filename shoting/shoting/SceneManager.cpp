#include "SceneManager.h"
AbstractScene* SceneManager::Update() {
	AbstractScene* NextScene = mScene->Update();
	if (NextScene != mScene) {
		delete mScene;
		mScene = NextScene;
	}
	return NextScene;
}
void SceneManager::Draw()const {
	mScene->Draw();
}