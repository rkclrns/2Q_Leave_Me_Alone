#include "Run_Human.h"
#include "../Human.h"

void Run_Human::StateEnter()
{
	Debug::Log("Run_Human");
	owner->GetAnimator()->ChangeAnimation("Run", true);
}

void Run_Human::StateUpdate()
{
}

void Run_Human::StateExit()
{
}
