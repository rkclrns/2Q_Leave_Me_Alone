#include "IntroSceneText.h"

void IntroSceneText::Start()
{
	__super::Start();
	// 리소스 Add두번하면 안댐
	textComponent->SetFont(ResourceManager::AddFont(L"Galmuri11", L"Font/Galmuri11.ttf"));

	texts.push_back(L"송세환입니다. 나쁜 슬라임이 아니야! 소수를 버리고 다수를 구한다는 생각이, 잘못되었다고는 생각하지 않아. 빼앗겨본 적 없는 자가, 빼앗긴 자의 슬픔을 이해하는 것은 불가능해");
	texts.push_back(L"나는 슬라임 리무루. 나쁜 슬라임이 아니야! 소수를 버리고 다수를 구한다는 생각이, 잘못되었다고는 생각하지 않아. 빼앗겨본 적 없는 자가, 빼앗긴 자의 슬픔을 이해하는 것은 불가능해");
	texts.push_back(L"나는 슬라임 리무루. 나쁜 슬라임이 아니야! 소수를 버리고 다수를 구한다는 생각이, 잘못되었다고는 생각하지 않아. 빼앗겨본 적 없는 자가, 빼앗긴 자의 슬픔을 이해하는 것은 불가능해");
	texts.push_back(L"나는 슬라임 리무루. 나쁜 슬라임이 아니야! 소수를 버리고 다수를 구한다는 생각이, 잘못되었다고는 생각하지 않아. 빼앗겨본 적 없는 자가, 빼앗긴 자의 슬픔을 이해하는 것은 불가능해");

	textComponent->SetBox(Vector2(1000, 250));
	textComponent->SetSize(40.f);
	textComponent->SetColor(D2D1::ColorF(D2D1::ColorF::White));
	gameObject->transform->position = Vector2(0, 400);
	textComponent->SetAlignment(AlignmentType::Center);

	rect = gameObject->AddComponent<RectRenderer>();
	rect->size = Vector2(1000, 250);
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::DimGray));
	rect->SetLine(false);
	rect->alpha = 0.5f;
}

