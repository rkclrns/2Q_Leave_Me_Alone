#include "SFXVolumeBarUI.h"
#include "Resource.h"
#include "Contents.h"


void SFXVolumeBarUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(SFXVolumeBarSprite().Get());
	Vector2 size = mainSprite->size / 2;
	gameObject->transform->position = Vector2(1152 + size.x, 760 + size.y);

	volumeGauge = gameObject->AddComponent<SpriteRenderer2D>();
	volumeGauge->SetSprite(VolumeGaugeBarSprite().Get());
	volumeGauge->gameObject->transform->SetParent(gameObject->transform);
	volumeGauge->renderOffset = Vector2(65, 0);
}

void SFXVolumeBarUI::SelectedLogic()
{
	mainSprite->index = 1;

	if ((InputManager::KeyIsDown(Key::LEFT) || InputManager::GetMoveKeyForce().x < 0)
		&& !m_isMove)
	{
		if (GameManager::SFXVolume > 0)
			GameManager::SFXVolume -= 0.2f;

		m_isMove = true;
	}
	else if ((InputManager::KeyIsDown(Key::RIGHT) || InputManager::GetMoveKeyForce().x > 0)
		&& !m_isMove)
	{
		if (GameManager::SFXVolume < 1.f)
			GameManager::SFXVolume += 0.2f;

		m_isMove = true;
	}
	else if (InputManager::GetMoveKeyForce().x == 0)
		m_isMove = false;

	int volume = (GameManager::SFXVolume * 10.0f) * 0.5f;
	volumeGauge->index = volume;
}

void SFXVolumeBarUI::UnSelectedLogic()
{
	mainSprite->index = 0;

	int volume = (GameManager::SFXVolume * 10.0f) * 0.5f;
	volumeGauge->index = volume;
}

void SFXVolumeBarUI::OnDestroy()
{

}