#pragma once
#include "FloorBase.h"

class Floor_02 : public FloorBase
{
public:
	void Start();
private:
	RectRenderer* m_map;
};

