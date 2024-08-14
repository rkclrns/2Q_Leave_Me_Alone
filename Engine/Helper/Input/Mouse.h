#pragma once

class Mouse
{
public:
	enum Type // ¸¶¿ì½º
	{
		LEFT = VK_LBUTTON,
		ROLL = VK_MBUTTON,
		RIGHT = VK_RBUTTON,
	};
	Mouse() = default;
	virtual ~Mouse() {}

	virtual void Update();

	Vector2 MousePosition() { return mousePos; }
	bool MouseDown(int _code);
	bool MouseHold(int _code);
	bool MouseUp(int _code);

private:
	struct MouseState {
		bool Left = false;
		bool Right = false;
		bool Mid = false;
	};
	MouseState curState;
	MouseState preState;
	Vector2	   mousePos;

};