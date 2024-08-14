#include "InGameHumanListUI.h"
#include "UIHeader.h"

void InGameHumanListUI::Start()
{
	__super::Start();

	int dx = 256;
	m_offset = 28;

	for (int i = 0; i < 5; i++)
	{
		Actor* actor = CreateObject<Actor>(L"InGameHumanBox", LayerTag::UI, ObjectTag::UI);
		actor->AddComponent<InGameHumanBox>();
		actor->transform->position = Vector2(960 + (i * dx), 979);
		actor->transform->SetParent(gameObject->transform);
		actor->SetActive(false);
		m_humansList.push_back(actor);
	}
}

void InGameHumanListUI::Update()
{
	if (InputManager::KeyIsDown(Key::UP))
	{
		if (m_humanCounter < 5) m_humanCounter++;
	}

	if (InputManager::KeyIsDown(Key::DOWN))
	{
		if (m_humanCounter > 0)
		{
			m_humanCounter--;
		}
	}

	gameObject->transform->position.x = -(m_humanCounter - 1) * 128;

	for (int i = 0; i < 5; i++)
	{
		if (i <= m_humanCounter - 1)
		{
			m_humansList[i]->SetActive(true);
		}
		else
		{
			m_humansList[i]->SetActive(false);
		}
	}
}
