#include "Piano.h"
#include "Resource.h"

void Piano::Start()
{
	__super::Start();
	/*PianoSprite().Get();
	m_animator->AddAnimation("Animation", PianoAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);*/
}

void Piano::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
}

void Piano::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}