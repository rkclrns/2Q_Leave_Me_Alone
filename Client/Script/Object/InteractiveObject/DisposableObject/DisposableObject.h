#pragma once
#include "Script/Object/InteractiveObject/InteractiveObject.h"

class DisposableObject : public InteractiveObject
{
public:
	virtual void Start();
	virtual void Update();
	virtual void OnInteractive() override;
protected:
};

