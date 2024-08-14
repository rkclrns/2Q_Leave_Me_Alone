#include "StartButton.h"
#include "Contents.h"

#include "World/Stage_01.h"

void StartButton::Start()
{
	__super::Start();
	rect = gameObject->AddComponent<RectRenderer>();
	rect->size = Vector2(416, 224);
	gameObject->transform->position = gameObject->transform->position = Vector2(160 + (rect->size.x / 2), 704 + (rect->size.y / 2));
	button->SetSize(rect->size);
}

void StartButton::Update()
{
	// introScene 으로 월드 체인지
	if (GameManager::fader->IsFadeOutEnd() && GameManager::fader->GetEvent() == L"Intro")
	{
		GameManager::fader->SetEvent(L"");
		FadeSystem::loadingScene->changeWorld = WorldManager::CreateWorld<Stage_01>("Stage_01", WorldTag::Play);
		ChangeWorld("LoadingScene");
	}

	if (isPlayer == true)
	{
		if (InputManager::KeyIsDown(Key::SPACEBAR))
			OnPlayerEnter();
		else
			OnPlayerStay();
	}
	else
		OnPlayerExit();
}

void StartButton::OnPlayerStay()
{
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Gray));
}

void StartButton::OnPlayerEnter()
{
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::DimGray));
	GameManager::fader->SetFade(true);
	GameManager::fader->SetEvent(L"Intro");
}

void StartButton::OnPlayerExit()
{
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::White));
}