#include "IntroScene_01.h"
#include "ScriptHeaders.h"
#include "UIHeader.h"
#include "Contents.h"

void IntroScene_01::WorldLoad()
{
	Actor* actor = CreateObject<Actor>(L"IntroBackground", LayerTag::BackGround);
	actor->AddComponent<IntroBackground>();

	Actor* text = CreateObject<Actor>(L"IntroSceneText", LayerTag::UI);
	text->AddComponent<IntroSceneText>();
}

void IntroScene_01::WorldDestroy()
{

}

void IntroScene_01::WorldEnter()
{
}

void IntroScene_01::WorldExit()
{

}
