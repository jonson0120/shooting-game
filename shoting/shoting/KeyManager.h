#pragma once
#include"DxLib.h"

class KeyManager
{
private:
	static int oldKey;  //�O��̓��̓L�[
	static int nowKey;  //����̓��̓L�[

private:
	KeyManager() = default;

public:
	static void Updata()
	{
		oldKey = nowKey;
		nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	}

	//�{�^�����������u��
	static bool OnClick(int inoutKey)
	{
		int KeyFlag = (nowKey & ~oldKey);
		bool ret = (KeyFlag & inoutKey);
		return ret;
	}

	//�{�^���������Ă����
	static bool OnPressed(int inoutKey)
	{
		bool ret = (nowKey & inoutKey);
		return ret;
	}

	//�{�^���𗣂����u��
	static bool OnRelease(int inoutKey)
	{
		int KeyFlag = (oldKey & ~nowKey);
		bool ret = ((~KeyFlag) & inoutKey);
		return ret;
	}
};

