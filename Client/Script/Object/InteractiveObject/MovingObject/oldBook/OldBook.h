#pragma once
#include "Script/Object/InteractiveObject/MovingObject/MovingObject.h"

class OldBook : public MovingObject
{
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnInteractive() override;
};

