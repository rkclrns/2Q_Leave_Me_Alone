#include "TeaCup.h"
#include "Resource.h"

void TeaCup::Start()
{
	__super::Start();
	TeaCupSprite().Get();
	m_animator->AddAnimation("Animation", TeaCupAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
	m_interactiveIndex = 1;
	m_fallingIndex = 2;
	m_breakIndex = 5;
}
