#include "Timer.h"

void Timer::Start()
{
	timer = 0;
}

void Timer::Update()
{
	if (isStart)
	{
		timer -= Time::deltaTime;
	}
	else if (timer <= 0)
	{
		timer = 0.f;
		isStart = false;
	}
}

void Timer::SetTimer(float _time)
{
	timer = _time;
}

void Timer::Play()
{
	isStart = true;
}

void Timer::Stop()
{
	isStart = false;
}

bool Timer::IsEnd()
{
	return timer <= 0.f;
}
