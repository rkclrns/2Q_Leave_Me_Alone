#include "Chandelier.h"
#include "Resource.h"

void Chandelier::Start()
{
	__super::Start();

	ChandelierSprite().Get();
	m_animator->AddAnimation("Animation", ChandelierAnimation().Get());
	m_animator->ChangeAnimation("Animation", false);
	m_interactiveIndex = 0;
	m_breakIndex = 11;
}

//void Chandelier::Update()
//{
//}
