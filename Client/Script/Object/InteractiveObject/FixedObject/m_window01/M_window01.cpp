#include "M_window01.h"
#include "Resource.h"

void M_window01::Start()
{
	__super::Start();
	MiddleWindow1Sprite().Get();
	m_animator->AddAnimation("Animation", MiddleWindow1Animation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void M_window01::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
}

void M_window01::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}