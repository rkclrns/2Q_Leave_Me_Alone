#include "Mirror_01.h"
#include "Resource.h"

void Mirror_01::Start()
{
	__super::Start();
	MirrorSprite().Get();
	m_animator->AddAnimation("Animation", MirrorAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Mirror_01::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
}

void Mirror_01::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}
