#include "ClearUI.h"
#include "ClearLogoUI.h"

void ClearUI::Start()
{
	gameObject->SetPersistent(true);

	RectRenderer* rect = gameObject->AddComponent<RectRenderer>();
	rect->size = Vector2(1920, 1085);
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Black));
	rect->SetLine(false);
	rect->alpha = 0.5f;
	rect->renderOffset = Vector2(960, 540);

	sprite = CreateObject<Actor>(L"ClearLogo", LayerTag::UI, ObjectTag::UI);
	sprite->AddComponent<ClearLogoUI>();
	sprite->transform->SetParent(gameObject->transform);
}
