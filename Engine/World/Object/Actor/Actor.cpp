#include "pch.h"
#include "Actor.h"

Actor::Actor(std::wstring _name, ObjectTag _tag)
	: Object(_name, _tag)
{
	m_type = ObjectType::Actor;
	m_componentList->clear();
	transform = this->AddComponent<Transform2D>();
}

Actor::~Actor()
{
	CallOnDestroy(); // ��ũ��Ʈ�� Destroy �ݹ� ȣ��
	// ������Ʈ �Ҵ� ����
	for (int i = 0; i < (int)ComponentType::SIZE; i++)
	{
		for (Component*& comp : m_componentList[i]) {
			delete comp;
		}
	}
}

void Actor::FixedUpdate()
{
	for (int i = 0; i < (int)ComponentType::SIZE; i++)
	{
		for (Component*& comp : m_componentList[i])
		{
			if (comp && comp->GetState() == GameState::Active)
				comp->FixedUpdate();
		}
	}
}

void Actor::EarlyUpdate()
{
	for (int i = 0; i < (int)ComponentType::SIZE; i++)
	{
		for (Component*& comp : m_componentList[i])
		{
			if (comp && comp->GetState() == GameState::Active)
				comp->EarlyUpdate();
		}
	}
}

void Actor::Update()
{
	for (int i = 0; i < (int)ComponentType::SIZE; i++)
	{
		for (Component*& comp : m_componentList[i])
		{
			if (comp && comp->GetState() == GameState::Active)
				comp->Update();
		}
	}
}

void Actor::LateUpdate()
{
	for (int i = 0; i < (int)ComponentType::SIZE; i++)
	{
		for (Component*& comp : m_componentList[i])
		{
			if (comp && comp->GetState() == GameState::Active)
				comp->LateUpdate();
		}
	}
}

void Actor::Draw(Camera2D* _camera)
{
	for (int i = 0; i < (int)ComponentType::SIZE; i++)
	{
		for (Component*& comp : m_componentList[i])
		{
			if (comp && comp->GetState() == GameState::Active)
				comp->Draw(_camera);
		}
	}
}

void Actor::Render()
{
	for (int i = 0; i < (int)ComponentType::SIZE; i++)
	{
		for (Component*& comp : m_componentList[i])
		{
			if (comp && comp->GetState() == GameState::Active)
				comp->Render();
		}
	}
}

void Actor::SetActive(bool _val)
{
	// Destroy���¸� ���ٲٰ� �ϱ� ���� PASS
	if (m_state == GameState::Destroy) return;
	GameState temp = _val ? GameState::Active : GameState::Passive;
	// ���� ���¿� ������ PASS
	if (m_state == temp) return;
	m_state = temp;
	// �ڽĵ鵵 ȣ���ؾ� �ϱ� ������ �Լ��� ���� ���� ��������� ȣ��
	if (m_state == GameState::Active)
	{
		CallOnEnalbe();
		for (Transform2D* tr : transform->GetChild())
		{
			tr->gameObject->SetActive(true);
		}
	}
	else if (m_state == GameState::Passive)
	{
		CallOnDisalbe();
		for (Transform2D* tr : transform->GetChild())
		{
			tr->gameObject->SetActive(false);
		}
	}
}

void Actor::SetDestroy()
{
	__super::SetDestroy();
	for (Transform2D* tr : transform->GetChild())
	{
		tr->gameObject->SetDestroy();
	}
}

void Actor::CallOnEnalbe()
{
	for (Component*& comp : m_componentList[(int)ComponentType::Script])
	{
		if (comp->GetState() == GameState::Active)
			dynamic_cast<Script*>(comp)->OnEnable();
	}
}

void Actor::CallOnDisalbe()
{
	for (Component*& comp : m_componentList[(int)ComponentType::Script])
	{
		if (comp->GetState() == GameState::Active)
			dynamic_cast<Script*>(comp)->OnDisable();
	}
}

void Actor::CallOnDestroy()
{
	for (Component*& comp : m_componentList[(int)ComponentType::Script])
	{
		if (comp->GetState() == GameState::Active)
			dynamic_cast<Script*>(comp)->OnDestroy();
	}
}
