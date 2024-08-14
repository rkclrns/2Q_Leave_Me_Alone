#include "FallingObject.h"

void FallingObject::Start()
{
	__super::Start();
}

void FallingObject::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		if (m_animator->currentFrame >= m_interactiveIndex)
		{
			m_animator->GotoAndPlay(0);
		}
	}
	if (m_interactiveState == eInteractiveState::Using)
	{
		if (m_animator->currentFrame < m_breakIndex)
		{
			if (m_animator->currentFrame >= m_fallingIndex)
			{
				gameObject->transform->position.y += m_gravity;
			}
			if(m_animator->currentFrame >= m_breakIndex - 1) m_animator->GotoAndStop(m_breakIndex - 1);
		}
		else
		{
			m_body->SetState(GameState::Passive);
			m_hitRange->SetState(GameState::Active);
		}
		if (m_gravity < m_maxGravity) m_gravity += 10.f * Time::deltaTime;
		else m_gravity = m_maxGravity;
	}
}

void FallingObject::OnInteractive()
{
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndPlay(m_interactiveIndex);
	}
	__super::OnInteractive();
}

void FallingObject::OnCollisionEnter(Collider* _origin, Collider* _destination)
{
	if (_origin->colliderTag == "Body" && _destination->colliderTag == "Floor")
	{
		m_animator->GotoAndPlay(m_breakIndex);
	}
}
