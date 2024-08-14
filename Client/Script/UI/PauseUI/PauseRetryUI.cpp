#include "PauseRetryUI.h"
#include "Resource.h"

void PauseRetryUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(PauseRetrySprite().Get());

	Vector2 size = mainSprite->size / 2;

	gameObject->transform->position = Vector2(1152 + size.x, 224 + size.y);
}

void PauseRetryUI::SelectedLogic()
{
	if (InputManager::KeyIsHold(Key::SPACEBAR))
	{
		mainSprite->index = 2;
		//ChangeWorld("IntroScene_01");
	}
	else
		mainSprite->index = 1; 
}

void PauseRetryUI::UnSelectedLogic()
{
	mainSprite->index = 0;
}

void PauseRetryUI::OnDestroy()
{
	PauseRetrySprite().Release();
}

