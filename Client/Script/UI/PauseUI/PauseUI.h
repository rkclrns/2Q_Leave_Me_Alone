#pragma once
#include "Application.h"

class PauseUIBase;
class PauseUI
	: public Script
{
public:
	void Start();
	void Update();
protected:

	PauseUIBase* selectUi;
	PauseUIBase* UIs[4];

	int m_selectType = 0;

private:
	bool m_isMove = false;
	void InputLogic();
};


