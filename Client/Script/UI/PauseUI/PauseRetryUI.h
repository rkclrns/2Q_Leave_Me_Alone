#pragma once
#include "Script/UI/PauseUI/PauseUIBase.h"

class PauseRetryUI 
	: public PauseUIBase
{
public:
	void Start();
	virtual void SelectedLogic();
	virtual void UnSelectedLogic();
	void OnDestroy();

protected:
};

