#include "NonFallingObject.h"

void NonFallingObject::Start()
{
	__super::Start();
}

void NonFallingObject::Update()
{
	__super::Update();

	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndPlay(0);
	}
	if (m_interactiveState == eInteractiveState::Using)
	{
		if (m_animator->currentFrame < m_breakIndex)
		{
			if (m_animator->currentFrame >= m_breakIndex)
				m_animator->GotoAndStop(m_breakIndex);
		}
	}
}

void NonFallingObject::OnInteractive()
{
	__super::OnInteractive();
}
