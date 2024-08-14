#include "TitleLogo.h"
#include "Resource.h"

void TitleLogo::Start()
{
	gameObject->transform->position = Vector2(0, -200);

	sprite = gameObject->AddComponent<SpriteRenderer2D>();
	sprite->SetSprite(TitleLogoSprite().Get());
	sprite->size = Vector2(1100, 500);
}

void TitleLogo::Update()
{
	
}

void TitleLogo::OnDestroy()
{
	
}
