#pragma once
#include "DisposableObject.h"

class FallingObject
	: public DisposableObject
{
public:
	virtual void Start();
	virtual void Update();
	virtual void OnInteractive() override;
	virtual void OnCollisionEnter(Collider* _origin, Collider* _destination) override;
protected:
	float m_gravity = 0.f;
	float m_maxGravity = 10.0f;
	int m_interactiveIndex = 0;
	int m_fallingIndex = 0;
	int m_breakIndex = 0;
};

