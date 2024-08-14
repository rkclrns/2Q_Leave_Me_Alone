#include "CreditBackground.h"
#include "Resource.h"

void CreditBackground::Start()
{
	sprite = gameObject->AddComponent<SpriteRenderer2D>();
	sprite->SetSprite(CreditBackgroundSprite().Get());
	sprite->size = Vector2(960, 1085); 
}
