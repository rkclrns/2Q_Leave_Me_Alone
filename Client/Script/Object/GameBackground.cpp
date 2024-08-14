#include "GameBackground.h"
#include "Resource.h"

void GameBackground::Start()
{
	gameObject->transform->position = Vector2(0, 0);

	sprite = gameObject->AddComponent<SpriteRenderer2D>();
	sprite->SetSprite(TestBackgroundSprite().Load());
	sprite->size = Vector2(5200, 6651);
}

void GameBackground::Update()
{

}
