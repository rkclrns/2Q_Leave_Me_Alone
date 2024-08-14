#pragma once
#include "Script/Object/ObjectBase.h"

// FSM이 들어가는(animation이 있는) Object들이 공통으로 사용할 Interface
class Animator2D;
class FiniteStateMachine;
class FMODPlayer;
class IFSMObjectCore : public ObjectBase
{
public:
	virtual void Start();
	virtual void Update();

	Animator2D* GetAnimator() { return m_animator; }

protected:
	Animator2D* m_animator;
	FMODPlayer* m_soundPlayer;
};