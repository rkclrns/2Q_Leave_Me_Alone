#include "pch.h"
#include "ResourceManager.h"

std::wstring ResourceManager::m_assetPath = L"Asset/";
std::unordered_map<std::wstring, Resource::Sprite2D*>	 ResourceManager::m_spriteMap;
std::unordered_map<std::wstring, Resource::Animation2D*> ResourceManager::m_animationMap;
std::unordered_map<std::wstring, Resource::FMODSound*>   ResourceManager::m_audioMap;
std::unordered_map<std::wstring, Resource::Font*>		 ResourceManager::m_fontMap;

void ResourceManager::Release()
{
	for (auto it = m_spriteMap.begin(); it != m_spriteMap.end(); ++it)
	{
		delete it->second;
	}
	m_spriteMap.clear();
	for (auto it = m_animationMap.begin(); it != m_animationMap.end(); ++it)
	{
		delete it->second;
	}
	m_animationMap.clear();
	for (auto it = m_audioMap.begin(); it != m_audioMap.end(); ++it)
	{
		delete it->second;
	}
	m_audioMap.clear();
	for (auto it = m_fontMap.begin(); it != m_fontMap.end(); ++it)
	{
		delete it->second;
	}
	m_fontMap.clear();
}

Resource::Sprite2D* ResourceManager::AddSprite2D(const std::wstring& _key, const std::wstring& _path, SpriteData _data)
{
	std::wstring temp = m_assetPath + _path;
	Resource::Sprite2D* _sprite = GetSprite2D(_key);
	if (_sprite != nullptr)
	{
		return _sprite;
	}
	else
	{
		_sprite = new Resource::Sprite2D(_key, temp, ResourceType::Sprite2D, _data);
		m_spriteMap.insert(std::make_pair(_key, _sprite));
	}
	return _sprite;
}

Resource::Animation2D* ResourceManager::AddAnimation2D(const std::wstring& _key, Resource::Sprite2D* _sprite, std::vector<AnimationData>& _data)
{
	Resource::Animation2D* _anime = GetAnimation2D(_key);
	if (_anime != nullptr)
	{
		return _anime;
	}
	else
	{
		_anime = new Resource::Animation2D(_key, ResourceType::Animation2D, _sprite, _data);
		m_animationMap.insert(std::make_pair(_key, _anime));
	}
	return _anime;
}

Resource::Animation2D* ResourceManager::AddAnimation2DFromCSV(const std::wstring& _key, const std::wstring& _path)
{
	Resource::Animation2D* _anime = GetAnimation2D(_key);
	if (_anime != nullptr)
	{
		return _anime;
	}
	else
	{
		std::wstring temp = m_assetPath + _path;
		std::vector<AnimationData> datas;
		std::wifstream file(temp);
		if (!file.is_open()) assert(false);

		std::wstring line;			// 한줄의 문자열	
		std::wstring token;
		
		getline(file, line);
		Resource::Sprite2D* sprite = GetSprite2D(line);
		if (!sprite) assert(false);

		// 파일이 끝에 도달할 때까지 반복
		while (getline(file, line))
		{
			if (line.empty()) break;
			std::wstringstream wss(line); // 한 줄을 읽어서 wstringstream에 저장
			AnimationData data;
			// ','를 기준으로 문자열을 분리
			{
				// 인덱스, 듀레이션, 오프셋
				getline(wss, token, L',');
				data.index = std::stoi(token);  // 인덱스는 정수로 변환
				getline(wss, token, L',');
				data.duration = std::stof(token);  // 듀레이션을 float으로 변환
				getline(wss, token, L',');
				data.offset.x = std::stof(token);  // x 오프셋을 float으로 변환
				getline(wss, token, L',');
				data.offset.y = std::stof(token);  // y 오프셋을 float으로 변환
			}
			datas.push_back(data);
		}
		_anime = new Resource::Animation2D(_key, ResourceType::Animation2D, sprite, datas);
		m_animationMap.insert(std::make_pair(_key, _anime));
		return _anime;
	}
	return nullptr;
}

