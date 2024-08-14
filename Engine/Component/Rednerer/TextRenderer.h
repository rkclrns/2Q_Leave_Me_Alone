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


	void SetSize(float _val);					// 텍스트 크기
	void SetColor(D2D1_COLOR_F _color);			// 텍스트 색깔
	void SetBold(BoldType _boldtype);			// 텍스트 굵기
	void SetText(const wchar_t* _text);			// 출력할 텍스트
	void SetText(std::wstring _text);			// 22
	void AddText(std::wstring _text);			// 텍스트 추가
	void AddText(wchar_t _text);				// 텍스트 추가
	void SetFont(Resource::Font* _font);		// 폰트
	void SetBox(Vector2 _size);					// 텍스트박스
	void SetAlignment(AlignmentType _type);

	void SetSizeToRange(float _val, UINT32 _start, UINT32 _range = -1);				// 시작부터 특정 범위만큼만 사이즈를 바꿈
	void SetColorToRange(D2D1_COLOR_F _color, UINT32 _start, UINT32 _range = -1);   // 시작부터 특정 범위만큼만 컬러 바꿈
	void SetBoldToRange(BoldType _boldtype, UINT32 _start, UINT32 _range = -1);     // 

	std::wstring GetText() { return m_text; }
	Resource::Font* GetFont() { return m_font; }

private:

	std::wstring m_text;                 // 츨력할 텍스트
	Resource::Font* m_font;              // 폰트
	float m_textSize;                    // 글씨 크기
	D2D1_COLOR_F m_textColor;            // 글씨 색
	DWRITE_FONT_WEIGHT m_textBoldSize;   // 글씨 굵기
	DWRITE_TEXT_ALIGNMENT m_textAlignment; // 글씨 정렬

	IDWriteTextLayout* m_textLayout;

	void UpdateTextLayout();

};

