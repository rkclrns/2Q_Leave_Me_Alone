#include "PauseLogoUI.h"
#include "Resource.h"

void PauseLogoUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(PauseLogoSprite().Get());
	Vector2 mainSize = mainSprite->size / 2;
	mainSprite->renderOffset = Vector2(128 + mainSize.x, 224 + mainSize.y);

	sprite = gameObject->AddComponent<SpriteRenderer2D>();
	sprite->SetSprite(PauseTutorialSprite().Get());
	Vector2 spriteSize = sprite->size / 2;
	sprite->renderOffset = Vector2(128 + spriteSize.x, 480 + spriteSize.y);
}
