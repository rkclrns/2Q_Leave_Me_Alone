#include "S_lamp.h"
#include "Resource.h"

void S_lamp::Start()
{
	__super::Start();
	// TODO : ���ҽ��� �����Ű��.
	LampSprite1().Get();
	m_animator->AddAnimation("Animation", Lamp1Animation().Get());
	m_animator->ChangeAnimation("Animation", false);
	m_interactiveIndex = 1;
	m_fallingIndex = 4;
	m_breakIndex = 5;
}