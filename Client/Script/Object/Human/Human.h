#pragma once
#include "Script/Object/IFSMObjectCore.h"
#include "Script/Object/ObjectBase.h"

class FiniteStateMachine;
class Light;
class Human : public IFSMObjectCore
{
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void OnCollisionEnter(Collider* _origin, Collider* _destination) final;

	const BoxCollider2D* GetCollider() { return m_body; }

	void SetFearScore(int _fearScore) { m_fearScore = _fearScore; }
	const int GetFearScore() { return m_fearScore; }

public:
	bool isSurprise = false;

	FiniteStateMachine* m_FSM;

private:
	SpriteRenderer2D* m_sprite;
	BoxCollider2D* m_body;
	BoxCollider2D* m_fearBox;
	Light* light;

	float m_fearScore = 0.0f;
};

