#pragma once
#include "Script/UI/PauseUI/PauseUIBase.h"

class PauseExitUI 
	: public PauseUIBase
{
public:
	void Start();
	virtual void SelectedLogic();
	virtual void UnSelectedLogic();
	void OnDestroy();

	bool isSelect = false;

protected:
};


