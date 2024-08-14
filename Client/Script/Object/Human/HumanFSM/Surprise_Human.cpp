#include "Surprise_Human.h"
#include "../Human.h"

void Surprise_Human::StateEnter()
{
	Debug::Log("Surprise_Human");
	owner->GetAnimator()->ChangeAnimation("Surprise", false);
}

void Surprise_Human::StateUpdate()
{
	ChangeState_To_AniEnd("RUN");
}

void Surprise_Human::StateExit()
{
}
