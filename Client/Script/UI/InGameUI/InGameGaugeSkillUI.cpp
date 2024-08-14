#include "InGameGaugeSkillUI.h"
#include "Resource.h"

void InGameGaugeSkillUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(InGameGaugeSkillSprite().Get());

	Vector2 size = mainSprite->size / 2;
	gameObject->transform->position = Vector2(1161 + size.x, 51 + size.y);
}

void InGameGaugeSkillUI::Update()
{
	// TODO :: gaugeLogic

}

void InGameGaugeSkillUI::OnDestroy()
{
	
}
