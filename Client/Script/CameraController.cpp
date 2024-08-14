#include "CameraController.h"


void CameraController::Start()
{
	m_myCamera = gameObject->GetComponent<Camera2D>();
}

void CameraController::Update()
{
	Vector2 SetPos = Vector2::Zero;
	Vector2 SetSca = Vector2::One;

	// ===================카메라조작===================
	if (m_cameraMode == eCameraMode::Controll)
	{
		SetPos = gameObject->transform->position +
			InputManager::GetCameraMoveForce() * m_moveSpd * Time::GetDeltaTime(1000.0f);

		float distasnce = player->transform->position.Distance(SetPos);
		if (distasnce >= 800.0f)
		{
			Vector2 direction = (SetPos - player->transform->position).Normalize();
			SetPos = player->transform->position + direction * 800.0f;
		}
		SetSca = Vector2(1.3f, 1.3f);
		if (InputManager::GetCameraMoveForce() == Vector2::Zero)
			m_cameraMode = eCameraMode::PlayerZoom;
	}
	// ===================플레이어줌===================
	else if (m_cameraMode == eCameraMode::PlayerZoom)
	{
		if (player)
		{
			SetPos = player->transform->position;
		}
		if (InputManager::GetCameraMoveForce() != Vector2::Zero)
			m_cameraMode = eCameraMode::Controll;
		if (InputManager::KeyIsDown('R'))
		{
			m_cameraMode = eCameraMode::MapZoom;
		}
	}
	// ===================한눈에보기===================
	else if (m_cameraMode == eCameraMode::MapZoom)
	{
		SetSca = Vector2(3.0f, 3.0f);
		if (InputManager::KeyIsDown('R'))
		{
			m_cameraMode = eCameraMode::PlayerZoom;
		}
	}
	
	gameObject->transform->position =
		MathF.Lerp(gameObject->transform->position,
			SetPos, 7.0f * Time::deltaTime);

	Vector2 oldScale = gameObject->transform->scale;

	gameObject->transform->scale =
		MathF.Lerp(gameObject->transform->scale,
			SetSca, 7.0f * Time::deltaTime);
}

void CameraController::FixedUpdate()
{
	if (isShaking)
		Shaking();
}

void CameraController::SetShake(bool _status, float _power)
{
	isShaking = _status;
	m_shakePower = _power;
}

void CameraController::Shaking()
{
	m_shakePos.x = (float)(rand() % 100 + 1) - 50;
	m_shakePos.y = (float)(rand() % 100 + 1) - 50;
	m_shakePos *= m_shakePower;
}
