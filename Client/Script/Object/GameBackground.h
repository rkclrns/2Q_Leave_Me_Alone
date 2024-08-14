#pragma once
#include "Script/Object/ObjectBase.h"

class GameBackground : public ObjectBase
{
public:
	void Start();
	void Update();

private:
	SpriteRenderer2D* sprite;
};

