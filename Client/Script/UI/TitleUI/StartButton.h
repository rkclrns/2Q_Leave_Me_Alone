#pragma once
#include "../ButtonUI.h"

class StartButton
	: public ButtonUI
{
public:
	void Start();
	void Update();
	void OnPlayerEnter();
	void OnPlayerStay();
	void OnPlayerExit();

	bool isPlayer = false;

protected:
	int buttonState;

	// 임시로 만듬 나중엔 MainSprite 사용
	RectRenderer* rect;
	// SpriteRenderer2D* button;

private:
};

