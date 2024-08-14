#pragma once
#include "FloorBase.h"

class Floor_01 : public FloorBase
{
public:
	void Start();
	void Update();
private:
	RectRenderer* m_map;
};

