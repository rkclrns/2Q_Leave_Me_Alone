#include "pch.h"
#include "Input.h"

Key*		Input::m_key;
Mouse*		Input::m_mouse;
std::vector<GamePad*> Input::m_pads;

void Input::Initialize()
{
	m_key = new Key();
	m_mouse = new Mouse();
	for (int i = 0; i < XUSER_MAX_COUNT; ++i)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));
		DWORD dwResult = XInputGetState(i, &state);
		if (dwResult != ERROR_SUCCESS) break;

		GamePad* pad = new GamePad(i);
		pad->Update();
		if (pad->IsConnected())
		{
			m_pads.push_back(pad);
		}
		else
		{
			delete pad;
		}
	}
}

void Input::Update()
{
	m_mouse->Update();
	for (GamePad* pad : m_pads)
	{
		pad->Update();
	}
}

void Input::StateUpdate()
{
	m_key->ResetKey();
}

void Input::Release()
{
	SAFE_DELETE(m_key);
	SAFE_DELETE(m_mouse);
	for (GamePad* pad : m_pads)
	{
		SAFE_DELETE(pad);
	}
}

void Input::GetKeyDown(int _keyCode)
{
	m_key->GetKeyDown(_keyCode);
}

void Input::GetKeyUp(int _keyCode)
{
	m_key->GetKeyUp(_keyCode);
}

bool Input::KeyIsDown(int _keyCode)
{
	return m_key->KeyDown(_keyCode);
}

bool Input::KeyIsHold(int _keyCode)
{
	return m_key->KeyHold(_keyCode);
}

bool Input::KeyIsUp(int _keyCode)
{
	return m_key->KeyUp(_keyCode);
}

bool Input::MouseIsDown(int _type)
{
	return m_mouse->MouseDown(_type);
}

bool Input::MouseIsHold(int _type)
{
	return m_mouse->MouseHold(_type);
}

bool Input::MouseIsUp(int _type)
{
	return m_mouse->MouseUp(_type);
}

Vector2 Input::MousePosition()
{
	return m_mouse->MousePosition();
}

bool Input::PadIsDown(int button, int _handle)
{
	if (m_pads.empty()) return false;
	if (button <= 0) return false;
	else return m_pads[_handle]->IsConnected() ? m_pads[_handle]->ButtonDown(button) : false;
}

bool Input::PadIsHold(int button, int _handle)
{
	if (m_pads.empty()) return false;
	if (button <= 0) return false;
	else return m_pads[_handle]->IsConnected() ? m_pads[_handle]->ButtonHold(button) : false;
}

bool Input::PadIsUp(int button, int _handle)
{
	if (m_pads.empty()) return false;
	if (button <= 0) return false;
	else return m_pads[_handle]->IsConnected() ? m_pads[_handle]->ButtonUp(button) : false;
}

Vector2 Input::GetPadStickForce(GamePad::StickType _type, int _handle)
{
	if (m_pads.empty()) return false;
	else return m_pads[_handle]->IsConnected() ? m_pads[_handle]->GetStickForce(_type) : Vector2::Zero;
}

float Input::GetPadTriggerForce(GamePad::TriggerType _type, int _handle)
{
	if (m_pads.empty()) return false;
	else return m_pads[_handle]->IsConnected() ? m_pads[_handle]->GetTriggerForce(_type) : 0.0f;
}

void Input::SetPadVibration(WORD _leftMotor, WORD _rightMotor, int _handle)
{
	if (m_pads.empty()) return;
	else m_pads[_handle]->SetVibration(_leftMotor, _rightMotor);
}