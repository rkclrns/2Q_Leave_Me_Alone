#pragma once
#include "../Engine/GameApp.h"
#include "Manager/InputManager.h"

#define TITLE L"Leave Me Alone!"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

class GameApplication
	: public GameApp
{
public:
	void Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height);
	void LoadWorld();
	void LoadResource();
	void ReleaseResource();
};