#include "OldBook.h"
#include "Resource.h"

void OldBook::Start()
{
	__super::Start();
	// TODO : 리소스를 적용시키자.
	// 애니메이션 루프는 무조건 false로 할 것.
	OldBookSprite().Get();
	m_animator->AddAnimation("Animation", OldBookAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
}

void OldBook::Update()
{
	__super::Update();
	if (m_interactiveState == eInteractiveState::Useable)
	{
		m_animator->GotoAndStop(0);
	}
}

void OldBook::OnInteractive()
{
	m_animator->GotoAndPlay(1);
	__super::OnInteractive();
}