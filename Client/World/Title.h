#pragma once
#include "Application.h"


class Title 
	: public World
{
public:
	void WorldLoad() override;
	void WorldDestroy() override;
	void WorldEnter() override;
	void WorldExit() override;

private:
};