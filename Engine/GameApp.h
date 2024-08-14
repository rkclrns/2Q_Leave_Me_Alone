#pragma once
#include "pch.h"

#include "Render/D2DRender.h"

#include "World/Manager/WorldManager.h"
#include "Resource/Manager/ResourceManager.h"
#include "Collision/Manager/CollisionManager.h"
#include "Collision/Manager/ButtonManager.h"
#include "GameManager/GameManager.h"

#include "Window/WindowSystem.h"
#include "SoundSystem/FMODSystem.h"

// �ֻ�� �������̽�
// Ŭ���̾�Ʈ ������ GameApp�� include �� ����ؼ� ���� ��� ����� ����� �� �մ�.

class GameApp
{
public:

	void Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height);

	void Run();

	void Release();

	static void		Quit() { isEnd = true; }

protected:
	template<class T> void SetGameManager() {
		SAFE_DELETE(gameManager) 
		gameManager = new T();
		gameManager->Initialize();
	}
	void FixedUpdate();
	void EarlyUpdate();
	void Update();
	void LateUpdate();
	void Render();
	void StateUpdate();
private:

	static bool		isEnd;
	static Vector2  scrennSize;

	Engine::GameManager* gameManager = nullptr;
	HINSTANCE m_hinstance;
	WindowSystem* m_window;
};

