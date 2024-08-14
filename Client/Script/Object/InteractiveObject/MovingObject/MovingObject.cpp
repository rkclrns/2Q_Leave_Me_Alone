#include "MovingObject.h"

void MovingObject::Start()
{
	__super::Start();
}

void MovingObject::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Passive)
	{
		if (m_coolTimer > 0.0f)
		{
			m_coolTimer -= Time::deltaTime;
		}
		else
		{
			m_coolTimer = 0.0f;
			m_interactiveState = eInteractiveState::Useable;
			m_body->SetState(GameState::Active);
		}
	}
	else if (m_interactiveState == eInteractiveState::Using)
	{
		if (m_animator->End())
		{
			m_interactiveState = eInteractiveState::Passive;
		}
	}
	if (m_interactiveState == eInteractiveState::Using)
	{
		m_hitRange->SetState(GameState::Active);
		m_body->SetState(GameState::Passive);
	}
	else
	{
		m_hitRange->SetState(GameState::Passive);
	}
}

void MovingObject::OnInteractive()
{
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_interactiveState = eInteractiveState::Using;
		m_coolTimer = m_maxCoolTime;
		m_body->SetState(GameState::Passive);
		m_hitRange->SetState(GameState::Active);
	}
}