#include "CreditText.h"

void CreditText::Start()
{
	__super::Start();

	// 리소스 Add두번하면 안댐
	textComponent->SetFont(ResourceManager::AddFont(L"Galmuri11", L"Font/Galmuri11.ttf"));

	texts.push_back(L"개발하느라 다들 고생 많았네요 쏼라쏼라… 스페셜 땡스 투 어쩌구저쩌구… … 알고 계셨나요 ? ‘지바크’의 어원은 지박령이랍니다. (따단) 개발하느라 다들 고생 많았네요 쏼라쏼라… 스페셜 땡스 투 어쩌구저쩌구… … 알고 계셨나요 ? ‘지바크’의 어원은 지박령이랍니다. (따단) 개발하느라 다들 고생 많았네요 쏼라쏼라… 스페셜 땡스 투 어쩌구저쩌구… … 알고 계셨나요 ? ‘지바크’의 어원은 지박령이랍니다. (따단) 개발하느라 다들 고생 많았네요 쏼라쏼라… 스페셜 땡스 투 어쩌구저쩌구… … 알고 계셨나요 ? ‘지바크’의 어원은 지박령이랍니다. (따단) 개발하느라 다들 고생 많았네요 쏼라쏼라… 스페셜 땡스 투 어쩌구저쩌구… … 알고 계셨나요 ? ‘지바크’의 어원은 지박령이랍니다. (따단) 개발하느라 다들 고생 많았네요 쏼라쏼라… 스페셜 땡스 투 어쩌구저쩌구… … 알고 계셨나요 ? ‘지바크’의 어원은 지박령이랍니다. (따단)");

	textComponent->SetBox(Vector2(708, 918));
	textComponent->SetSize(30.f);
	textComponent->SetColor(D2D1::ColorF(D2D1::ColorF::White));

	textComponent->SetAlignment(AlignmentType::Center);

	rect = gameObject->AddComponent<RectRenderer>();
	rect->size = textComponent->size;
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::DimGray));
	rect->SetLine(false);
	rect->alpha = 0.5f;

}

void CreditText::Update()
{
	__super::Update();

	m_scrollTimer = 0.5f;

	if (InputManager::KeyIsHold(Key::SPACEBAR))
		m_scrollTimer = 5.0f;

	gameObject->transform->position.y -= 0.3f * m_scrollTimer;
}

