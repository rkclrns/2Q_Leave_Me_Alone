#pragma once
#include "Script/UI/UIBase.h"

// �޸չڽ��� ��Ƶо� 
class InGameHumanListUI
	:public UIBase
{
public:
	void Start();
	void Update();


protected:
private:
	std::vector<Actor*> m_humansList;

	int m_humanCounter = 0;
	int m_offset;
};

