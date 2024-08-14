#include "InGameSkillUI.h"
#include "Resource.h"

void InGameSkillUI::Start()
{
	__super::Start();

	mainSprite->SetSprite(InGameSkillSprite().Get());

	Vector2 size = mainSprite->size / 2;

	gameObject->transform->position = Vector2(942 + size.x , 31 + size.y);
}

void InGameSkillUI::Update()
{
	m_skillTimer += Time::deltaTime;

	if (InputManager::KeyIsHold(69))
	{
		if(m_canSkill)
			m_isSkill = true;
		else
		{
			// ��ų ��Ÿ�� ����
			if (m_skillTimer > 10)
			{
				m_skillTimer -= 10;

				m_canSkill = true;
			}
		}
	}

	if (m_isSkill)
	{
		mainSprite->index = 0;

		// ��ų ���ð� ����
		if (m_skillTimer > 3)
		{
			m_skillTimer -= 3;

			m_isSkill = false;
			m_canSkill = false;
		}
	}
	else 
		mainSprite->index = 1;
}
