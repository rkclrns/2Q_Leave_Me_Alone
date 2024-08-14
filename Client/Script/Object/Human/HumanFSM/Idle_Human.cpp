#include "Idle_Human.h"
#include "../Human.h"

void Idle_Human::StateEnter()
{
	Debug::Log("Idle_Human");
	owner->GetAnimator()->ChangeAnimation("Idle", true);
}

void Idle_Human::StateUpdate()
{
}

void Idle_Human::StateExit()
{
}
