#pragma once
#include "StageBase.h"


class Stage_01
	: public StageBase
{
public:
	virtual void WorldLoad() override;
	virtual void WorldDestroy() override;
	virtual void WorldEnter() override;
	virtual void WorldExit() override;
private:
};
