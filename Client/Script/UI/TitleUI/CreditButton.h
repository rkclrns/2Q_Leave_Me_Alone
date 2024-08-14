#pragma once
#include "../ButtonUI.h"

class CreditButton
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

	// �ӽ÷� ���� ���߿� MainSprite ���
	RectRenderer* rect;
	// SpriteRenderer2D* button;

private:
};

