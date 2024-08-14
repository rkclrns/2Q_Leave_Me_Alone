#include "Human.h"
#include "Resource.h"
#include "../Light/Light.h"]
#include "HumanFSM/Idle_Human.h"
#include "HumanFSM/Walk_Human.h"
#include "HumanFSM/Run_Human.h"
#include "HumanFSM/Surprise_Human.h"
#include "../InteractiveObject/InteractiveObject.h"

void Human::Start()
{
	Debug::Log("Woman1 생성");
	gameObject->transform->position = Vector2(-530, 130);

	// Animation
	Woman1Sprite().Load();
	m_animator = gameObject->AddComponent<Animator2D>();
	m_animator->centerOffset = Vector2(10.0f, 0.0f);
	m_animator->AddAnimation("Idle", Woman1_Idle().Load());
	m_animator->AddAnimation("Walk", Woman1_Walk().Load());
	m_animator->AddAnimation("Run", Woman1_Run().Load());
	m_animator->AddAnimation("Surprise", Woman1_Surprise().Load());

	// FSM
	m_FSM = gameObject->AddComponent<FiniteStateMachine>();

	m_FSM->AddState<Walk_Human>("WALK");
	m_FSM->AddState<Surprise_Human>("SURPRISE");
	m_FSM->AddState<Run_Human>("RUN");
	m_FSM->AddState<Idle_Human>("IDLE");


	// Collider 생성
	m_body = gameObject->AddComponent<BoxCollider2D>();
	m_body->size = { 230,310 };

	// Light 생성
	light = CreateObject<Actor>(L"Light", LayerTag::Layer_01, ObjectTag::Particle)->AddComponent<Light>();
	light->SetLight(eLightType::Candle, this);

	// Light 크기에 맞춰 공포범위 지정
	m_fearBox = gameObject->AddComponent<BoxCollider2D>();
	m_fearBox->colliderTag = "fearBox";
	m_fearBox->size = { (light->GetCircle()->radius) * 2.0f ,500.0f };
}

void Human::Update()
{
	if (InputManager::KeyIsDown('Q'))
	{
		gameObject->transform->scale.x *= -1.0f;
	}

	m_fearBox->offset = Vector2(-160.0f * gameObject->transform->scale.x, 0.0f);	// 수정예정
}

void Human::OnCollisionEnter(Collider* _origin, Collider* _destination)
{
	if (_destination->gameObject->GetTag() == ObjectTag::Interactive)
	{
		if (_origin->colliderTag == "fearBox" && _destination->colliderTag == "HitBox")
		{
			isSurprise = true;

			if (isSurprise) { Debug::Log("isSurprise : true"); }
			else { Debug::Log("isSurprise : false"); }

		}
	}

}
