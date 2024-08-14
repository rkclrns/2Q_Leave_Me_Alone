#pragma once
#include "Application.h"

class Human;
class HumanFSMBase : public FSMState
{
public:
	virtual void Start();
	bool ChangeState_To_AniEnd(const std::string& _fsmName);

public:
	Human* owner;
};

