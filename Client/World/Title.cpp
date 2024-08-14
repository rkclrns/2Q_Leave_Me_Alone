#include "Title.h"
#include "UIHeader.h"
#include "WorldHeaders.h"

void Title::WorldLoad()
{
	Actor* actor;

	actor = CreateObject<Actor>(L"TitleBackground", LayerTag::BackGround);
	actor->AddComponent<TitleBackground>();
	actor = CreateObject<Actor>(L"TitleLogo", LayerTag::BackGround);
	actor->AddComponent<TitleLogo>();

	actor = CreateObject<Actor>(L"TitlePlayer", LayerTag::UI, ObjectTag::UI);
	actor->AddComponent<TitlePlayerUI>();
}

void Title::WorldDestroy()
{

}

void Title::WorldEnter()
{

}

void Title::WorldExit()
{

}