Resource::FMODSound* ResourceManager::AddFMODSound(const std::wstring& _key, const std::wstring& _path, bool isLoop, int _group)
{
	std::wstring temp = L"Asset/" + _path;
	Resource::FMODSound* _audio = GetFMODSound(_key);
	if (_audio != nullptr)
	{
		return _audio;
	}
	else
	{
		_audio = new Resource::FMODSound(_key, temp, ResourceType::AudioClip, isLoop, _group);
		m_audioMap.insert(std::make_pair(_key, _audio));
	}
	return _audio;
}

Resource::Font* ResourceManager::AddFont(const std::wstring& _key, const std::wstring& _path)
{
	std::wstring temp = L"Asset/" + _path;
	Resource::Font* _font = GetFont(_key);
	if (_font != nullptr)
	{
		return _font;
	}
	else
	{
		_font = new Resource::Font(_key, temp, ResourceType::Font);
		m_fontMap.insert(std::make_pair(_key, _font));
	}
	return _font;
}

Resource::Sprite2D* ResourceManager::GetSprite2D(const std::wstring& _key)
{
	auto it = m_spriteMap.find(_key);

	if (it == m_spriteMap.end())
		return nullptr;

	return it->second;
}

Resource::Animation2D* ResourceManager::GetAnimation2D(const std::wstring& _key)
{
	std::unordered_map<std::wstring, Resource::Animation2D*>::iterator it = m_animationMap.find(_key);

	if (it == m_animationMap.end())
		return nullptr;

	return it->second;
}

Resource::FMODSound* ResourceManager::GetFMODSound(const std::wstring& _key)
{
	std::unordered_map<std::wstring, Resource::FMODSound*>::iterator it = m_audioMap.find(_key);

	if (it == m_audioMap.end())
		return nullptr;

	return it->second;
}

Resource::Font* ResourceManager::GetFont(const std::wstring& _key)
{
	std::unordered_map<std::wstring, Resource::Font*>::iterator it = m_fontMap.find(_key);

	if (it == m_fontMap.end())
		return nullptr;

	return it->second;
}

bool ResourceManager::ReleaseSprite2D(const std::wstring& _key)
{
	auto it = m_spriteMap.find(_key);
	if (it == m_spriteMap.end())
		return false;
	delete (*it).second;
	m_spriteMap.erase(it);
	return true;
}

bool ResourceManager::ReleaseAnimation2D(const std::wstring& _key)
{
	auto it = m_animationMap.find(_key);
	if (it == m_animationMap.end())
		return false;
	delete (*it).second;
	m_animationMap.erase(it);
	return true;
}

bool ResourceManager::ReleaseFMODSound(const std::wstring& _key)
{
	auto it = m_audioMap.find(_key);
	if (it == m_audioMap.end())
		return false;
	delete (*it).second;
	m_audioMap.erase(it);
	return true;
}

bool ResourceManager::ReleaseFont(const std::wstring& _key)
{
	auto it = m_fontMap.find(_key);
	if (it == m_fontMap.end())
		return false;
	delete (*it).second;
	m_fontMap.erase(it);
	return true;
}

void ResourceManager::Clear()
{
	for (auto it = m_spriteMap.begin(); it != m_spriteMap.end(); ++it)
	{
		delete it->second;
	}
	m_spriteMap.clear();
	for (auto it = m_animationMap.begin(); it != m_animationMap.end(); ++it)
	{
		delete it->second;
	}
	m_animationMap.clear();
	for (auto it = m_audioMap.begin(); it != m_audioMap.end(); ++it)
	{
		delete it->second;
	}
	m_audioMap.clear();
	for (auto it = m_fontMap.begin(); it != m_fontMap.end(); ++it)
	{
		delete it->second;
	}
	m_fontMap.clear();
}
