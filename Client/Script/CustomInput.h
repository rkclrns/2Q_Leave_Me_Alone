#pragma once

struct CustomInput
{
	int key[KEYBOARD_MAX + 1];
	CustomInput()
	{
		for (int i = 0; i < KEYBOARD_MAX + 1; i++)
		{
			key[i + 1] = - 1;
		}
	}
	int& operator[](char _key)
	{
		return key[(int)_key];
	}
	int& operator[](int _key)
	{
		return key[_key];
	}
};