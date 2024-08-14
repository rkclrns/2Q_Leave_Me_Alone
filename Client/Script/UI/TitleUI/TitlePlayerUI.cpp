#include "TitlePlayerUI.h"
#include "Resource.h"
#include "UIHeader.h"


void TitlePlayerUI::Start()
{
	Debug::Log("플레이어 생성");

	m_offset = Vector2(0, -150);

	m_animator = gameObject->AddComponent<Animator2D>();
	m_animator->AddAnimation("Idle", PlayerIdle().Get());
	m_animator->ChangeAnimation("Idle", true);

	gameObject->depthsLevel = 0;

	m_buttons[0] = CreateObject<Actor>(L"Start", LayerTag::UI, ObjectTag::UI);
	m_buttons[0]->AddComponent<StartButton>();
	m_buttons[1] = CreateObject<Actor>(L"Credit", LayerTag::UI, ObjectTag::UI);
	m_buttons[1]->AddComponent<CreditButton>();
	m_buttons[2] = CreateObject<Actor>(L"Exit", LayerTag::UI, ObjectTag::UI);
	m_buttons[2]->AddComponent<ExitButton>();

	gameObject->transform->position = m_buttons[1]->transform->position + m_offset;
}

void TitlePlayerUI::Update()
{
	InputLogic();
	Vector2 buttonPos = { m_buttons[m_selectType]->transform->position.x, m_buttons[m_selectType]->transform->position.y + m_offset.y };
	gameObject->transform->position = MathF.Lerp(gameObject->transform->position, buttonPos, 10 * Time::deltaTime);

	if (m_selectType == 0)
	{
		m_buttons[0]->GetComponent<StartButton>(ComponentType::Script)->isPlayer = true;
		m_buttons[1]->GetComponent<CreditButton>(ComponentType::Script)->isPlayer = false;
		m_buttons[2]->GetComponent<ExitButton>(ComponentType::Script)->isPlayer = false;
	}
	else if (m_selectType == 1)
	{
		m_buttons[0]->GetComponent<StartButton>(ComponentType::Script)->isPlayer = false;
		m_buttons[1]->GetComponent<CreditButton>(ComponentType::Script)->isPlayer = true;
		m_buttons[2]->GetComponent<ExitButton>(ComponentType::Script)->isPlayer = false;
	}
	else if (m_selectType == 2)
	{
		m_buttons[0]->GetComponent<StartButton>(ComponentType::Script)->isPlayer = false;
		m_buttons[1]->GetComponent<CreditButton>(ComponentType::Script)->isPlayer = false;
		m_buttons[2]->GetComponent<ExitButton>(ComponentType::Script)->isPlayer = true;
	}
}

void TitlePlayerUI::InputLogic()
{
	if ((InputManager::KeyIsDown(Key::LEFT) || InputManager::GetMoveKeyForce().x < 0)
		&& !isMove)	// 좌
	{
		if (m_selectType > 0)
			m_selectType--;

		isMove = true;
	}

	if ((InputManager::KeyIsDown(Key::RIGHT) || InputManager::GetMoveKeyForce().x > 0)
		&& !isMove)// 우
	{
		if (m_selectType < 2)
			m_selectType++;

		isMove = true;
	}

	if (InputManager::GetMoveKeyForce().x == 0)
	{
		isMove = false;
	}
}
