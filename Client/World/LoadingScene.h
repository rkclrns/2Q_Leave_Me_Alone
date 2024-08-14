#pragma once
#include "Application.h"

class LoadingUI;

class LoadingScene
	: public World
{
public:
	virtual void WorldLoad() override;
	virtual void WorldDestroy() override;
	virtual void WorldEnter() override;
	virtual void WorldExit() override;

	World* changeWorld;

private:
	LoadingUI* UI;
};




