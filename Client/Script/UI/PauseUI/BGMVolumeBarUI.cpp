#include "BGMVolumeBarUI.h"
#include "Resource.h"
#include "Contents.h"
#include "ScriptHeaders.h"


void BGMVolumeBarUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(BGMVolumeBarSprite().Get());

	Vector2 size = mainSprite->size / 2;

	gameObject->transform->position = Vector2(1152 + size.x, 635 + size.y);

	volumeGauge = gameObject->AddComponent<SpriteRenderer2D>();
	volumeGauge->SetSprite(VolumeGaugeBarSprite().Get());
	volumeGauge->gameObject->transform->SetParent(gameObject->transform);
	volumeGauge->renderOffset = Vector2(65 , 0);
}

void BGMVolumeBarUI::SelectedLogic()
{
	mainSprite->index = 1;

	if ((InputManager::KeyIsDown(Key::LEFT) || InputManager::GetMoveKeyForce().x < 0)
		&& !m_isMove)
	{
		if (GameManager::BGMVolume > 0)
			GameManager::BGMVolume -= 0.2f;

		m_isMove = true;
	}
	else if ((InputManager::KeyIsDown(Key::RIGHT) || InputManager::GetMoveKeyForce().x > 0)
		&& !m_isMove)
	{
		if (GameManager::BGMVolume < 1.f)
			GameManager::BGMVolume += 0.2f;

		m_isMove = true;
	}
	else if (InputManager::GetMoveKeyForce().x == 0)
		m_isMove = false;

	int volume = (GameManager::BGMVolume * 10.0f) * 0.5f;
	volumeGauge->index = volume;
}

void BGMVolumeBarUI::UnSelectedLogic()
{
	mainSprite->index = 0;

	int volume = (GameManager::BGMVolume * 10.0f) * 0.5f;
	volumeGauge->index = volume;
}

void BGMVolumeBarUI::OnDestroy()
{
	
}
