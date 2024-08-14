#pragma once
#include "Renderer.h"

class CircleRenderer
	: public Renderer
{
public:

	CircleRenderer();
	virtual ~CircleRenderer();

	virtual bool Draw(Camera2D* _camera) final;

	void SetLineColor(D2D1_COLOR_F _color);
	void SetFillColor(D2D1_COLOR_F _color);
	void SetLine(bool _val);
	void SetFill(bool _val);

	float lineWidth;  // �ܰ��� �β�
	float radius;

private:

	D2D1_COLOR_F m_linecolor; // ��
	D2D1_COLOR_F m_fillcolor; // ä���
	bool isFill;			  // ä��� ����	
	bool isLine;			  // �ܰ��� ����
};
