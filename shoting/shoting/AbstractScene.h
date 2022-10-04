#pragma once
#include<stdio.h>
//デフォルトの抽出シーンクラス
//ユーザーはこれを継承してシーン実装すると楽
class AbstractScene {
public:

	//デストラクト
	virtual ~AbstractScene() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw() const = 0;
};

