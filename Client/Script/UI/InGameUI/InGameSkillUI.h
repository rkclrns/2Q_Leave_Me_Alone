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
	bool m_isSkill = false; // ��ų ������ΰ�?
	bool m_canSkill = true; // ��ų�� ����� �� �ִ°�?
	float m_skillTimer = 0; // ��ų ��Ÿ��
};

