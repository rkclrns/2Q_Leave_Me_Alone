#pragma once
#include "Application.h"

class Timer;

class LoadingUI
	: public Script
{
public:
	void Start();
	void Update();

	World* changeWorld;

protected:

private:
	SpriteRenderer2D* m_point;
	Animator2D*		  m_text;
	Timer*			  m_timer;
};

