#include "pch.h"
#include "GameApp.h"

bool GameApp::isEnd = false;
Vector2 GameApp::scrennSize = { 0,0 };

void GameApp::Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height)
{
	scrennSize = { _width , _height };
	m_hinstance = _hinstance;
	m_window = new WindowSystem(_hinstance, _title, Vector2(_width, _height));
	m_window->Initialize();
	FMODSystem::Initialize();
	D2DRender::Initialize(m_window->GetHandle());
	Time::Initialize();
	Input::Initialize();
}	

void GameApp::Run()
{
	MSG msg;
	while (!isEnd)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Time::Update();
			Input::Update();
			FixedUpdate();
			EarlyUpdate();
			Update();
			LateUpdate();
			StateUpdate();
			Render();
		}
	}
}

void GameApp::Release()
{
	D2DRender::Release();
	WorldManager::Release();
	if (gameManager) delete gameManager;
}

void GameApp::FixedUpdate()
{
	static float deltaCount;
	deltaCount += Time::deltaTime;
	while (deltaCount >= 0.02f)
	{
		if (CollisionManager::ProcessCycle == 0)
			CollisionManager::CollsionProcess();
		if(gameManager) gameManager->FixedUpdate();
		WorldManager::FixedUpdate();
		deltaCount -= 0.02f;
	}
}

void GameApp::EarlyUpdate()
{
	if(CollisionManager::ProcessCycle == 1)
		CollisionManager::CollsionProcess();
	if (gameManager) gameManager->EarlyUpdate();
	WorldManager::EarlyUpdate();
	ButtonManager::EarlyUpdate();
}

void GameApp::Update()
{
	if (gameManager) gameManager->Update();
	WorldManager::Update();
	FMODSystem::Update();
}

void GameApp::LateUpdate()
{
	if (CollisionManager::ProcessCycle == 2)
		CollisionManager::CollsionProcess();
	if (gameManager) gameManager->LateUpdate();
	WorldManager::LateUpdate();
	ButtonManager::LateUpdate();
}

void GameApp::StateUpdate()
{
	WorldManager::StateUpdate();
	Input::StateUpdate();
}

void GameApp::Render()
{
	D2DRender::BeginDraw();
	WorldManager::Render();
	D2DRender::EndDraw();
}