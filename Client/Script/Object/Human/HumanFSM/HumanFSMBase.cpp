#include "HumanFSMBase.h"
#include "../Human.h"

void HumanFSMBase::Start()
{
	owner = FSM->gameObject->GetComponent<Human>();
}

bool HumanFSMBase::ChangeState_To_AniEnd(const std::string& _fsmName)
{
	if (owner->GetAnimator()->End())
	{
		FSM->ChangeState(_fsmName);
		return true;
	}
	return false;
}
