#pragma once
#include "Script/Object/InteractiveObject/FixedObject/FixedObject.h"

class M_window01 : public FixedObject
{
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnInteractive() override;
};

