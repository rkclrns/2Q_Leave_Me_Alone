#include "Doll.h"
#include "Resource.h"

void Doll::Start()
{
	__super::Start();
	DollSprite().Get();
	m_animator->AddAnimation("Animation", DollAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Doll::Update()
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

void Doll::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}