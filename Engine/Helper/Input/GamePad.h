#pragma once



class GamePad
{
    using PADHANDLE = int;
    enum class StickType;
    enum class TriggerType;
public:
    GamePad(PADHANDLE _handle);
    virtual ~GamePad() {}
     
    void Update();
    bool IsConnected() const { return m_connected; }
    bool ButtonDown(WORD button) const;
    bool ButtonHold(WORD button) const;
    bool ButtonUp(WORD button) const;
    Vector2 GetStickForce(StickType _type) const;
    float GetTriggerForce(TriggerType _type) const;

    void SetVibration(WORD leftMotor, WORD rightMotor);
    static void SetDeadZone(float _value) { m_deadZone = _value; }

private:
    PADHANDLE m_handle;
    XINPUT_STATE m_state;
    XINPUT_STATE m_prevState;
    bool m_connected;
    static float m_deadZone;

public:
   
    enum ButtonType
    {
        A = XINPUT_GAMEPAD_A,
        B = XINPUT_GAMEPAD_B,
        X = XINPUT_GAMEPAD_X,
        Y = XINPUT_GAMEPAD_Y,
        D_LEFT = XINPUT_GAMEPAD_DPAD_LEFT,
        D_RIGHT = XINPUT_GAMEPAD_DPAD_RIGHT,
        D_UP = XINPUT_GAMEPAD_DPAD_UP,
        D_DOWN = XINPUT_GAMEPAD_DPAD_DOWN,
        LEFT_THUMB = XINPUT_GAMEPAD_LEFT_THUMB,
        RIGHT_THUMB = XINPUT_GAMEPAD_RIGHT_THUMB,
        LEFT_SHOULD = XINPUT_GAMEPAD_LEFT_SHOULDER,
        RIGHT_SHOULD = XINPUT_GAMEPAD_RIGHT_SHOULDER,
        START = XINPUT_GAMEPAD_START,
        BACK = XINPUT_GAMEPAD_BACK
    };

    enum class StickType
    {
        LEFT,
        RIGHT,
    };

    enum class TriggerType
    {
        LEFT,
        RIGHT,
    };
};

