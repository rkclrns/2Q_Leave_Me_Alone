#pragma once
#include "Application.h"
#include "World/LoadingScene.h"
class FadeSystem
	: public Script
{
public:
	enum eType
	{
		Stop = 0,
		FadeIn = -1,
		FadeOut = 1,
	};
	void Start();
	void Update();

	void SetFade(bool _on, float _duration = 1.0f);
	void SetEvent(const wchar_t* _event);
	void StopFade();

	bool IsFadeInEnd() { return m_alpha == 0.f; }
	bool IsFadeOutEnd() { return m_alpha == 1.f; }

	std::wstring& GetEvent() { return m_event; }

	static LoadingScene* loadingScene;

private:

	RectRenderer* m_fadeRect = nullptr;
	float m_alpha = 0.f;
	float m_duration = 1.f;
	int	  m_fadeState = 0;
	int   m_preState = 0;
	std::wstring m_event = L"";
};

