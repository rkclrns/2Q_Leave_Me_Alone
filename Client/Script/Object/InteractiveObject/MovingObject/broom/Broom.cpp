#include "Broom.h"
#include "Resource.h"

void Broom::Start()
{
	__super::Start();
	BroomSprite().Get();
	m_animator->AddAnimation("Animation", BroomAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Broom::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
	if (m_animator->End())
	{
		m_animator->GotoAndStop(0);
	}
}

void Broom::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}
