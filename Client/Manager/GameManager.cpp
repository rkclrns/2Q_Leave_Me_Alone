#include "GameManager.h"
#include "WorldHeaders.h"

CameraController* GameManager::cameraController = nullptr;
FadeSystem* GameManager::fader;
float GameManager::BGMVolume = 1.0f;
float GameManager::SFXVolume = 1.0f;

GameManager::GameManager()
{
	UIManager::Initialize();
	fader = CreateObject<Actor>(L"FadeActor", LayerTag::UI, ObjectTag::UI)->AddComponent<FadeSystem>();
	SetPersistentObject(fader->gameObject, true);
}

GameManager::~GameManager()
{
}

void GameManager::Start()
{
}

void GameManager::Update()
{
	if (Input::KeyIsDown(112) && fader->IsFadeInEnd())
	{
		WorldManager::ChangeWorld(WorldManager::CreateWorld<Stage_01>("Stage_01", WorldTag::Play));
		//fader->SetFade(true);
	}
	if (Input::KeyIsDown(113))
	{ 
		WorldManager::ChangeWorld(WorldManager::CreateWorld<Test>("Test", WorldTag::Play));
	}
	if (Input::KeyIsDown(114))
	{
		WorldManager::ChangeWorld("Title");
	}

	if (WorldManager::GetActiveWorld()->GetTag() == WorldTag::Play)
	{
		//UIManager::clearUI->gameObject->SetActive(true);
		UIManager::inGameUI->gameObject->SetActive(true);

		if (InputManager::KeyIsDown(Key::ESCAPE))
		{
			if (UIManager::pauseUI->gameObject->GetState() == GameState::Active)
			{
				UIManager::pauseUI->gameObject->SetActive(false);
			}
			else
			{
				UIManager::pauseUI->gameObject->SetActive(true);
			}
		}
	}
	else
	{
		UIManager::pauseUI->gameObject->SetActive(false);
		UIManager::inGameUI->gameObject->SetActive(false);
		UIManager::clearUI->gameObject->SetActive(false);
	}
	if (Input::MouseIsDown(Mouse::LEFT))
	{
		Debug::Log("X : " + std::to_string(Input::MousePosition().x));
		Debug::Log("Y : " + std::to_string(Input::MousePosition().y));
	}
}