#pragma once
#include "Component.h"

class Input;
class Mouse;
class D2DRender;

class Button
	: public Component
{
public:
	Button();
	virtual ~Button();

	virtual void EarlyUpdate() final;
	virtual void Update() final;

	bool& IsEnter() { return isEnter; }
	void  SetSize(Vector2 _size) { m_buttonSize = _size; }

	// ������ ���� �ѹ��� ȣ���
	bool OnPress() { return isEnter&& Input::MouseIsDown(Mouse::LEFT); }
	// ������ ���� ������Ʈ���� ȣ���
	bool OnHold() { return isEnter&& Input::MouseIsHold(Mouse::LEFT); }
	// �� ���� �ѹ��� ȣ���
	bool OnRelease() { return isEnter&& Input::MouseIsUp(Mouse::LEFT); }

private:

	static Actor* m_targetObject;
	Vector2 	  m_buttonSize;
	bool		  isEnter;

};