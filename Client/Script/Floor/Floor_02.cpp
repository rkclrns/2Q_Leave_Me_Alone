#include "Floor_02.h"

void Floor_02::Start()
{
	m_map = gameObject->AddComponent<RectRenderer>();
	m_map->size = Vector2(5200, 676);
	m_map->SetLine(false);
	m_map->SetFillColor(D2D1::ColorF(D2D1::ColorF::IndianRed));

	gameObject->transform->position = Vector2(180, 2180);

}
