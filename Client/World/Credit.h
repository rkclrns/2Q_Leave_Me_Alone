#pragma once
#include "Application.h"


class Credit
	: public World
{
public:
	void WorldLoad() override;
	void WorldDestroy() override;
	void WorldEnter() override;
	void WorldExit() override;

private:
};