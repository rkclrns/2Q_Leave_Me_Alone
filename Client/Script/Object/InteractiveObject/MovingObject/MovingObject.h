#pragma once
#include "Script/Object/InteractiveObject/InteractiveObject.h"

class MovingObject : public InteractiveObject
{
public:
	virtual void Start();
	virtual void Update();
	virtual void OnInteractive();
protected:
};

