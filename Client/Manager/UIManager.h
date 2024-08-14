#pragma once
#include "Script/UI/PauseUI/PauseUI.h"
#include "Script/UI/InGameUI/InGameUI.h"
#include "Script/UI/ClearUI/ClearUI.h"

class UIManager
{
public:
	static void Initialize();
	static PauseUI* pauseUI;
	static InGameUI* inGameUI;
	static ClearUI* clearUI;
};

