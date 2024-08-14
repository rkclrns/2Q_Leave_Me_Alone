#pragma once
#include "DisposableObject.h"

class NonFallingObject
	: public DisposableObject
{
public:
	virtual void Start();
	virtual void Update();
	virtual void OnInteractive() override;
protected:
	int m_interactiveIndex = 0;
	int m_breakIndex = 0;
private:
};

