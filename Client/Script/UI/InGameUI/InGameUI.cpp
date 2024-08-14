#include "InGameUI.h"
#include "UIHeader.h"
#include "Resource.h"
#include "Contents.h"

void InGameUI::Start()
{
	gameObject->SetPersistent(true);

	// InGame Key
	humanListKeySprite = gameObject->AddComponent<SpriteRenderer2D>();
	humanListKeySprite->SetSprite(HumanListKeySprite().Get());
	Vector2 HumanKeySize = humanListKeySprite->size / 2;
	humanListKeySprite->renderOffset = Vector2(HumanKeySize.x + 15, HumanKeySize.y + 893);

	pauseKeySprite = gameObject->AddComponent<SpriteRenderer2D>();
	pauseKeySprite->SetSprite(PauseKeySprite().Get());
	Vector2 PauseKeySize = pauseKeySprite->size / 2;
	pauseKeySprite->renderOffset = Vector2(PauseKeySize.x + 15, PauseKeySize.y + 989);

	// InGameUI
	timeUI = CreateObject<Actor>(L"InGameTimeUI", LayerTag::UI, ObjectTag::UI);
	timeUI->AddComponent<InGameTimeUI>();
	timeUI->transform->SetParent(gameObject->transform);

	skillUI = CreateObject<Actor>(L"InGameSkillUI", LayerTag::UI, ObjectTag::UI);
	skillUI->AddComponent<InGameSkillUI>();
	skillUI->transform->SetParent(gameObject->transform);

	skillGaugeUI = CreateObject<Actor>(L"InGameGaugeSkillUI", LayerTag::UI, ObjectTag::UI);
	skillGaugeUI->AddComponent<InGameGaugeSkillUI>();
	skillGaugeUI->transform->SetParent(gameObject->transform);

	HumanListUI = CreateObject<Actor>(L"InGameHumanListUI", LayerTag::UI, ObjectTag::UI);
	HumanListUI->AddComponent<InGameHumanListUI>();
	HumanListUI->transform->SetParent(gameObject->transform);

}

void InGameUI::Update()
{

}