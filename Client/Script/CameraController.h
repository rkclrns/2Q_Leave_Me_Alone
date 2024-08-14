#pragma once
#include "Application.h"

enum class eCameraMode
{
	PlayerZoom, // �÷��̾ ���ϴ� ����
	MapZoom,	// ��ü ���� ���ϴ� ����
	Controll,	// ���� ������ �� �ִ� ����
};

class CameraController
	: public Script
{
public:
	void Start();
	void Update();
	void FixedUpdate();

	void SetShake(bool _status, float _power = 1.f);
	void Shaking();

	eCameraMode GetMode() { return m_cameraMode; }
	// ��Ŀ�� ������Ʈ
	Actor* player;

private:
	// ī�޶� ������Ʈ
	Camera2D* m_myCamera;
	// ī�޶� ���� ����
	Rect_F m_limitRange;
	// ī�޶� �ɼ�
	Vector2 m_offset;
	// ī�޶� ���ǵ�
	float m_moveSpd = 15.f;

	// ȭ�� ����
	bool isShaking;
	float m_shakePower;
	Vector2 m_shakePos;

	eCameraMode m_cameraMode = eCameraMode::PlayerZoom;
};
