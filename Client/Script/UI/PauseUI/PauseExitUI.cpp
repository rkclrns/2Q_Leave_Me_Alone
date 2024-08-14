#include "PauseExitUI.h"
#include "Resource.h"


void PauseExitUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(PauseExitSprite().Get());

	Vector2 size = mainSprite->size / 2;

	gameObject->transform->position = Vector2(1472 + size.x, 416 + size.y);
}

void PauseExitUI::SelectedLogic()
{
	if (InputManager::KeyIsDown(Key::SPACEBAR))
	{
		ChangeWorld("Title");
	}
	if (InputManager::KeyIsHold(Key::SPACEBAR))
	{
		mainSprite->SetSprite(L"S_PauseExit", 2);
	}
	else
		mainSprite->SetSprite(L"S_PauseExit", 1);
}

void PauseExitUI::UnSelectedLogic()
{
	mainSprite->SetSprite(L"S_PauseExit", 0);
}

void PauseExitUI::OnDestroy()
{
	PauseExitSprite().Release();
}
