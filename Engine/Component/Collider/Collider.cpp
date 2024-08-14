#include "pch.h"
#include "Collider.h"
#include "../../Collision/Manager/CollisionManager.h"
#include "../../World/Object/Actor/Actor.h"

UINT Collider::CollisionID = 1;

Collider::Collider()
	: isTrigger(false),
	m_id(CollisionID++)
{
}

Collider::~Collider()
{

}

void Collider::OnCollisionEnter(Collider* _origin, Collider* _destination)
{
	for (Component*& comp : gameObject->GetComponentList(ComponentType::Script))
	{
		if (comp->GetState() == GameState::Active)
		{
			dynamic_cast<Script*>(comp)->OnCollisionEnter(_origin, _destination);
		}
	}
}

void Collider::OnCollisionStay(Collider* _origin, Collider* _destination)
{
	for (Component*& comp : gameObject->GetComponentList(ComponentType::Script))
	{
		if (comp->GetState() == GameState::Active)
		{
			dynamic_cast<Script*>(comp)->OnCollisionStay(_origin, _destination);
		}
	}
}

void Collider::OnCollisionExit(Collider* _origin, Collider* _destination)
{
	for (Component*& comp : gameObject->GetComponentList(ComponentType::Script))
	{
		if (comp->GetState() == GameState::Active)
		{
			dynamic_cast<Script*>(comp)->OnCollisionExit(_origin, _destination);
		}
	}
}

bool Collider::CheckInteract(Collider* _dest)
{
	return CollisionManager::GetCollisionID(this, _dest);
}
