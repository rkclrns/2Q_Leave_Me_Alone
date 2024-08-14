#include "LoadingUI.h"
#include "Contents.h"
#include "Resource.h"
#include "Script/Timer.h"

void LoadingUI::Start()
{
	m_point = gameObject->AddComponent<SpriteRenderer2D>();
	m_point->SetSprite(LoadingPointerSprite().Get());
	Vector2 m_pointerSize = m_point->size * 0.5f;
	m_point->renderOffset = Vector2(m_pointerSize.x + (-124), m_pointerSize.y + 227);

	m_text = gameObject->AddComponent<Animator2D>();
	m_text->AddAnimation("LoadingText", LoadingTextAnimation().Get());
	m_text->ChangeAnimation("LoadingText", true);
	m_text->renderOffset = Vector2(960, 848);

	m_timer = gameObject->AddComponent<Timer>();
	m_timer->SetTimer(5.0f);
	m_timer->Play();
}

void LoadingUI::Update()
{
	float moveSpeed = 6.5f;
	m_point->renderOffset.x += 0.3f * moveSpeed;

	if (m_timer->IsEnd())
	{
		if (GameManager::fader->IsFadeInEnd())
		{
			GameManager::fader->SetFade(true);
			return;
		}
		else if (GameManager::fader->IsFadeOutEnd())
		{
			ChangeWorld(changeWorld);
			GameManager::fader->SetFade(false);
		}
	}
}
