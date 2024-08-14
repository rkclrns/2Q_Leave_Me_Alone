#include "Chair.h"
#include "Resource.h"

void Chair::Start()
{
	__super::Start();
	ChairSprite().Get();
	m_animator->AddAnimation("Animation", ChairAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Chair::Update()
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

void Chair::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}