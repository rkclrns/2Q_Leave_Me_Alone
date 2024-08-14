#include "Statue.h"
#include "Resource.h"

void Statue::Start()
{
	__super::Start();
	StatueSprite().Get();
	m_animator->AddAnimation("Animation", StatueAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Statue::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
}

void Statue::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}
