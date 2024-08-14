#pragma once
#include "Application.h"

class FloorBase
	: public Script
{
public:

	void Start();
	void Set(std::wstring _stageName, std::wstring _floorName);
	void Reset();

protected:

	BoxCollider2D*	  m_floor;
	SpriteRenderer2D* m_backGround;
	Vector2			  m_size;

	int objectCount = 0;

	std::wstring m_stageName;		// ex) stage01
	std::wstring m_floorName;		// ex) floor_01

	void LoadFromCSV();
};