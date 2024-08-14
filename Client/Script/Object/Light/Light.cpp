#include "Light.h"
#include "Resource.h"
#include "../Human/Human.h"

void Light::Start()
{
	m_circle = gameObject->AddComponent<CircleRenderer>();
	// 이미지의 사이즈 설정
	m_circle->SetFillColor(D2D1::ColorF(D2D1::ColorF::Goldenrod));
	m_circle->SetFill(true);
	m_circle->SetLine(false);
}

void Light::Update()
{
}

void Light::SetLight(eLightType _elightType, Human* _humanOwner)
{
	m_owner = m_owner;

	gameObject->transform->SetParent(_humanOwner->gameObject->transform);

	if (_humanOwner->GetCollider() == nullptr) { return; }

	switch (_elightType)
	{
	case eLightType::Flash:
	{
		m_circle->radius = 230.0f;
		gameObject->transform->position = Vector2(250, -20);
		break;
	}
	case eLightType::Lantern:
	{
		m_circle->radius = 180.0f;
		gameObject->transform->position = Vector2(200, -20);
		break;
	}
	case eLightType::Candle:
	{
		m_circle->radius = 140.0f;
		gameObject->transform->position = Vector2(160, -20);
		break;
	}
	default:
		break;
	}
}
