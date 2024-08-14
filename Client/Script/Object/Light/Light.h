#pragma once
#include "Script/Object/ObjectBase.h"

enum class eLightType
{
	Flash,
	Lantern,
	Candle,
	None
};

class Human;
class Light : public ObjectBase
{
public:
	virtual void Start() final;
	virtual void Update() final;

	void SetLight(eLightType _elightType, Human* _humanOwner);	// �̹���&�ݶ��̴� ũ�� ����
	CircleRenderer* GetCircle() { return m_circle; }

private:
	CircleRenderer* m_circle;
	BoxCollider2D* m_body;
	Human* m_owner;
};

