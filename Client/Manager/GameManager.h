#pragma once
#include "Application.h"
#include "FadeSystem.h"
#include "UIManager.h"
#include "Script/CameraController.h"
// 굳이 오브젝트로 추가하지 않고도 전역적으로
// 게임을 관리해줄 수 있는 친구입니다
// BGM이나 공통UI들은 여기다 묶어도 될듯하네요 ㅇㅇ

class GameManager
	: public Engine::GameManager
{
public:
	GameManager();
	virtual ~GameManager();
	void Start();
	void Update();
	
	static CameraController* cameraController;
	static FadeSystem* fader;

	static float BGMVolume;
	static float SFXVolume;

};

enum eSoundGroup
{
	BackGround,
	Effect,
	Voice,
	GroupSize
};