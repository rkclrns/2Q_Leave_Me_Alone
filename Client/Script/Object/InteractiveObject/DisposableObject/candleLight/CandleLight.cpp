#include "CandleLight.h"
#include "Resource.h"

void CandleLight::Start()
{
	__super::Start();
	CandleLightSprite().Get();
	m_animator->AddAnimation("Animation", CandleLightAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
	m_interactiveIndex = 5;
	m_fallingIndex = 7;
	m_breakIndex = 11;
}
