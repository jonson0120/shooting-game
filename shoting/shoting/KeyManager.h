#pragma once
#include"DxLib.h"

class KeyManager
{
private:
	static int oldKey;  //前回の入力キー
	static int nowKey;  //今回の入力キー

private:
	KeyManager() = default;

public:
	static void Updata()
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	}

	//ボタンを押した瞬間
	static bool OnClick(int inoutKey)
	{
		int KeyFlag = (nowKey & ~oldKey);
		bool ret = (KeyFlag & inoutKey);
		return ret;
	}

	//ボタンを押している間
	static bool OnPressed(int inoutKey)
	{
		bool ret = (nowKey & inoutKey);
		return ret;
	}

	//ボタンを離した瞬間
	static bool OnRelease(int inoutKey)
	{
		int KeyFlag = (oldKey & ~nowKey);
		bool ret = ((~KeyFlag) & inoutKey);
		return ret;
	}
};

