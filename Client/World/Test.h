#pragma once
#include "Application.h"

class Test : public World
{
public:
	virtual void WorldLoad() override;
	virtual void WorldDestroy() override;
	virtual void WorldEnter() override;
	virtual void WorldExit() override;

private:
	Actor* floor1;
};
