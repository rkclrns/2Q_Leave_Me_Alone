#include "Pot.h"
#include "Resource.h"

void Pot::Start()
{
	__super::Start();
	PotSprite().Get();
	m_animator->AddAnimation("Animation", PotAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
	m_interactiveIndex = 1;
	m_fallingIndex = 2;
	m_breakIndex = 5;
}