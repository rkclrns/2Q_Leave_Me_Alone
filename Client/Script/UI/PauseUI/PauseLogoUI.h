#pragma once
#include "Script/UI/PauseUI/PauseUIBase.h"

class PauseLogoUI
	: public PauseUIBase
{
public:
	void Start();
protected:

private:
	SpriteRenderer2D* sprite;
};

