#include "DisposableObject.h"

void DisposableObject::Start()
{
	__super::Start();
}

void DisposableObject::Update()
{
	__super::Update();
	if (m_animator->End())
	{
		m_interactiveState = eInteractiveState::Passive;
		m_hitRange->SetState(GameState::Passive);
		m_animator->alpha -= Time::deltaTime / m_fadeTime;
	}
	if (m_animator->alpha <= 0.0f)
	{
		Destroy(gameObject);
	}
}

void DisposableObject::OnInteractive()
{
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_interactiveState = eInteractiveState::Using;
	}
}
