#include "Test.h"
#include "ScriptHeaders.h"
#include "Contents.h"

// ���带 ���� �� �� �ѹ� ȣ��
void Test::WorldLoad()
{
	Actor* player = CreateObject<Actor>(L"Player", LayerTag::Object, ObjectTag::Player);
	player->AddComponent<Player>();

	Maincamera->SetBackGroundColor(D2D1::ColorF(D2D1::ColorF::Black));
	Maincamera->gameObject->transform->scale = Vector2(2, 2);
	CameraController* cameraConroller = Maincamera->gameObject->AddComponent<CameraController>();
	cameraConroller->player = player;
	GameManager::cameraController = cameraConroller;

	// light Overlay ����
	Maincamera->SetLayerProperty(LayerTag::Layer_01, Layer::Blending);
}

// ���带 ������ �� �� �ѹ�
void Test::WorldDestroy()
{
}

// ���� ��ü �ɶ� �ѹ�
void Test::WorldEnter()
{
	Floor_01* floor1 = CreateObject<Actor>(L"Floor01", LayerTag::BackGround, ObjectTag::Defalut)->AddComponent<Floor_01>();
	floor1->Set(L"Stage_01", L"Floor_01");


	Actor* cat = CreateObject<Actor>(L"Cat", LayerTag::Object, ObjectTag::Defalut);
	cat->AddComponent<Cat>();


	Actor* human = CreateObject<Actor>(L"Enemy", LayerTag::Object, ObjectTag::Monster);
	human->AddComponent<Human>();
}

// ���� ���� �� �ѹ�
void Test::WorldExit()
{
	WorldManager::DestroyWorld(this->GetName());
}
