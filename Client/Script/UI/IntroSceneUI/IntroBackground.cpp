#include "IntroBackground.h"
#include "Resource.h"

void IntroBackground::Start()
{
	gameObject->transform->position = Vector2(0, 0);

	mainSprite = gameObject->AddComponent<SpriteRenderer2D>();
	mainSprite->SetSprite(IntroBackgroundSprite().Get());
	mainSprite->size = Vector2(1920, 1080);
}

void IntroBackground::Update()
{
	// TODO :: image change

}

void IntroBackground::OnDestroy()
{
	
}
