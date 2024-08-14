#pragma once
#include "Application.h"

class FloorBase;

class StageBase
	: public World
{
public:

	std::vector<FloorBase*> floors;

	virtual void WorldLoad() override;
	virtual void WorldDestroy() override;
	virtual void WorldEnter() override;
	virtual void WorldExit() override;
private:
};

