#pragma once
#include "Application.h"

class Timer
	: public Script
{
public:
	void Start();
	void Update();

	void SetTimer(float _time);
	void Play();
	void Stop();
	bool IsEnd();
private:
	float timer;
	bool isStart = false;
};


