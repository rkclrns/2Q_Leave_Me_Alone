#include "Stage_01.h"
#include "ScriptHeaders.h"
#include "Contents.h"

void Stage_01::WorldLoad()
{
	Actor* player = CreateObject<Actor>(L"Player", LayerTag::Object, ObjectTag::Player);
	player->AddComponent<Player>();

	Maincamera->SetBackGroundColor(D2D1::ColorF(D2D1::ColorF::Black));
	Maincamera->gameObject->transform->scale = Vector2(2, 2);
	CameraController* cameraConroller = Maincamera->gameObject->AddComponent<CameraController>();
	cameraConroller->player = player;
	GameManager::cameraController = cameraConroller;
}

void Stage_01::WorldDestroy()
{
}

void Stage_01::WorldEnter()
{
	Floor_01* floor1 = CreateObject<Actor>(L"Floor01", LayerTag::BackGround, ObjectTag::Defalut)->AddComponent<Floor_01>();
	floor1->Set(L"Stage_01", L"Floor_01");

}

void Stage_01::WorldExit()
{
	WorldManager::DestroyWorld(this->GetName());
}
