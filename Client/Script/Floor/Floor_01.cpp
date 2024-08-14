#include "Floor_01.h"
#include "Resource.h"

void Floor_01::Start()
{
	__super::Start();
	m_backGround->SetSprite(BackGroundSprite_01().Get());
	m_floor->size = Vector2(m_backGround->size.x, 80.0f);
	m_floor->gameObject->transform->position.y = m_backGround->size.y * 0.5 - m_floor->size.y * 0.5 - 200;
}

void Floor_01::Update()
{
}
