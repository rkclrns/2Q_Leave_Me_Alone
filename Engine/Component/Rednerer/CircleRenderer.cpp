#include "pch.h"
#include "CircleRenderer.h"
#include "World/Layer/Layer.h"
#include "../../Render/D2DRender.h"
#include "../Camera2D.h"
#include "../Transform2D.h"


CircleRenderer::CircleRenderer()
	: isFill(true),
	isLine(true),
	lineWidth(1.f),
	m_fillcolor(D2D1::ColorF(D2D1::ColorF::White)),
	m_linecolor(D2D1::ColorF(D2D1::ColorF::Black))
{
	m_type = ComponentType::CircleRenderer;
}

CircleRenderer::~CircleRenderer()
{
}

bool CircleRenderer::Draw(Camera2D* _camera)
{
	ID2D1BitmapRenderTarget* renderTarget = nullptr;

	if (_camera->GetLayerRenderProperty(_camera->GetRenderProcess()) == Layer::Blending)
		renderTarget = _camera->GetBlendingRenderTarget();
	else
		renderTarget = _camera->GetBitmapRenderTarget();

	ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
	D2D1_COLOR_F oldColor = brush->GetColor(); // 기존 색상 저장
	float oldAlpha = brush->GetOpacity(); // 기존 색상 저장
	brush->SetOpacity(alpha);

	renderTarget->SetTransform(CalCulateMatrix(_camera));
	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(renderOffset.x, renderOffset.y), radius, radius);
	
	if (isFill)
	{
		brush->SetColor(m_fillcolor);
		renderTarget->FillEllipse(&ellipse, brush);
	}

	if (isLine)
	{
		brush->SetColor(m_linecolor);
		renderTarget->DrawEllipse(ellipse, brush, lineWidth);
	}

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	return true;
}

void CircleRenderer::SetLineColor(D2D1_COLOR_F _color)
{
	m_linecolor = _color;
}

void CircleRenderer::SetFillColor(D2D1_COLOR_F _color)
{
	m_fillcolor = _color;
}

void CircleRenderer::SetLine(bool _val)
{
	isLine = _val;
}

void CircleRenderer::SetFill(bool _val)
{
	isFill = _val;
}
