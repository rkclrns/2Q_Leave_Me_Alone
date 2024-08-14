#include "CreditButton.h"
#include "Contents.h"

void CreditButton::Start()
{
	__super::Start();

	rect = gameObject->AddComponent<RectRenderer>();
	rect->size = Vector2(416, 224);
	gameObject->transform->position = gameObject->transform->position = Vector2(752 + (rect->size.x / 2), 801 + (rect->size.y / 2));
	button->SetSize(rect->size);
}

void CreditButton::Update()
{
	// CreditScene 으로 월드 체인지
	if (GameManager::fader->IsFadeOutEnd() && GameManager::fader->GetEvent() == L"Credit") 
	{
		FadeSystem::loadingScene->changeWorld = WorldManager::FindWorld("Credit");
		ChangeWorld("LoadingScene");
	}
		

	if (isPlayer == true)
	{
		if (InputManager::KeyIsHold(Key::SPACEBAR))
			OnPlayerEnter();
		else
			OnPlayerStay();
	}
	else
		OnPlayerExit();
}

void CreditButton::OnPlayerStay()
{
	// Debug::Log("CreditEnter");

	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Gray));
}

void CreditButton::OnPlayerEnter()
{
	//Debug::Log("CreditClick");

	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::DimGray));

	// Credit Scene Change World
	GameManager::fader->SetFade(true);
	GameManager::fader->SetEvent(L"Credit");
}

void CreditButton::OnPlayerExit()
{
	//Debug::Log("CreditExit");

	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::White));
}