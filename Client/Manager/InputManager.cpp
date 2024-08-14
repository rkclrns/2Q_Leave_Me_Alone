#include "InputManager.h"
CustomInput InputManager::keySet;
CustomInput InputManager::padSet;

void InputManager::Initialize()
{
	for (int i = 0; i < KEYBOARD_MAX + 1; i++)
	{
		keySet.key[i + 1] = i + 1;
	}
	// Pad Key
	padSet['E'] = GamePad::X;
	padSet[Key::SPACEBAR] = GamePad::A;
	padSet[Key::ESCAPE] = GamePad::START;

	padSet[Key::TAB] = GamePad::LEFT_SHOULD;
	padSet['R'] = GamePad::RIGHT_SHOULD;

	// MoveKey
	padSet[Key::LEFT] = GamePad::D_LEFT;
	padSet[Key::RIGHT] = GamePad::D_RIGHT;
	padSet[Key::UP] = GamePad::D_UP;
	padSet[Key::DOWN] = GamePad::D_DOWN;
}

Vector2 InputManager::GetMoveKeyForce()
{
	if (Input::GetPadStickForce(GamePad::StickType::LEFT).x != 0 ||
		Input::GetPadStickForce(GamePad::StickType::LEFT).y != 0)
	{
		return Input::GetPadStickForce(GamePad::StickType::LEFT);
	}
	else
	{
		Vector2 force;
		if (Input::KeyIsHold(keySet[Key::LEFT]) || Input::PadIsHold(padSet[Key::LEFT])) force.x = -1.f;
		else if (Input::KeyIsHold(keySet[Key::RIGHT]) || Input::PadIsHold(padSet[Key::RIGHT])) force.x = 1.f;
		if (Input::KeyIsHold(keySet[Key::UP]) || Input::PadIsHold(padSet[Key::UP])) force.y = -1.f;
		else if (Input::KeyIsHold(keySet[Key::DOWN]) || Input::PadIsHold(padSet[Key::DOWN])) force.y = 1.f;
		return force;
	}
	return Vector2::Zero;
}

Vector2 InputManager::GetCameraMoveForce()
{
	if (Input::GetPadStickForce(GamePad::StickType::RIGHT).x != 0 ||
		Input::GetPadStickForce(GamePad::StickType::RIGHT).y != 0)
	{
		return Input::GetPadStickForce(GamePad::StickType::RIGHT);
	}
	else
	{
		Vector2 force;
		if (Input::KeyIsHold(keySet[Key::LSHIFT]))
		{
			if (Input::KeyIsHold(keySet[Key::LEFT])) force.x = -1.f;
			else if (Input::KeyIsHold(keySet[Key::RIGHT])) force.x = 1.f;
			if (Input::KeyIsHold(keySet[Key::UP])) force.y = -1.f;
			else if (Input::KeyIsHold(keySet[Key::DOWN])) force.y = 1.f;
		}
		return force;
	}
}

bool InputManager::KeyIsDown(int _key)
{
	bool a = Input::KeyIsDown(keySet[_key]);
	bool b = Input::PadIsDown(padSet[_key]);
	bool isDown = Input::KeyIsDown(keySet[_key]) || Input::PadIsDown(padSet[_key]);
	return isDown;
}

bool InputManager::KeyIsHold(int _key)
{
	bool isHold = Input::KeyIsHold(keySet[_key]) || Input::PadIsHold(padSet[_key]);
	return isHold;
}

bool InputManager::KeyIsUp(int _key)
{
	bool isUp = Input::KeyIsUp(keySet[_key]) || Input::PadIsUp(padSet[_key]);
	return isUp;
}