#pragma once
#include "Application.h"

enum class eCameraMode
{
	PlayerZoom, // 플레이어를 줌하는 상태
	MapZoom,	// 전체 맵을 줌하는 상태
	Controll,	// 직접 조작할 수 있는 상태
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
	// 포커싱 오브젝트
	Actor* player;

private:
	// 카메라 컴포넌트
	Camera2D* m_myCamera;
	// 카메라 범위 제한
	Rect_F m_limitRange;
	// 카메라 옵셋
	Vector2 m_offset;
	// 카메라 스피드
	float m_moveSpd = 15.f;

	// 화면 흔들기
	bool isShaking;
	float m_shakePower;
	Vector2 m_shakePos;

	eCameraMode m_cameraMode = eCameraMode::PlayerZoom;
};
