#include "FadeSystem.h"

LoadingScene* FadeSystem::loadingScene;

void FadeSystem::Start()
{
	m_fadeRect = gameObject->AddComponent<RectRenderer>();
	m_fadeRect->size = Vector2(SCREEN_WIDTH,SCREEN_HEIGHT) + 1;
	m_fadeRect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Black));
	m_fadeRect->SetLine(false);
	gameObject->depthsLevel = 5000;
	gameObject->transform->position = Vector2(m_fadeRect->size.x * 0.5f, m_fadeRect->size.y * 0.5f);
	gameObject->SetPersistent(true);
	loadingScene = dynamic_cast<LoadingScene*>(WorldManager::FindWorld("LoadingScene"));
	
}

void FadeSystem::Update()
{
	m_fadeRect->alpha = m_alpha;

	m_alpha += ((float)m_fadeState * Time::deltaTime) / m_duration;

	if (m_alpha >= 1.f)
	{
		m_alpha = 1.f;
		m_fadeState = Stop;
	}
	else if (m_alpha <= 0.f)
	{
		m_alpha = 0.f;
		m_fadeState = Stop;
	}
}

void FadeSystem::SetFade(bool _on, float _duration)
{
	if (_on)
	{
		m_fadeState = FadeOut;
		m_alpha = 0.f;
	}
	else
	{
		m_fadeState = FadeIn;
		m_alpha = 1.f;
	}
	m_duration = _duration;
}

void FadeSystem::SetEvent(const wchar_t* _event)
{
	m_event = _event;
}

void FadeSystem::StopFade()
{
	m_preState = m_fadeState;
	m_fadeState = Stop;
}
