#pragma once
#include "HumanFSMBase.h"

class Run_Human : public HumanFSMBase
{

public:
	virtual void StateEnter() final;
	virtual void StateUpdate() final;
	virtual void StateExit() final;
};
