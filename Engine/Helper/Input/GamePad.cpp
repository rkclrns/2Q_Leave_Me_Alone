#include "pch.h"
#include "GamePad.h"

float GamePad::m_deadZone = 0.3f;

GamePad::GamePad(PADHANDLE _handle)
	: m_handle(_handle), m_connected(false)
{
	ZeroMemory(&m_state, sizeof(XINPUT_STATE));
	ZeroMemory(&m_prevState, sizeof(XINPUT_STATE));
}

void GamePad::Update()
{
    m_prevState = m_state;
    ZeroMemory(&m_state, sizeof(XINPUT_STATE));

    DWORD result = XInputGetState(m_handle, &m_state);

    if (result == ERROR_SUCCESS)
    {
        m_connected = true;
    }
    else
    {
        m_connected = false;
    }
}

bool GamePad::ButtonDown(WORD button) const
{
    return (m_state.Gamepad.wButtons & button) && !(m_prevState.Gamepad.wButtons & button);
}

bool GamePad::ButtonHold(WORD button) const
{
    return (m_state.Gamepad.wButtons & button) && (m_prevState.Gamepad.wButtons & button);
}

bool GamePad::ButtonUp(WORD button) const
{
    return !(m_state.Gamepad.wButtons & button) && (m_prevState.Gamepad.wButtons & button);
}

void GamePad::SetVibration(WORD leftMotor, WORD rightMotor)
{
    XINPUT_VIBRATION vibration;
    ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
    vibration.wLeftMotorSpeed = leftMotor;
    vibration.wRightMotorSpeed = rightMotor;
    XInputSetState(m_handle, &vibration);
}

Vector2 GamePad::GetStickForce(StickType _type) const
{
    float xForce = 0.0f, yForce = 0.0f;

    if (_type == StickType::LEFT)
    {
        xForce = static_cast<float>(m_state.Gamepad.sThumbLX) / 32768.0f;
        yForce = static_cast<float>(m_state.Gamepad.sThumbLY) / 32768.0f;
    }
    else if (_type == StickType::RIGHT)
    {
        xForce = static_cast<float>(m_state.Gamepad.sThumbRX) / 32768.0f;
        yForce = static_cast<float>(m_state.Gamepad.sThumbRY) / 32768.0f;
    }

    if (std::abs(xForce) < m_deadZone) xForce = 0.0f;
    if (std::abs(yForce) < m_deadZone) yForce = 0.0f;

    return Vector2(xForce, -yForce);
}

float GamePad::GetTriggerForce(TriggerType _type) const
{
    float force = 0.0f;
    if (_type == TriggerType::LEFT)
    {
        force = static_cast<float>(m_state.Gamepad.bLeftTrigger) / (float)UCHAR_MAX;
    }
    else if (_type == TriggerType::RIGHT)
    {
        force = static_cast<float>(m_state.Gamepad.bRightTrigger) / (float)UCHAR_MAX;
    }

    if (std::abs(force) < m_deadZone) force = 0.0f;

    return force;
}
