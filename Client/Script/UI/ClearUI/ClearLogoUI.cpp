#include "ClearLogoUI.h"
#include "Resource.h"

void ClearLogoUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(ClearLogoSprite().Get());
	gameObject->transform->position = Vector2(960, 540);
}
