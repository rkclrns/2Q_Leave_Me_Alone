#include "Cat.h"
#include "Resource.h"

void Cat::Start()
{
	Debug::Log("Cat »ý¼º");
	CatSprite().Load();
	m_animator = gameObject->AddComponent<Animator2D>();
	//m_animator->centerOffset = Vector2(75, 300);

	m_animator->AddAnimation("Idle", Cat_Idle().Load());
	m_animator->AddAnimation("Walk", Cat_Walk().Load());
	m_animator->AddAnimation("Run", Cat_Run().Load());
	m_animator->AddAnimation("Jump", Cat_Jump().Load());
	m_animator->AddAnimation("Appear", Cat_Appear().Load());
	m_animator->AddAnimation("Disappear", Cat_Disappear().Load());

	m_animator->ChangeAnimation("Idle");
	gameObject->transform->position = Vector2(-500, 0);
}

void Cat::Update()
{
	if (Input::KeyIsDown(49)) m_animator->ChangeAnimation("Idle",true);
	if (Input::KeyIsDown(50)) m_animator->ChangeAnimation("Walk", true);
	if (Input::KeyIsDown(51)) m_animator->ChangeAnimation("Run", true);
	if (Input::KeyIsDown(52)) m_animator->ChangeAnimation("Jump", true);
	if (Input::KeyIsDown(53)) m_animator->ChangeAnimation("Appear", true);
	if (Input::KeyIsDown(54)) m_animator->ChangeAnimation("Disappear", false);


	if (m_animator->GetActiveAnimation()->GetKey() == Cat_Appear()._key)
	{
		if (m_animator->End())
		{
			m_animator->ChangeAnimation("Run");
		}
	}

	if (m_animator->GetActiveAnimation()->GetKey() == Cat_Jump()._key)
	{
		if (m_animator->End())
		{
			m_animator->ChangeAnimation("Disappear");
		}
	}
}
