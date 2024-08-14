#include "S_frame01.h"
#include "Resource.h"

void S_frame01::Start()
{
	__super::Start();
	FrameSprite().Get();
	m_animator->AddAnimation("Animation", FrameAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
	m_interactiveIndex = 1;
	m_fallingIndex = 1;
	m_breakIndex = 2;
}