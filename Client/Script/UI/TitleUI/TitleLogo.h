#pragma once
#include "Script/Object/ObjectBase.h"

class TitleLogo : public ObjectBase
{
public:
	void Start();
	void Update();
	void OnDestroy();

protected:
	SpriteRenderer2D* sprite;
};

