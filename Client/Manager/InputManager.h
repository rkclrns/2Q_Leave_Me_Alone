#pragma once
#include "Application.h"
#include "Script/CustomInput.h"

class InputManager
{
public:

	static void Initialize();
	// 이동 Force값을 반환
	static Vector2 GetMoveKeyForce();
	// 카메라 이동 Force값을 반환
	static Vector2 GetCameraMoveForce();

	static bool KeyIsDown(int _key);
	static bool KeyIsHold(int _key);
	static bool KeyIsUp(int _key);

	static CustomInput keySet;
	static CustomInput padSet;

private:
	 
	int a = 0;

};