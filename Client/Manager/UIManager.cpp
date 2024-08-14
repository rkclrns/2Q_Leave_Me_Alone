#include "UIManager.h"

PauseUI* UIManager::pauseUI;
InGameUI* UIManager::inGameUI;
ClearUI* UIManager::clearUI;

void UIManager::Initialize()
{
	inGameUI = WorldManager::GetActiveWorld()->CreateObject<Actor>(L"InGameUI", LayerTag::UI, ObjectTag::UI)->AddComponent<InGameUI>();
	inGameUI->gameObject->SetActive(true);

	pauseUI = WorldManager::GetActiveWorld()->CreateObject<Actor>(L"PauseUI", LayerTag::UI, ObjectTag::UI)->AddComponent<PauseUI>();
	pauseUI->gameObject->SetActive(false);
	clearUI = WorldManager::GetActiveWorld()->CreateObject<Actor>(L"ClearUI", LayerTag::UI, ObjectTag::UI)->AddComponent<ClearUI>();
	clearUI->gameObject->SetActive(false);
}