#pragma once
#include "Script/UI/UIBase.h"

class CreditBackground
	: public UIBase
{
public:
	void Start();

protected:
	SpriteRenderer2D* sprite;
};

