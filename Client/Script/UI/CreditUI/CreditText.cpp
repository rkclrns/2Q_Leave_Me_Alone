#include "CreditText.h"

void CreditText::Start()
{
	__super::Start();

	// ���ҽ� Add�ι��ϸ� �ȴ�
	textComponent->SetFont(ResourceManager::AddFont(L"Galmuri11", L"Font/Galmuri11.ttf"));

	texts.push_back(L"�����ϴ��� �ٵ� ��� ���ҳ׿� �X��X�� ����� ���� �� ��¼����¼���� �� �˰� ��̳��� ? ������ũ���� ����� ���ڷ��̶��ϴ�. (����) �����ϴ��� �ٵ� ��� ���ҳ׿� �X��X�� ����� ���� �� ��¼����¼���� �� �˰� ��̳��� ? ������ũ���� ����� ���ڷ��̶��ϴ�. (����) �����ϴ��� �ٵ� ��� ���ҳ׿� �X��X�� ����� ���� �� ��¼����¼���� �� �˰� ��̳��� ? ������ũ���� ����� ���ڷ��̶��ϴ�. (����) �����ϴ��� �ٵ� ��� ���ҳ׿� �X��X�� ����� ���� �� ��¼����¼���� �� �˰� ��̳��� ? ������ũ���� ����� ���ڷ��̶��ϴ�. (����) �����ϴ��� �ٵ� ��� ���ҳ׿� �X��X�� ����� ���� �� ��¼����¼���� �� �˰� ��̳��� ? ������ũ���� ����� ���ڷ��̶��ϴ�. (����) �����ϴ��� �ٵ� ��� ���ҳ׿� �X��X�� ����� ���� �� ��¼����¼���� �� �˰� ��̳��� ? ������ũ���� ����� ���ڷ��̶��ϴ�. (����)");

	textComponent->SetBox(Vector2(708, 918));
	textComponent->SetSize(30.f);
	textComponent->SetColor(D2D1::ColorF(D2D1::ColorF::White));

	textComponent->SetAlignment(AlignmentType::Center);

	rect = gameObject->AddComponent<RectRenderer>();
	rect->size = textComponent->size;
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::DimGray));
	rect->SetLine(false);
	rect->alpha = 0.5f;

}

void CreditText::Update()
{
	__super::Update();

	m_scrollTimer = 0.5f;

	if (InputManager::KeyIsHold(Key::SPACEBAR))
		m_scrollTimer = 5.0f;

	gameObject->transform->position.y -= 0.3f * m_scrollTimer;
}

