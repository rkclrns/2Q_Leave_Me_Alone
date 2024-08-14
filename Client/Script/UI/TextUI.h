#pragma once
#include "Application.h"

class TextUI 
	: public Script
{
public:
	virtual void Start();
	virtual void Update();


protected:

	RectRenderer* rect;
	TextRenderer* textComponent;
	std::vector<std::wstring> texts;

private:

	float m_timer = 0.0f;
	int m_index1 = 0;
	int m_index2 = 0;
	bool isEnter = false;
};

