#pragma once
#include "Script/Object/ObjectBase.h"

enum class ePlayerState
{
	Default,
	Interactive,
	Skill
};

class InteractiveObject;
class Player : public ObjectBase
{
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void OnCollisionStay(Collider* _origin, Collider* _destination);

	ePlayerState m_playerState = ePlayerState::Default;

private:
	Animator2D* m_animator;
	BoxCollider2D* m_body;
	InteractiveObject* targetObj;
	float m_moveSpeed;
	int m_skillGauge;
	int m_maxSkillGauge;

};

