#pragma once
#include "Application.h"

class TitlePlayerUI 
	: public Script
{
public:
	virtual void Start() override;
	virtual void Update() override;

	void InputLogic();

private:
	Animator2D* m_animator;

	Actor* m_buttons[3];
	int m_selectType = 1;

	Vector2 m_offset;

	bool isMove = false;
};