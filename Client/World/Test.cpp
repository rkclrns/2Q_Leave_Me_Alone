#include "Test.h"
#include "ScriptHeaders.h"
#include "Contents.h"

// 월드를 만들 때 딱 한번 호출
void Test::WorldLoad()
{
	Actor* player = CreateObject<Actor>(L"Player", LayerTag::Object, ObjectTag::Player);
	player->AddComponent<Player>();

	Maincamera->SetBackGroundColor(D2D1::ColorF(D2D1::ColorF::Black));
	Maincamera->gameObject->transform->scale = Vector2(2, 2);
	CameraController* cameraConroller = Maincamera->gameObject->AddComponent<CameraController>();
	cameraConroller->player = player;
	GameManager::cameraController = cameraConroller;

	// light Overlay 설정
	Maincamera->SetLayerProperty(LayerTag::Layer_01, Layer::Blending);
}

// 월드를 삭제될 떄 딱 한번
void Test::WorldDestroy()
{
}

// 월드 교체 될때 한번
void Test::WorldEnter()
{
	Floor_01* floor1 = CreateObject<Actor>(L"Floor01", LayerTag::BackGround, ObjectTag::Defalut)->AddComponent<Floor_01>();
	floor1->Set(L"Stage_01", L"Floor_01");


	Actor* cat = CreateObject<Actor>(L"Cat", LayerTag::Object, ObjectTag::Defalut);
	cat->AddComponent<Cat>();


	Actor* human = CreateObject<Actor>(L"Enemy", LayerTag::Object, ObjectTag::Monster);
	human->AddComponent<Human>();
}

// 월드 나갈 때 한번
void Test::WorldExit()
{
	WorldManager::DestroyWorld(this->GetName());
}
