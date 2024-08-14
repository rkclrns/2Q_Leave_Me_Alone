#include "ExitButton.h"

void ExitButton::Start()
{
	__super::Start();
	rect = gameObject->AddComponent<RectRenderer>();
	rect->size = Vector2(416, 224);
	gameObject->transform->position = Vector2(1344 + (rect->size.x / 2), 736 + (rect->size.y / 2));
	button->SetSize(rect->size);
}

void ExitButton::Update()
{
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

void ExitButton::OnPlayerStay()
{
	//Debug::Log("ExitEnter");

	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Gray));
}

void ExitButton::OnPlayerEnter()
{
	
	//Debug::Log("ExitClick");

	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::DimGray));

	// Game Exit
	GameApplication::Quit();
}

void ExitButton::OnPlayerExit()
{
	//Debug::Log("ExitExit");

	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::White));
}