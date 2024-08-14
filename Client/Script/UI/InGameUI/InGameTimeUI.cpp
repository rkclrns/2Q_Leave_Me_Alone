#include "InGameTimeUI.h"
#include "Resource.h"

void InGameTimeUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(InGameTimeSprite().Get());

	int dx = mainSprite->size.x / 2;
	int dy = mainSprite->size.y / 2;

	gameObject->transform->position = Vector2(15 + dx, 15 + dy);
}

void InGameTimeUI::Update()
{
	// TODO :: timer Logic

}
