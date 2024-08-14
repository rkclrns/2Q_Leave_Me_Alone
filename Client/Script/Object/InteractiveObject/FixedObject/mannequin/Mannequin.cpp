#include "Mannequin.h"
#include "Resource.h"

void Mannequin::Start()
{
	__super::Start();
	MannequinSprite().Get();
	m_animator->AddAnimation("Animation", MannequinAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Mannequin::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
}

void Mannequin::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}