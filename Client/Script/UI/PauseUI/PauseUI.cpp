#include "PauseUI.h"
#include "Contents.h"
#include "Resource.h"


#include "Script/UI/PauseUI/PauseUIBase.h"
#include "Script/UI/PauseUI/PauseLogoUI.h"
#include "Script/UI/PauseUI/PauseRetryUI.h"
#include "Script/UI/PauseUI/PauseExitUI.h"
#include "Script/UI/PauseUI/BGMVolumeBarUI.h"
#include "Script/UI/PauseUI/SFXVolumeBarUI.h"

void PauseUI::Start()
{
	gameObject->SetPersistent(true);
	
	// pause Background
	RectRenderer* rect = gameObject->AddComponent<RectRenderer>();
	rect->size = Vector2(1920, 1085);
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Black));
	rect->SetLine(false);
	rect->alpha = 0.5f;
	rect->renderOffset = Vector2(960, 540);

	// pause Logo
	Actor* actor;
	actor = CreateObject<Actor>(L"PauseLogo", LayerTag::UI, ObjectTag::UI);
	actor->AddComponent<PauseLogoUI>();
	actor->transform->SetParent(gameObject->transform);

	// pause Menu
	actor = CreateObject<Actor>(L"PauseRetry", LayerTag::UI, ObjectTag::UI);
	UIs[0] = actor->AddComponent<PauseRetryUI>();
	UIs[0]->gameObject->transform->SetParent(gameObject->transform);
	actor = CreateObject<Actor>(L"PauseExit", LayerTag::UI, ObjectTag::UI);
	UIs[1] = actor->AddComponent<PauseExitUI>();
	UIs[1]->gameObject->transform->SetParent(gameObject->transform);
	actor = CreateObject<Actor>(L"BGMVolumeBar", LayerTag::UI, ObjectTag::UI);
	UIs[2] = actor->AddComponent<BGMVolumeBarUI>();
	UIs[2]->gameObject->transform->SetParent(gameObject->transform);
	actor = CreateObject<Actor>(L"SFXVolumeBar", LayerTag::UI, ObjectTag::UI);
	UIs[3] = actor->AddComponent<SFXVolumeBarUI>();
	UIs[3]->gameObject->transform->SetParent(gameObject->transform);
}

void PauseUI::Update()
{
	InputLogic();

	selectUi = UIs[m_selectType];
	selectUi->SelectedLogic();

	for (int i = 0; i < 4; i++)
	{
		if (UIs[i] != selectUi)
			UIs[i]->UnSelectedLogic();
	}
}

void PauseUI::InputLogic()
{
	if ((InputManager::KeyIsDown(Key::UP) || InputManager::GetMoveKeyForce().y < 0)
		&& !m_isMove) // ╩С
	{
		if (m_selectType > 0)
			m_selectType--;

		m_isMove = true;
	}

	if ((InputManager::KeyIsDown(Key::DOWN) || InputManager::GetMoveKeyForce().y > 0)
		&& !m_isMove) // го
	{
		if (m_selectType < 3)
			m_selectType++;

		m_isMove = true;
	}

	if (InputManager::GetMoveKeyForce().y == 0)
		m_isMove = false;
}