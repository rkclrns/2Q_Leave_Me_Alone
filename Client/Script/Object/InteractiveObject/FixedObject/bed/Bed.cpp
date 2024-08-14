#include "Bed.h"
#include "Resource.h"

void Bed::Start()
{
	__super::Start();
	BedSprite().Get();
	m_animator->AddAnimation("Animation", BedAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Bed::Update()
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

void Bed::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}