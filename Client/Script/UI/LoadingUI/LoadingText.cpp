#include "LoadingText.h"

void LoadingText::Start()
{
	__super::Start();

	// 리소스 Add두번하면 안댐
	textComponent->SetFont(ResourceManager::AddFont(L"Galmuri11", L"Font/Galmuri11.ttf"));

	texts.push_back(L"로딩중...");

	textComponent->SetBox(Vector2(300, 50));
	textComponent->SetSize(30.f);
	textComponent->SetColor(D2D1::ColorF(D2D1::ColorF::Black));

	textComponent->SetAlignment(AlignmentType::Left);
	gameObject->transform->position = Vector2(300, 932);

	rect = gameObject->AddComponent<RectRenderer>();
	rect->size = textComponent->size;
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::DimGray));
	rect->SetLine(false);
	rect->alpha = 0.5f;
}

void LoadingText::Update()
{
	__super::Update();
}
