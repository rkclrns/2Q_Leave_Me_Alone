#include "TitleBackground.h"
#include "Resource.h"

void TitleBackground::Start()
{
	gameObject->transform->position = Vector2(0, 0);

	sprite = gameObject->AddComponent<SpriteRenderer2D>();
	sprite->SetSprite(TitleBackgroundSprite().Get());
	sprite->size = Vector2(1920, 1080);
}

void TitleBackground::Update()
{

}
