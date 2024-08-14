#pragma once
#include "Application.h"

class InGameUI
	: public Script
{
public:
	void Start();
	void Update();
protected:
private:
	SpriteRenderer2D* humanListKeySprite;
	SpriteRenderer2D* pauseKeySprite;

	Actor* timeUI;
	Actor* skillUI;
	Actor* skillGaugeUI;
	Actor* HumanListUI;
};

    