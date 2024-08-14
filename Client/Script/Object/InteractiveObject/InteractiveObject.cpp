#include "InteractiveObject.h"

void InteractiveObject::Start()
{
	m_body = gameObject->AddComponent<BoxCollider2D>();
	m_hitRange = gameObject->AddComponent<BoxCollider2D>();
	m_rect = gameObject->AddComponent<RectRenderer>();
	m_text = gameObject->AddComponent<TextRenderer>();
	m_animator = gameObject->AddComponent<Animator2D>();
	
	m_rect->size = Vector2(100, 100);
	m_rect->alpha = 0.5f;

	m_text->SetText(gameObject->GetName());
	m_text->SetBox(Vector2(100, 50));
	m_text->renderOffset = Vector2(0, 0);
	m_text->SetAlignment(AlignmentType::Center);

	m_body->colliderTag = "Body";
	m_hitRange->colliderTag = "HitBox";
	m_hitRange->SetRenderInfo(D2D1::ColorF(D2D1::ColorF::Red));
	m_hitRange->SetState(GameState::Passive);

	LoadCSV();
}

void InteractiveObject::Update()
{
	m_text->SetText(gameObject->GetName() + std::to_wstring(m_animator->frameCount));
}

void InteractiveObject::LoadCSV()
{
	std::wstring name = gameObject->GetName();
	size_t pos = name.find(L'-');
	std::wstring temp = L"Asset/Csv/Object/" + name.substr(0, pos) + L".txt";
	std::wifstream file(temp);
	if (!file.is_open()) return;
	std::wstring line;
	std::wstring token;
	// 파일이 끝에 도달할 때까지 반복
	while (getline(file, line))
	{
		if (line.empty()) break;
		size_t pos = line.find(L':');
		if (pos != std::wstring::npos)
		{
			std::wstring key = line.substr(0, pos);
			std::wstring value = line.substr(pos + 1);
			if (key == L"cooltime")
			{
				m_maxCoolTime = (float)std::stoi(value);
			}
			else if (key == L"horror")
			{
				m_horrorPower = (float)std::stoi(value);
			}
			else if (key == L"bodyscale")
			{
				size_t cut = value.find(L',');
				m_body->size.x = (float)std::stoi(value.substr(0, cut));
				m_body->size.y = (float)std::stoi(value.substr(cut + 1));
			}
			else if (key == L"hitscale")
			{
				size_t cut = value.find(L',');
				m_hitRange->size.x = (float)std::stoi(value.substr(0, cut));
				m_hitRange->size.y = (float)std::stoi(value.substr(cut + 1));
			}
			else if (key == L"bodyoffset")
			{
				size_t cut = value.find(L',');
				m_body->offset.x = (float)std::stoi(value.substr(0, cut));
				m_body->offset.y = (float)std::stoi(value.substr(cut + 1));
			}
			else if (key == L"hitoffset")
			{
				size_t cut = value.find(L',');
				m_hitRange->offset.x = (float)std::stoi(value.substr(0, cut));
				m_hitRange->offset.y = (float)std::stoi(value.substr(cut + 1));
			}
			else if (key == L"fadetime")
			{
				m_fadeTime = (float)std::stoi(value);
			}
		}
	}
}
