#pragma once
#include "Key.h"
#include "Mouse.h"
#include "GamePad.h"

class Input

{
public:
	static void Initialize();
	static void Update();
	static void StateUpdate();
	static void Release();

	static void GetKeyDown(int _keyCode);
	static void GetKeyUp(int _keyCode);
	static void GetMouseMove();

	//===================Key===================
	static bool KeyIsDown(int _keyCode);
	static bool KeyIsHold(int _keyCode);
	static bool KeyIsUp(int _keyCode);
	//===================Mouse===================
	static bool MouseIsDown(int _type);
	static bool MouseIsHold(int _type);
	static bool MouseIsUp(int _type);
	static Vector2 MousePosition();
	//===================GamePad===================
	static bool PadIsDown(int button, int _handle = 0);
	static bool PadIsHold(int button, int _handle = 0);
	static bool PadIsUp(int button, int _handle = 0);
	static Vector2 GetPadStickForce(GamePad::StickType _type, int _handle = 0);
	static float GetPadTriggerForce(GamePad::TriggerType _type, int _handle = 0);
	// 패드 진동
	static void SetPadVibration(WORD _leftMotor, WORD _rightMotor, int _handle = 0);
	static int  ConnectedPadCount() { return m_pads.size(); }
private:
	static Key*		m_key;
	static Mouse*	m_mouse;
	static std::vector<GamePad*> m_pads;
};
