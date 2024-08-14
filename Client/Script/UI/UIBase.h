#pragma once
#include "Application.h"

class UIBase
	: public Script
{
public:
	void Start();
protected:
	SpriteRenderer2D* mainSprite;
private:
};