#include "Floor_03.h"

void Floor_03::Start()
{
	m_map = gameObject->AddComponent<RectRenderer>();
	m_map->size = Vector2(5200, 676);
	m_map->SetLine(false);
	m_map->SetFillColor(D2D1::ColorF(D2D1::ColorF::MediumPurple));

	gameObject->transform->position = Vector2(180, 3620);
}
