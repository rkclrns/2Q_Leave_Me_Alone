#include "Bottle.h"
#include "Resource.h"

void Bottle::Start()
{
	__super::Start();
	BottleSprite().Get();
	m_animator->AddAnimation("Animation", BottleAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
	m_interactiveIndex = 1;
	m_fallingIndex = 3;
	m_breakIndex = 4;
}