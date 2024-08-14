#pragma once
#include "Script/UI/UIBase.h"

class InGameSkillUI
	:public UIBase
{
public:
	void Start();
	void Update();
protected:
private:
	bool m_isSkill = false; // 스킬 사용중인가?
	bool m_canSkill = true; // 스킬을 사용할 수 있는가?
	float m_skillTimer = 0; // 스킬 쿨타임
};

