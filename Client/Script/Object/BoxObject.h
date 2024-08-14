#pragma once
#include "Application.h"

class BoxObject
	: public Script
{
public:
	void Start();
protected:
	BoxCollider2D* body;
private:
};

