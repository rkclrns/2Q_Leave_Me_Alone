#pragma once
#include "Script/Object/ObjectBase.h"

class TitleBackground : public ObjectBase
{
public:
	void Start();
	void Update();

protected:
	SpriteRenderer2D* sprite;
};

