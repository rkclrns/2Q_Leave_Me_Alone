#include "Credit.h"
#include "UIHeader.h"
#include "Contents.h"
#include "UIHeader.h"

void Credit::WorldLoad()
{
	Actor* actor;

	actor = CreateObject<Actor>(L"CreditBackground", LayerTag::BackGround, ObjectTag::UI);
	actor->AddComponent<CreditBackground>();
	actor->transform->position = Vector2(1450, 540);

	actor = CreateObject<Actor>(L"CreditText", LayerTag::UI, ObjectTag::UI);
	actor->AddComponent<CreditText>();
	actor->transform->position = Vector2(490, 540);
}

void Credit::WorldDestroy()
{

}

void Credit::WorldEnter()
{
	GameManager::fader->SetFade(false);
}

void Credit::WorldExit()
{

}
