#pragma once
#include "Application.h"

struct LoadSprite abstract
{
	std::wstring _key = L"";
	std::wstring _path = L"";
	SpriteData  _data = {};
	Resource::Sprite2D* Load()
	{
		return ResourceManager::AddSprite2D(_key, _path, _data);
	}
	Resource::Sprite2D* Get()
	{
		return ResourceManager::GetSprite2D(_key);
	}
	void Release()
	{
		ResourceManager::ReleaseSprite2D(_key);
	}
};

struct LoadAnimation abstract
{
	std::wstring _key = L"";
	std::wstring _spriteKey;
	std::vector<AnimationData> _data;
	Resource::Animation2D* Load()
	{
		return ResourceManager::AddAnimation2D(_key,
			ResourceManager::GetSprite2D(_spriteKey),
			_data);
	}
	Resource::Animation2D* Get()
	{
		return ResourceManager::GetAnimation2D(_key);
	}
	void Release()
	{
		ResourceManager::ReleaseAnimation2D(_key);
	}
};

struct LoadCSVAnimation abstract
{
	std::wstring _key = L"";
	std::wstring  _path = L"";
	Resource::Animation2D* Load()
	{
		return ResourceManager::AddAnimation2DFromCSV(_key, _path);
	}
	Resource::Animation2D* Get()
	{
		return ResourceManager::GetAnimation2D(_key);
	}
	void Release()
	{
		ResourceManager::ReleaseAnimation2D(_key);
	}
};

struct LoadSound abstract
{
	std::wstring _key = L"";
	std::wstring _path = L"";
	bool isLoop = false;
	int group = 0;

	Resource::FMODSound* Load()
	{
		return ResourceManager::AddFMODSound(_key, _path, isLoop, group);
	}
	Resource::FMODSound* Get()
	{
		return ResourceManager::GetFMODSound(_key);
	}
	void Release()
	{
		ResourceManager::ReleaseFMODSound(_key);
	}
};