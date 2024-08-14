#include "TV.h"
#include "Resource.h"

void TV::Start()
{
	__super::Start();
	TVSprite().Get();
	m_animator->AddAnimation("Animation", TVAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void TV::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
}

void TV::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}