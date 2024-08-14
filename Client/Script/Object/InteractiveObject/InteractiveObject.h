#pragma once
#include "Script/Object/ObjectBase.h"

enum class eInteractiveState
{
	Useable,
	Using,
	Passive
};
// ������Ʈ�� ��ȣ�ۿ��� �Ұ����� ���¸� ������� ���� State�� �������ұ�?
// �ݶ��̴��� ��Ȱ��ȭ�ϴ� ������� �����غ��ٸ�?
// Csv�� �ؼ� 
class InteractiveObject : public ObjectBase
{
public:

	virtual void Start();
	virtual void Update();
	virtual void OnCollisionStay(Collider* _origin, Collider* _destination) {}

	// �÷��̾ ��ȣ�ۿ� ���� �� ȣ�� �� �Լ�
	virtual void OnInteractive() = 0;
	// CSV�ҷ�����
	virtual void LoadCSV();

	eInteractiveState GetInteractiveState() const { return m_interactiveState; }
	Vector2 GetBodySize() { return m_body->size; }
	Vector2 GetBodyOffSet() { return m_body->offset; }

	const float GetHorrorPower() { return m_horrorPower; }

protected:
	eInteractiveState m_interactiveState = eInteractiveState::Useable;

	// ��ȸ���� ��Ÿ���� �ʿ���� ������ ���뼺�� ���� ����� �־����ϴ�.(CSV����)
	// ������ ��ȸ���� ��Ÿ�� ��굵 ���ϰŴϿ�, ��Ÿ������ ���º����� �̷�� ���� �ʱ� ������
	float m_coolTimer = 0.0f;
	float m_maxCoolTime = 10.0f;
	float m_horrorPower = 10.0f;

	BoxCollider2D* m_body;
	BoxCollider2D* m_hitRange;
	RectRenderer* m_rect;
	Animator2D* m_animator;
	TextRenderer* m_text;

	//=================��ȸ�� ������Ʈ ���� ����=================
	float m_fadeTime = 2.f;
};

