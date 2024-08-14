#pragma once
#include "Script/Object/InteractiveObject/InteractiveObject.h"

class FixedObject : public InteractiveObject
{
public:
	virtual void Start();
	virtual void Update();

	virtual void OnInteractive();
};

