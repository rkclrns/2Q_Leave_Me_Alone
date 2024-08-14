#include "pch.h"
#include "SpriteRenderer2D.h"
#include "../../Resource/Sprite2D.h"
#include "../Camera2D.h"
#include "../Transform2D.h"
#include "../../Resource/Manager/ResourceManager.h"
#include "World/Layer/Layer.h"
#include "../../Render/D2DRender.h"

SpriteRenderer2D::SpriteRenderer2D()
	: m_sprite(nullptr)
{
	m_type = ComponentType::SpriteRenderer2D;
}

SpriteRenderer2D::~SpriteRenderer2D()
{
}

bool SpriteRenderer2D::Draw(Camera2D* _camera)
{
	if (!m_sprite) return false;

	ID2D1BitmapRenderTarget* renderTarget = nullptr;

	if (_camera->GetLayerRenderProperty(_camera->GetRenderProcess()) == Layer::Blending) 
		renderTarget = _camera->GetBlendingRenderTarget();
	else 
		renderTarget = _camera->GetBitmapRenderTarget();

	renderTarget->SetTransform(CalCulateMatrix(_camera));

	D2D1_RECT_F dstRect = D2D1::RectF(
		renderOffset.x, renderOffset.y,
		renderOffset.x + size.x,
		renderOffset.y + size.y);

	renderTarget->DrawBitmap(m_sprite->GetSprite(index), dstRect, alpha);

	if (Debug::Active())
	{
		ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
		D2D1_COLOR_F oldColor = brush->GetColor(); // 기존 색상 저장
		float oldAlpha = brush->GetOpacity(); // 기존 색상 저장

		// 외곽선 출력
		brush->SetColor(D2D1::ColorF(D2D1::ColorF::Red));
		brush->SetOpacity(0.5f);
		renderTarget->DrawRectangle(dstRect, brush, 0.5f);
		// 중심점 출력
		renderTarget->DrawLine(
			D2D1::Point2F(dstRect.left, center.y),
			D2D1::Point2F(dstRect.right, center.y), brush);
		renderTarget->DrawLine(
			D2D1::Point2F(center.x, dstRect.top),
			D2D1::Point2F(center.x, dstRect.bottom), brush);

		brush->SetColor(oldColor); // 기존 색상 돌려놓기
		brush->SetOpacity(oldAlpha);
	}

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	return true;
}

void SpriteRenderer2D::SetSprite(std::wstring _key)
{
	SetSprite(ResourceManager::GetSprite2D(_key));
}
void SpriteRenderer2D::SetSprite(std::wstring _key, int _index)
{
	SetSprite(ResourceManager::GetSprite2D(_key), _index);
}
void SpriteRenderer2D::SetSprite(Resource::Sprite2D* _sprite)
{
	m_sprite = _sprite;
	size.x = m_sprite->GetSprite(index)->GetSize().width;
	size.y = m_sprite->GetSprite(index)->GetSize().height;
}

void SpriteRenderer2D::SetSprite(Resource::Sprite2D* _sprite, int _index)
{
	m_sprite = _sprite;
	index = _index;
	size.x = m_sprite->GetSprite(index)->GetSize().width;
	size.y = m_sprite->GetSprite(index)->GetSize().height;
}
