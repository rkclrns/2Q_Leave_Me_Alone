#include "FloorBase.h"
#include "Script/Object/InteractiveObject/MovingObject/oldBook/OldBook.h"
#include "Script/Object/InteractiveObject/DisposableObject/s_lamp/S_lamp.h"
#include "Script/Object/InteractiveObject/MovingObject/broom/Broom.h"
#include "Script/Object/InteractiveObject/MovingObject/chair/Chair.h"
#include "Script/Object/InteractiveObject/MovingObject/doll/Doll.h"
#include "Script/Object/InteractiveObject/FixedObject/bed/Bed.h"
#include "Script/Object/InteractiveObject/FixedObject/clock_big/Clock_big.h"
#include "Script/Object/InteractiveObject/FixedObject/m_window01/M_window01.h"
#include "Script/Object/InteractiveObject/FixedObject/mannequin/Mannequin.h"
#include "Script/Object/InteractiveObject/FixedObject/mirror_01/Mirror_01.h"
#include "Script/Object/InteractiveObject/FixedObject/statue/Statue.h"
#include "Script/Object/InteractiveObject/FixedObject/TV/TV.h"
#include "Script/Object/InteractiveObject/DisposableObject/chandelier/Chandelier.h"
#include "Script/Object/InteractiveObject/DisposableObject/bottle/Bottle.h"
#include "Script/Object/InteractiveObject/DisposableObject/pot/Pot.h"
#include "Script/Object/InteractiveObject/DisposableObject/s_frame01/S_frame01.h"
#include "Script/Object/InteractiveObject/DisposableObject/teaCup/TeaCup.h"
#include "Script/Object/InteractiveObject/DisposableObject/candleLight/CandleLight.h"

void FloorBase::Start()
{
    m_backGround = gameObject->AddComponent<SpriteRenderer2D>();
    Actor* actor;
    actor = CreateObject<Actor>(gameObject->GetName() + L"_Floor", LayerTag::Object, ObjectTag::HitBox);
    actor->transform->SetParent(gameObject->transform);
    m_floor = actor->AddComponent<BoxCollider2D>();
    m_floor->colliderTag = "Floor";
    m_floor->SetRenderInfo(D2D1::ColorF(D2D1::ColorF::BlueViolet));
}

void FloorBase::Set(std::wstring _stageName, std::wstring _floorName)
{
    // stage���� ������ �������� �� => �׷��� stage�� �´� �� ������Ʈ���� �ҷ�����
    m_stageName = _stageName;
    m_floorName = _floorName;
    LoadFromCSV();
}

void FloorBase::Reset()
{
}

void FloorBase::LoadFromCSV()
{
	std::wstring path = L"Asset/Csv/Stage/" + m_stageName + L"/" + m_floorName + L".csv";
	std::wifstream file(path);
	if (!file.is_open()) assert(false);

	std::wstring line;			// ������ ���ڿ�	

    // ������ ���� ������ ������ �ݺ�
    while (getline(file, line))
    {
        // �� ���� ������ ����
        if (line.empty()) break;
        objectCount++;
        std::wstringstream wss(line); // �� ���� �о wstringstream�� ����
        std::wstring token;
        std::wstring type;
        Actor* actor;
        Vector2 mapSize = Vector2(5200, 676);
        // ','�� �������� ���ڿ��� �и�
        {
            // ������Ʈ �̸�
            getline(wss, token, L',');
            type = token;
            actor = CreateObject<Actor>(type + L'-' + std::to_wstring(objectCount), LayerTag::Object, ObjectTag::Interactive);

            // ������Ʈ�� xy��ǥ
            getline(wss, token, L',');
            actor->transform->position.x = (float)std::stoi(token) - mapSize.x * 0.5f;
            getline(wss, token, L',');
            actor->transform->position.y = (float)std::stoi(token) - mapSize.y * 0.5f;

            // �θ� ����
            actor->transform->SetParent(gameObject->transform);
        }
        // ���⿡ type�� �°� ��ũ��Ʈ�� �߰�
        if (type == L"oldBook")  actor->AddComponent<OldBook>();
        if (type == L"s_lamp")  actor->AddComponent<S_lamp>();
        if (type == L"doll")  actor->AddComponent<Doll>();
        if (type == L"broom")  actor->AddComponent<Broom>();
        if (type == L"chair")  actor->AddComponent<Chair>();
        if (type == L"bed")  actor->AddComponent<Bed>();
        if (type == L"clock_big")  actor->AddComponent<Clock_big>();
        if (type == L"m_window01")  actor->AddComponent<M_window01>();
        if (type == L"statue")  actor->AddComponent<Statue>();
        if (type == L"mannequin")  actor->AddComponent<Mannequin>();
        if (type == L"mirror")  actor->AddComponent<Mirror_01>();
        if (type == L"TV")  actor->AddComponent<TV>();
        if (type == L"chandelier")  actor->AddComponent<Chandelier>();
        if (type == L"teaCup")  actor->AddComponent<TeaCup>();
        if (type == L"s_frame01")  actor->AddComponent<S_frame01>();
        if (type == L"pot")  actor->AddComponent<Pot>();
        if (type == L"bottle")  actor->AddComponent<Bottle>();
        if (type == L"candleLight")  actor->AddComponent<CandleLight>();
        // Todo : ���鋚���� �̸� �߰��ؼ� AddComponent
    }
}
