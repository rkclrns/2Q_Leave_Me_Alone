#include "LoadingScene.h"
#include "UIHeader.h"
#include "Contents.h"
#include "Resource.h"

void LoadingScene::WorldLoad()
{
	
}

void LoadingScene::WorldDestroy()
{

}

void LoadingScene::WorldEnter()
{
	UI = CreateObject<Actor>(L"LoadingUI", LayerTag::UI, ObjectTag::UI)->AddComponent<LoadingUI>();
	UI->changeWorld = changeWorld;
	GameManager::fader->SetFade(false);
}

void LoadingScene::WorldExit()
{
	changeWorld = nullptr;
	WorldManager::DestroyWorld(this->GetName());
}
