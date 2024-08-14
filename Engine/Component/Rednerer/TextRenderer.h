#pragma once
#include "Renderer.h"
#include "Resource/Font.h"

class TextRenderer
	: public Renderer
{
public:
	TextRenderer();
	virtual ~TextRenderer();

	virtual void Initialize() final;
	virtual bool Draw(Camera2D* _camera) final;


	void SetSize(float _val);					// �ؽ�Ʈ ũ��
	void SetColor(D2D1_COLOR_F _color);			// �ؽ�Ʈ ����
	void SetBold(BoldType _boldtype);			// �ؽ�Ʈ ����
	void SetText(const wchar_t* _text);			// ����� �ؽ�Ʈ
	void SetText(std::wstring _text);			// 22
	void AddText(std::wstring _text);			// �ؽ�Ʈ �߰�
	void AddText(wchar_t _text);				// �ؽ�Ʈ �߰�
	void SetFont(Resource::Font* _font);		// ��Ʈ
	void SetBox(Vector2 _size);					// �ؽ�Ʈ�ڽ�
	void SetAlignment(AlignmentType _type);

	void SetSizeToRange(float _val, UINT32 _start, UINT32 _range = -1);				// ���ۺ��� Ư�� ������ŭ�� ����� �ٲ�
	void SetColorToRange(D2D1_COLOR_F _color, UINT32 _start, UINT32 _range = -1);   // ���ۺ��� Ư�� ������ŭ�� �÷� �ٲ�
	void SetBoldToRange(BoldType _boldtype, UINT32 _start, UINT32 _range = -1);     // 

	std::wstring GetText() { return m_text; }
	Resource::Font* GetFont() { return m_font; }

private:

	std::wstring m_text;                 // ������ �ؽ�Ʈ
	Resource::Font* m_font;              // ��Ʈ
	float m_textSize;                    // �۾� ũ��
	D2D1_COLOR_F m_textColor;            // �۾� ��
	DWRITE_FONT_WEIGHT m_textBoldSize;   // �۾� ����
	DWRITE_TEXT_ALIGNMENT m_textAlignment; // �۾� ����

	IDWriteTextLayout* m_textLayout;

	void UpdateTextLayout();

};

