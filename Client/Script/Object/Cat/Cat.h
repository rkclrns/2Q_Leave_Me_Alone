#pragma once
#include "Script/Object/IFSMObjectCore.h"

class Cat : public IFSMObjectCore
{
public:
	virtual void Start() override;
	virtual void Update() override;

	bool isAttack = false;

private:
	BoxCollider2D* m_body;


	float m_speed = 500.0f;
};

