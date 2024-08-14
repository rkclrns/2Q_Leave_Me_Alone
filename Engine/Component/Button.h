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

	// 누르는 순간 한번만 호출됨
	bool OnPress() { return isEnter&& Input::MouseIsDown(Mouse::LEFT); }
	// 누르는 동안 업데이트마다 호출됨
	bool OnHold() { return isEnter&& Input::MouseIsHold(Mouse::LEFT); }
	// 뗀 순간 한번만 호출됨
	bool OnRelease() { return isEnter&& Input::MouseIsUp(Mouse::LEFT); }

private:

	static Actor* m_targetObject;
	Vector2 	  m_buttonSize;
	bool		  isEnter;

};