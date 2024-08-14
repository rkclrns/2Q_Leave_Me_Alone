#include "Player.h"
#include "Resource.h"
#include "Contents.h"
#include "Script/Object/InteractiveObject/InteractiveObject.h"
#include "../Client/Manager/InputManager.h"

void Player::Start()
{
	{
		m_moveSpeed = 500.0f;
		m_skillGauge = 100;
		m_maxSkillGauge = 100;
	}

   PlayerSprite().Load();
   m_animator = gameObject->AddComponent<Animator2D>();
   m_animator->AddAnimation("Hold", PlayerHold().Load());
   m_animator->AddAnimation("Move_Down", PlayerMove_Down().Load());
   m_animator->AddAnimation("Idle", PlayerIdle().Load());
   m_animator->AddAnimation("Move_RL", PlayerMove_RL().Load());
   m_animator->AddAnimation("Move_Top", PlayerMove_Top().Load());
   m_animator->AddAnimation("Skill", PlayerSkill().Load());

   m_body = gameObject->AddComponent<BoxCollider2D>();
   m_body->size = { 110,180 };
   m_body->colliderTag = "Body";
}

void Player::Update()
{
	if (m_playerState == ePlayerState::Skill)
	{
		if (m_animator->End())
		{
			m_playerState = ePlayerState::Default;
		}
	}
	else if (m_playerState != ePlayerState::Skill)
	{ 
		if (GameManager::cameraController->GetMode() == eCameraMode::PlayerZoom)
		{
			if (m_playerState == ePlayerState::Interactive)
			{
				// =================상호작용=================
				if (InputManager::KeyIsDown(Key::SPACEBAR))
				{
					if (targetObj)
					{
						targetObj->OnInteractive();
					}
				}
			}
			// =================스킬사용=================
			if (InputManager::KeyIsDown('E') && m_skillGauge >= m_maxSkillGauge)
			{
				m_playerState = ePlayerState::Skill;
				m_animator->ChangeAnimation("Skill", false);
				m_skillGauge = 0;
			}
			gameObject->transform->position += InputManager::GetMoveKeyForce() * Time::deltaTime * m_moveSpeed;
		}
		if (m_playerState == ePlayerState::Interactive)
		{
			m_animator->ChangeAnimation("Hold");
		}
		else if (m_playerState == ePlayerState::Default)
		{
			m_animator->ChangeAnimation("Idle");
		}
	}
}

void Player::LateUpdate() 
{
	if(m_playerState != ePlayerState::Skill)
		m_playerState = ePlayerState::Default;
}

void Player::OnCollisionStay(Collider* _origin, Collider* _destination)
{
	if (_destination->gameObject->GetTag() == ObjectTag::Interactive)
	{
		targetObj = _destination->gameObject->GetComponent<InteractiveObject>(ComponentType::Script);
		if (targetObj && _destination->colliderTag == "Body")
		{
			m_playerState = ePlayerState::Interactive;
		}
	}
}
