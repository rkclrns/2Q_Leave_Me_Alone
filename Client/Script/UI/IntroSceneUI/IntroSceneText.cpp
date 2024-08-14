#include "IntroSceneText.h"

void IntroSceneText::Start()
{
	__super::Start();
	// ���ҽ� Add�ι��ϸ� �ȴ�
	textComponent->SetFont(ResourceManager::AddFont(L"Galmuri11", L"Font/Galmuri11.ttf"));

	texts.push_back(L"�ۼ�ȯ�Դϴ�. ���� �������� �ƴϾ�! �Ҽ��� ������ �ټ��� ���Ѵٴ� ������, �߸��Ǿ��ٰ�� �������� �ʾ�. ���Ѱܺ� �� ���� �ڰ�, ���ѱ� ���� ������ �����ϴ� ���� �Ұ�����");
	texts.push_back(L"���� ������ ������. ���� �������� �ƴϾ�! �Ҽ��� ������ �ټ��� ���Ѵٴ� ������, �߸��Ǿ��ٰ�� �������� �ʾ�. ���Ѱܺ� �� ���� �ڰ�, ���ѱ� ���� ������ �����ϴ� ���� �Ұ�����");
	texts.push_back(L"���� ������ ������. ���� �������� �ƴϾ�! �Ҽ��� ������ �ټ��� ���Ѵٴ� ������, �߸��Ǿ��ٰ�� �������� �ʾ�. ���Ѱܺ� �� ���� �ڰ�, ���ѱ� ���� ������ �����ϴ� ���� �Ұ�����");
	texts.push_back(L"���� ������ ������. ���� �������� �ƴϾ�! �Ҽ��� ������ �ټ��� ���Ѵٴ� ������, �߸��Ǿ��ٰ�� �������� �ʾ�. ���Ѱܺ� �� ���� �ڰ�, ���ѱ� ���� ������ �����ϴ� ���� �Ұ�����");

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

