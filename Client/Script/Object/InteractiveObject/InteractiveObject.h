#pragma once
#include "Script/Object/ObjectBase.h"

enum class eInteractiveState
{
	Useable,
	Using,
	Passive
};
// 오브젝트가 상호작용이 불가능한 상태를 만들려면 굳이 State를 나눠야할까?
// 콜라이더를 비활성화하는 방식으로 구현해본다면?
// Csv로 해서 
class InteractiveObject : public ObjectBase
{
public:

	virtual void Start();
	virtual void Update();
	virtual void OnCollisionStay(Collider* _origin, Collider* _destination) {}

	// 플레이어가 상호작용 했을 때 호출 될 함수
	virtual void OnInteractive() = 0;
	// CSV불러오기
	virtual void LoadCSV();

	eInteractiveState GetInteractiveState() const { return m_interactiveState; }
	Vector2 GetBodySize() { return m_body->size; }
	Vector2 GetBodyOffSet() { return m_body->offset; }

	const float GetHorrorPower() { return m_horrorPower; }

protected:
	eInteractiveState m_interactiveState = eInteractiveState::Useable;

	// 일회용은 쿨타임이 필요없긴 하지만 범용성을 위해 여기다 넣었습니다.(CSV리딩)
	// 어차피 일회용은 쿨타임 계산도 안하거니와, 쿨타임으로 상태변경이 이루어 지지 않기 때문에
	float m_coolTimer = 0.0f;
	float m_maxCoolTime = 10.0f;
	float m_horrorPower = 10.0f;

	BoxCollider2D* m_body;
	BoxCollider2D* m_hitRange;
	RectRenderer* m_rect;
	Animator2D* m_animator;
	TextRenderer* m_text;

	//=================일회용 오브젝트 전용 변수=================
	float m_fadeTime = 2.f;
};

