#pragma once
#include "Application.h"
#include "Script/CustomInput.h"

class InputManager
{
public:

	static void Initialize();
	// �̵� Force���� ��ȯ
	static Vector2 GetMoveKeyForce();
	// ī�޶� �̵� Force���� ��ȯ
	static Vector2 GetCameraMoveForce();

	static bool KeyIsDown(int _key);
	static bool KeyIsHold(int _key);
	static bool KeyIsUp(int _key);

	static CustomInput keySet;
	static CustomInput padSet;

private:
	 
	int a = 0;

};