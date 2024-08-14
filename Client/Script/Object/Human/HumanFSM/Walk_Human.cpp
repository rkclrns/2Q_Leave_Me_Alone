#include "Walk_Human.h"
#include "../Human.h"

void Walk_Human::StateEnter()
{
	Debug::Log("Walk_Human");
	owner->GetAnimator()->ChangeAnimation("Walk", true);
}

void Walk_Human::StateUpdate()
{
	// owner->Light에서 충돌이 일어나면 FSM::Surprise로 변경해라
	if (owner->isSurprise)
	{
		owner->m_FSM->ChangeState("SURPRISE");
	}
}

void Walk_Human::StateExit()
{
}
