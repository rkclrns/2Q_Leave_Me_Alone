#include "Clock_big.h"
#include "Resource.h"

void Clock_big::Start()
{
	__super::Start();
	ClockBigSprite().Get();
	m_animator->AddAnimation("Animation", ClockBigAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void Clock_big::Update()
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

void Clock_big::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}