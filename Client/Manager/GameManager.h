#pragma once
#include "Application.h"
#include "FadeSystem.h"
#include "UIManager.h"
#include "Script/CameraController.h"
// ���� ������Ʈ�� �߰����� �ʰ� ����������
// ������ �������� �� �ִ� ģ���Դϴ�
// BGM�̳� ����UI���� ����� ��� �ɵ��ϳ׿� ����

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