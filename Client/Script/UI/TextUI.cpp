#include "TextUI.h"

void TextUI::Start()
{
	textComponent = gameObject->AddComponent<TextRenderer>();
}

void TextUI::Update()
{
	m_timer += Time::deltaTime;

	if (m_index1 < texts.size())
	{
		if (m_index2 < texts[m_index1].length())
		{
			if (m_timer > 0.1f)
			{
				m_timer -= 0.1f;
				textComponent->AddText(texts[m_index1][m_index2]);
				m_index2++;
			}

			// 빠르게 스킵하고 싶다면
			/*if (InputManager::KeyIsHold(Key::SPACEBAR))
			{
				if(!isEnter)
				{
					m_timer = 0.00f;
					textComponent->AddText(texts[m_index1][m_index2]);
					m_index2++;
				}
			}*/
		}
		/*else
		{
			if (InputManager::KeyIsDown(Key::SPACEBAR))
			{
				isEnter = true;

				textComponent->SetText(L"");
				m_index1++;
				m_index2 = 0;
			}
		}*/
	}
	/*if (InputManager::KeyIsUp(Key::SPACEBAR))
	{
		isEnter = false;
	}*/
}
