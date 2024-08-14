#pragma once
#include "Script/UI/TextUI.h"

class CreditText
	: public TextUI
{
public:
	void Start();
	void Update();
protected:

private:
	float m_scrollTimer;
};

