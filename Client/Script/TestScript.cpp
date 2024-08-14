#include "ScriptHeaders.h"

void TestScript::Start()
{
	gameObject->transform->position = Vector2(100, 100);

	rect = gameObject->AddComponent<RectRenderer>();
	sprite = gameObject->AddComponent<SpriteRenderer2D>();
	button = gameObject->AddComponent<Button>();

	rect->size = Vector2(100, 100);
	button->SetSize(rect->size);
}

void TestScript::Update()
{
}

void TestScript::Fixedupdate()
{
}

void TestScript::OnEnable()
{
}

void TestScript::OnDisable()
{
}

void TestScript::OnDestroy()
{
}

void TestScript::OnCollisionEnter(Actor* _collision)
{
}

void TestScript::OnCollisionStay(Actor* _collision)
{
}

void TestScript::OnCollisionExit(Actor* _collision)
{
}

void TestScript::OnMouseEnter()
{
	Debug::Log("Button Enter!");
}

void TestScript::OnMouseStay()
{
	Debug::Log("Button Stay!");
}

void TestScript::OnMouseExit()
{
	Debug::Log("Button Exit!");
}
