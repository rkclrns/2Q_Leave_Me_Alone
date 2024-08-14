#include "Walk_Human.h"
#include "../Human.h"

void Walk_Human::StateEnter()
{
	Debug::Log("Walk_Human");
	owner->GetAnimator()->ChangeAnimation("Walk", true);
}

void Walk_Human::StateUpdate()
{
	// owner->Light���� �浹�� �Ͼ�� FSM::Surprise�� �����ض�
	if (owner->isSurprise)
	{
		owner->m_FSM->ChangeState("SURPRISE");
	}
}

void Walk_Human::StateExit()
{
}
